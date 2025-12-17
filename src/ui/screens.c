#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

void create_screen_home() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.home = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    add_style_page(obj);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(95), LV_PCT(95));
            add_style_panel(obj);
            lv_obj_set_style_radius(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffd4af37), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_label(obj);
                    lv_label_set_text(obj, "HELLO WORLD!!!");
                }
            }
        }
    }
    
    tick_screen_home();
}

void tick_screen_home() {
}

void change_color_theme(uint32_t theme_index) {
    active_theme_index = theme_index;
    
    lv_style_set_bg_color(get_style_panel_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][13]));
    
    lv_style_set_bg_color(get_style_page_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][12]));
    
    lv_style_set_bg_color(get_style_switch_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][14]));
    
    lv_obj_invalidate(objects.home);
}

uint32_t theme_colors[2][15] = {
    { 0xff273c4e, 0xff919191, 0xff000000, 0xff007fc4, 0xff00c800, 0xff808080, 0xffffffff, 0xffff9600, 0xff000000, 0xff202d39, 0xffffffff, 0xff202d39, 0xff000000, 0xff35575f, 0xff507f8b },
    { 0xffffffff, 0xffd1d1d1, 0xff000000, 0xff0080c9, 0xff00c800, 0xff808080, 0xffffffff, 0xffff9600, 0xff000000, 0xffd9d9d9, 0xff000000, 0xff4a6278, 0xff1c320c, 0xff427425, 0xff000000 },
};


typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_home,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_home();
}
