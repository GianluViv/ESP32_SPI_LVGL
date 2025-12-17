#include <Arduino.h>
#include "lvgl_manager.h"

// test memorizzazione token

void setup() {
  Serial.begin(115200);

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