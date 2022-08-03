// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: LEDCUBELCD

#include "ui.h"

#include <Arduino.h>

#include "core/Config.h"
#include "space/Animation.h"
#include "ui_helpers.h"

///////////////////// PROTOTYPES ///////////////////
lv_obj_t* ui_create_screen();
void ui_create_listed_icon(lv_obj_t* screen, uint32_t id, uint16_t x,
                           uint16_t y, lv_event_cb_t event);
void ui_create_icon(lv_obj_t* screen, uint32_t id, uint16_t x, uint16_t y,
                    lv_event_cb_t event, const lv_img_dsc_t* image,
                    const char* text);
void ui_event(lv_event_t* e);
///////////////////// VARIABLES ////////////////////
lv_obj_t* ui_animation_screens[4];
lv_obj_t* ui_configuration_screens[14];
lv_obj_t* ui_settings_screen;

void ui_init(void) {
  lv_disp_t* dispp = lv_disp_get_default();
  lv_theme_t* theme = lv_theme_basic_init(dispp);
  lv_disp_set_theme(dispp, theme);

  lv_obj_t* screen = ui_create_screen();
  ui_animation_screens[0] = screen;
  ui_create_icon(screen, 200, 5, 4, ui_event, &ui_img_settings_80_png,
                 "Play all");
  ui_create_listed_icon(screen, 0, 110, 4, ui_event);
  ui_create_listed_icon(screen, 1, 215, 4, ui_event);
  ui_create_listed_icon(screen, 2, 5, 122, ui_event);
  ui_create_listed_icon(screen, 3, 110, 122, ui_event);
  ui_create_icon(screen, 101, 215, 122, ui_event, &ui_img_next_80_png,
                 "Next page");

  screen = ui_create_screen();
  ui_animation_screens[1] = screen;
  ui_create_listed_icon(screen, 4, 5, 4, ui_event);
  ui_create_listed_icon(screen, 5, 110, 4, ui_event);
  ui_create_listed_icon(screen, 6, 215, 4, ui_event);
  ui_create_listed_icon(screen, 7, 5, 122, ui_event);
  ui_create_listed_icon(screen, 8, 110, 122, ui_event);
  ui_create_icon(screen, 102, 215, 122, ui_event, &ui_img_next_80_png,
                 "Next page");

  screen = ui_create_screen();
  ui_animation_screens[2] = screen;
  ui_create_listed_icon(screen, 9, 5, 4, ui_event);
  ui_create_listed_icon(screen, 10, 110, 4, ui_event);
  ui_create_listed_icon(screen, 11, 215, 4, ui_event);
  ui_create_listed_icon(screen, 12, 5, 122, ui_event);
  ui_create_listed_icon(screen, 13, 110, 122, ui_event);
  ui_create_icon(screen, 103, 215, 122, ui_event, &ui_img_next_80_png,
                 "Next page");

  screen = ui_create_screen();
  ui_animation_screens[3] = screen;
  ui_create_listed_icon(screen, 14, 5, 4, ui_event);
  ui_create_icon(screen, 100, 215, 122, ui_event, &ui_img_next_80_png,
                 "Next page");

  lv_disp_load_scr(ui_animation_screens[0]);
}

void ui_create_listed_icon(lv_obj_t* screen, uint32_t id, uint16_t x,
                           uint16_t y, lv_event_cb_t event) {
  // This must match with ID from jump_item_t
  const lv_img_dsc_t* images[] = {
      &ui_img_accelerometer_80_png, &ui_img_arrows_80_png,
      &ui_img_atoms_80_png,         &ui_img_fireworks_80_png,
      &ui_img_helix_80_png,         &ui_img_life_80_png,
      &ui_img_mario_80_png,         &ui_img_plasma_80_png,
      &ui_img_pong_80_png,          &ui_img_scroller_80_png,
      &ui_img_sinus_80_png,         &ui_img_spectrum_80_png,
      &ui_img_starfield_80_png,     &ui_img_twinkels1_80_png,
      &ui_img_twinkels2_80_png};
  const lv_img_dsc_t* image = images[id];
  const char* text = Animation::get_item(id).name;
  ui_create_icon(screen, id, x, y, event, image, text);
}

void ui_event(lv_event_t* e) {
  lv_event_code_t event = lv_event_get_code(e);
  uint32_t id = (uint32_t)lv_event_get_user_data(e);
  if (event == LV_EVENT_CLICKED) {
    if (id < 100) {
      config.animation.changed = true;
      config.animation.play_one = true;
      config.animation.animation = id;
    } else if (id < 200) {
      _ui_screen_change(ui_animation_screens[id - 100],
                        LV_SCR_LOAD_ANIM_MOVE_LEFT, 1000, 0);
    } else if (id < 300) {
      config.animation.changed = true;
      config.animation.play_one = false;
    }
  }
  if (event == LV_EVENT_LONG_PRESSED) {
    if (id < 100) {
      //_ui_screen_change(ui_configuration_screens[id],
      // LV_SCR_LOAD_ANIM_FADE_ON,
      //                  1000, 0);
    } else if (id < 200) {
    } else if (id < 300) {
      //_ui_screen_change(ui_settings_screen, LV_SCR_LOAD_ANIM_FADE_ON, 1000,
      //0);
    }
  }
}

lv_obj_t* ui_create_screen() {
  lv_obj_t* screen = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(screen, lv_color_hex(0x000000),
                            LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(screen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  return screen;
}

void ui_create_icon(lv_obj_t* screen, uint32_t id, uint16_t x, uint16_t y,
                    lv_event_cb_t event, const lv_img_dsc_t* image,
                    const char* text) {
  lv_obj_t* panel = lv_obj_create(screen);
  lv_obj_set_width(panel, 100);
  lv_obj_set_height(panel, 114);
  lv_obj_set_x(panel, x);
  lv_obj_set_y(panel, y);
  lv_obj_clear_flag(panel, LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_set_style_bg_color(panel, lv_color_hex(0x000000),
                            LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t* button = lv_btn_create(panel);
  lv_obj_set_width(button, 80);
  lv_obj_set_height(button, 80);
  lv_obj_set_x(button, 0);
  lv_obj_set_y(button, 6);
  lv_obj_set_align(button, LV_ALIGN_TOP_MID);
  // The pointer IS the value to enable casting "id" needs to be sizeof(void*)
  // This hack enables freeing the memory for "id". No need to keep in global
  lv_obj_add_event_cb(button, event, LV_EVENT_ALL, (void*)id);
  lv_obj_set_style_radius(button, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(button, lv_color_hex(0x000000),
                            LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_clip_corner(button, true, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_img_src(button, image, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_img_opa(button, 100, LV_PART_MAIN | LV_STATE_PRESSED);
  lv_obj_set_style_shadow_color(button, lv_color_hex(0xFFFFFF),
                                LV_PART_MAIN | LV_STATE_PRESSED);
  lv_obj_set_style_shadow_opa(button, 255, LV_PART_MAIN | LV_STATE_PRESSED);
  lv_obj_set_style_shadow_width(button, 20, LV_PART_MAIN | LV_STATE_PRESSED);
  lv_obj_set_style_shadow_spread(button, 3, LV_PART_MAIN | LV_STATE_PRESSED);

  lv_obj_t* label = lv_label_create(panel);
  lv_obj_set_width(label, 100);
  lv_obj_set_height(label, 20);
  lv_obj_set_x(label, 0);
  lv_obj_set_y(label, 0);
  lv_obj_set_align(label, LV_ALIGN_BOTTOM_MID);
  lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
  lv_label_set_text(label, text);
  lv_obj_set_style_text_color(label, lv_color_hex(0xFFFFFF),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER,
                              LV_PART_MAIN | LV_STATE_DEFAULT);
}
