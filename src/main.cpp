#include <Arduino.h>
#include "lvgl_manager.h"
#include <esp_system.h>

// test SSH

void setup() {
  Serial.begin(115200);
  delay(1000);  // Attesa per stabilizzare la seriale

  // Mostra il motivo dell'ultimo riavvio
  esp_reset_reason_t reason = esp_reset_reason();
  Serial.print("Reset reason: ");
  switch (reason) {
    case ESP_RST_POWERON: Serial.println("Power-on reset"); break;
    case ESP_RST_EXT: Serial.println("External reset"); break;
    case ESP_RST_SW: Serial.println("Software reset"); break;
    case ESP_RST_PANIC: Serial.println("Panic/Exception reset"); break;
    case ESP_RST_INT_WDT: Serial.println("Interrupt watchdog reset"); break;
    case ESP_RST_TASK_WDT: Serial.println("Task watchdog reset"); break;
    case ESP_RST_WDT: Serial.println("Other watchdog reset"); break;
    case ESP_RST_DEEPSLEEP: Serial.println("Deep sleep reset"); break;
    case ESP_RST_BROWNOUT: Serial.println("Brownout reset"); break;
    case ESP_RST_SDIO: Serial.println("SDIO reset"); break;
    default: Serial.println("Unknown reset"); break;
    }

  // Inizializza il manager LVGL (display, touchscreen, UI)
  lvgl_manager_init();

  // Avvia il task FreeRTOS per l'aggiornamento della grafica
  lvgl_manager_start_task();
  }

void loop() {
  // Il loop principale è libero per altre operazioni
  // La grafica LVGL viene gestita dal task dedicato

  // Esempio di come modificare la grafica in modo thread-safe:
  // if (lvgl_lock(100)) {  // Timeout di 100ms
  //     // Modifica elementi LVGL qui
  //     lvgl_unlock();
  // }

  // Oppure usando la macro:
  LV_SAFE({
    //     // Modifica elementi LVGL qui
    }, 100);

  delay(100);  // Piccolo delay per non sovraccaricare la CPU
  }