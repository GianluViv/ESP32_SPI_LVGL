#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: panel
lv_style_t *get_style_panel_MAIN_DEFAULT();
void add_style_panel(lv_obj_t *obj);
void remove_style_panel(lv_obj_t *obj);

// Style: page
lv_style_t *get_style_page_MAIN_DEFAULT();
void add_style_page(lv_obj_t *obj);
void remove_style_page(lv_obj_t *obj);

// Style: arc
lv_style_t *get_style_arc_KNOB_DEFAULT();
lv_style_t *get_style_arc_MAIN_DEFAULT();
lv_style_t *get_style_arc_INDICATOR_DEFAULT();
void add_style_arc(lv_obj_t *obj);
void remove_style_arc(lv_obj_t *obj);

// Style: led
lv_style_t *get_style_led_MAIN_DEFAULT();
void add_style_led(lv_obj_t *obj);
void remove_style_led(lv_obj_t *obj);

// Style: switch
lv_style_t *get_style_switch_KNOB_DEFAULT();
lv_style_t *get_style_switch_MAIN_DEFAULT();
lv_style_t *get_style_switch_MAIN_CHECKED();
void add_style_switch(lv_obj_t *obj);
void remove_style_switch(lv_obj_t *obj);

// Style: txt_blk
void add_style_txt_blk(lv_obj_t *obj);
void remove_style_txt_blk(lv_obj_t *obj);

// Style: label
lv_style_t *get_style_label_MAIN_DEFAULT();
void add_style_label(lv_obj_t *obj);
void remove_style_label(lv_obj_t *obj);



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/