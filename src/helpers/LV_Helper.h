/**


	protected $casts = [

	];
 * @file      LV_Helper.h
 * @author    Lewis He (lewishe@outlook.com)
 * @license   MIT
 * @copyright Copyright (c) 2023  Shenzhen Xin Yuan Electronic Technology Co., Ltd
 * @date      2023-04-20
 *
 */

#pragma once
#include <lvgl.h>
#include "helpers/LilyGo_Display.h"
#include <ui/ui_helpers.h>
#include <app.h>
#include <ui/ui.h>
#include <Arduino.h>

extern lv_obj_t *lastScreen;

void beginLvglHelper(LilyGo_Display &board, bool debug = false);

void changeScreen(lv_obj_t ** target, lv_scr_load_anim_t fademode = LV_SCR_LOAD_ANIM_FADE_ON, int spd = 300, int delay = 0, void (*target_init)(void) = &ui_Setting_Screen_screen_init, bool saveAsLastScreen = true);

void backToLastScreen();