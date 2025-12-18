#include "lvgl_manager.h"
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
#include "ui/ui.h"

// ============================================================================
// Configurazione Touchscreen
// ============================================================================
#define XPT2046_IRQ 36   // T_IRQ
#define XPT2046_MOSI 32  // T_DIN
#define XPT2046_MISO 39  // T_OUT
#define XPT2046_CLK 25   // T_CLK
#define XPT2046_CS 33    // T_CS

// ============================================================================
// Configurazione Display
// ============================================================================
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320
#define DRAW_BUF_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT / 10 * (LV_COLOR_DEPTH / 8))

// ============================================================================
// Configurazione Task LVGL
// ============================================================================
#define LVGL_TASK_STACK_SIZE 8192  // Aumentato per evitare stack overflow
#define LVGL_TASK_PRIORITY 5
#define LVGL_TASK_CORE 1
#define LVGL_TICK_PERIOD_MS 5

// ============================================================================
// Variabili statiche
// ============================================================================
static SPIClass touchscreenSPI = SPIClass(VSPI);
static XPT2046_Touchscreen touchscreen(XPT2046_CS, XPT2046_IRQ);
static uint32_t draw_buf[DRAW_BUF_SIZE / 4];

// Mutex per proteggere le operazioni LVGL
static SemaphoreHandle_t lvgl_mutex = NULL;

// Task handle
static TaskHandle_t lvgl_task_handle = NULL;

// Coordinate touchscreen
static int touch_x, touch_y, touch_z;

// ============================================================================
// Funzioni private
// ============================================================================

/**
 * @brief Callback per il logging di LVGL
 */
static void log_print(lv_log_level_t level, const char* buf) {
    LV_UNUSED(level);
    Serial.println(buf);
    Serial.flush();
    }

/**
 * @brief Callback per la lettura del touchscreen
 */
static void touchscreen_read(lv_indev_t* indev, lv_indev_data_t* data) {
    if (touchscreen.tirqTouched() && touchscreen.touched()) {
        TS_Point p = touchscreen.getPoint();

        // Calibrazione dei punti del touchscreen
        touch_x = map(p.x, 200, 3700, 1, SCREEN_WIDTH);
        touch_y = map(p.y, 240, 3800, 1, SCREEN_HEIGHT);
        touch_z = p.z;

        data->state = LV_INDEV_STATE_PRESSED;
        data->point.x = touch_x;
        data->point.y = touch_y;
        } else {
        data->state = LV_INDEV_STATE_RELEASED;
        }
    }

/**
 * @brief Task FreeRTOS per l'aggiornamento della grafica LVGL
 */
static void lvgl_task(void* pvParameters) {
    (void)pvParameters;

    TickType_t last_wake_time = xTaskGetTickCount();

    while (true) {
        // Acquisisce il mutex prima di aggiornare LVGL
        if (xSemaphoreTake(lvgl_mutex, portMAX_DELAY) == pdTRUE) {
            lv_tick_inc(LVGL_TICK_PERIOD_MS);  // Aggiorna il tick di LVGL
            lv_task_handler();  // Gestisce la GUI
            ui_tick();          // Aggiorna la UI
            xSemaphoreGive(lvgl_mutex);
            }

        // Attende fino al prossimo ciclo
        vTaskDelayUntil(&last_wake_time, pdMS_TO_TICKS(LVGL_TICK_PERIOD_MS));
        }
    }

// ============================================================================
// Funzioni pubbliche
// ============================================================================

void lvgl_manager_init(void) {
    String LVGL_Arduino = String("LVGL Library Version: ") +
        lv_version_major() + "." +
        lv_version_minor() + "." +
        lv_version_patch();
    Serial.println(LVGL_Arduino);

    // Crea il mutex per LVGL
    lvgl_mutex = xSemaphoreCreateMutex();
    if (lvgl_mutex == NULL) {
        Serial.println("Errore: impossibile creare il mutex LVGL!");
        return;
        }

    // Inizializza LVGL
    lv_init();

    // Registra la funzione di log per il debug
    lv_log_register_print_cb(log_print);

    // Inizializza SPI per il touchscreen
    touchscreenSPI.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
    touchscreen.begin(touchscreenSPI);
    touchscreen.setRotation(2);

    // Crea l'oggetto display
    lv_display_t* disp = lv_tft_espi_create(SCREEN_WIDTH, SCREEN_HEIGHT, draw_buf, sizeof(draw_buf));
    lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_270);

    // Inizializza il dispositivo di input (touchscreen)
    lv_indev_t* indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(indev, touchscreen_read);

    // Inizializza la UI di EEZ Studio
    ui_init();

    Serial.println("LVGL Manager inizializzato con successo");
    }

void lvgl_manager_start_task(void) {
    if (lvgl_mutex == NULL) {
        Serial.println("Errore: LVGL Manager non inizializzato!");
        return;
        }

    // Crea il task LVGL su un core specifico
    BaseType_t result = xTaskCreatePinnedToCore(
        lvgl_task,              // Funzione del task
        "LVGL_Task",            // Nome del task
        LVGL_TASK_STACK_SIZE,   // Dimensione dello stack
        NULL,                   // Parametri
        LVGL_TASK_PRIORITY,     // Priorità
        &lvgl_task_handle,      // Handle del task
        LVGL_TASK_CORE          // Core su cui eseguire
    );

    if (result == pdPASS) {
        Serial.println("Task LVGL avviato con successo");
        } else {
        Serial.println("Errore: impossibile creare il task LVGL!");
        }
    }

bool lvgl_lock(uint32_t timeout_ms) {
    if (lvgl_mutex == NULL) {
        return false;
        }

    TickType_t timeout_ticks = (timeout_ms == 0) ? portMAX_DELAY : pdMS_TO_TICKS(timeout_ms);
    return xSemaphoreTake(lvgl_mutex, timeout_ticks) == pdTRUE;
    }

void lvgl_unlock(void) {
    if (lvgl_mutex != NULL) {
        xSemaphoreGive(lvgl_mutex);
        }
    }
