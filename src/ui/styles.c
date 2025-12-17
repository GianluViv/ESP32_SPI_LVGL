#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "ui.h"
#include "screens.h"

//
// Style: panel
//

void init_style_panel_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_pad_top(style, 0);
    lv_style_set_pad_bottom(style, 0);
    lv_style_set_pad_left(style, 0);
    lv_style_set_pad_right(style, 0);
    lv_style_set_border_color(style, lv_color_hex(0xffd4af37));
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][13]));
};

lv_style_t *get_style_panel_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_panel_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_panel(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_panel_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_panel(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_panel_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: page
//

void init_style_page_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][12]));
};

lv_style_t *get_style_page_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_page_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_page(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_page_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_page(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_page_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: arc
//

void init_style_arc_KNOB_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_opa(style, 0);
};

lv_style_t *get_style_arc_KNOB_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_arc_KNOB_DEFAULT(style);
    }
    return style;
};

void init_style_arc_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_arc_opa(style, 0);
};

lv_style_t *get_style_arc_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_arc_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_arc_INDICATOR_DEFAULT(lv_style_t *style) {
    lv_style_set_arc_opa(style, 0);
};

lv_style_t *get_style_arc_INDICATOR_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_arc_INDICATOR_DEFAULT(style);
    }
    return style;
};

void add_style_arc(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_arc_KNOB_DEFAULT(), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_arc_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_arc_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
};

void remove_style_arc(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_arc_KNOB_DEFAULT(), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_arc_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_arc_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
};

//
// Style: led
//

void init_style_led_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_clip_corner(style, false);
    lv_style_set_shadow_spread(style, 2);
};

lv_style_t *get_style_led_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_led_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_led(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_led_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_led(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_led_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: switch
//

void init_style_switch_KNOB_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xff000000));
    lv_style_set_bg_color(style, lv_color_hex(0xffd4af37));
};

lv_style_t *get_style_switch_KNOB_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_switch_KNOB_DEFAULT(style);
    }
    return style;
};

void init_style_switch_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_border_color(style, lv_color_hex(0xffd4af37));
    lv_style_set_border_width(style, 2);
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][14]));
};

lv_style_t *get_style_switch_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_switch_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_switch_MAIN_CHECKED(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff4ade80));
};

lv_style_t *get_style_switch_MAIN_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_switch_MAIN_CHECKED(style);
    }
    return style;
};

void add_style_switch(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_switch_KNOB_DEFAULT(), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_switch_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_switch_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
};

void remove_style_switch(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_switch_KNOB_DEFAULT(), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_switch_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_switch_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
};

//
// Style: txt_blk
//

void add_style_txt_blk(lv_obj_t *obj) {
    (void)obj;
};

void remove_style_txt_blk(lv_obj_t *obj) {
    (void)obj;
};

//
// Style: label
//

void init_style_label_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_align(style, LV_ALIGN_CENTER);
    lv_style_set_text_color(style, lv_color_hex(0xffffffff));
    lv_style_set_text_font(style, &lv_font_montserrat_20);
};

lv_style_t *get_style_label_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_label_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_label(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_label_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_label(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_label_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_panel,
        add_style_page,
        add_style_arc,
        add_style_led,
        add_style_switch,
        add_style_txt_blk,
        add_style_label,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_panel,
        remove_style_page,
        remove_style_arc,
        remove_style_led,
        remove_style_switch,
        remove_style_txt_blk,
        remove_style_label,
    };
    remove_style_funcs[styleIndex](obj);
}

