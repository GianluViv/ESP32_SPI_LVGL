#ifndef LVGL_MANAGER_H
#define LVGL_MANAGER_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * @brief Inizializza LVGL, il display e il touchscreen
     */
    void lvgl_manager_init(void);

    /**
     * @brief Avvia il task FreeRTOS per l'aggiornamento della grafica LVGL
     */
    void lvgl_manager_start_task(void);

    /**
     * @brief Acquisisce il mutex per proteggere le operazioni LVGL
     * @param timeout_ms Timeout in millisecondi (0 = attesa infinita)
     * @return true se il mutex è stato acquisito, false altrimenti
     */
    bool lvgl_lock(uint32_t timeout_ms);

    /**
     * @brief Rilascia il mutex LVGL
     */
    void lvgl_unlock(void);

    /**
     * @brief Macro per eseguire codice LVGL in modo thread-safe
     * @param code Codice da eseguire
     * @param timeout_ms Timeout in millisecondi
     */
#define LV_SAFE(code, timeout_ms) \
    do { \
        if (lvgl_lock(timeout_ms)) { \
            code; \
            lvgl_unlock(); \
        } \
    } while(0)

#ifdef __cplusplus
    }
#endif

#endif // LVGL_MANAGER_H
