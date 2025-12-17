#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *home;
    lv_obj_t *obj0;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_HOME = 1,
};

void create_screen_home();
void tick_screen_home();

enum Themes {
    THEME_ID_DARK,
    THEME_ID_LIGHT,
};
enum Colors {
    COLOR_ID_PAGE_BACKG,
    COLOR_ID_PANEL_BACKG,
    COLOR_ID_LABEL_COLOR,
    COLOR_ID_VALSIR,
    COLOR_ID_ACCENT,
    COLOR_ID_ARC_COLOR,
    COLOR_ID_VALSIR_W,
    COLOR_ID_ORANGE,
    COLOR_ID_BLACK,
    COLOR_ID_PANEL_BACKG_DARK,
    COLOR_ID_BW,
    COLOR_ID_PANEL_DARK,
    COLOR_ID_GREEN,
    COLOR_ID_GREEN_L,
    COLOR_ID_PANEL_BG,
};
void change_color_theme(uint32_t themeIndex);
extern uint32_t theme_colors[2][15];
extern uint32_t active_theme_index;

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/