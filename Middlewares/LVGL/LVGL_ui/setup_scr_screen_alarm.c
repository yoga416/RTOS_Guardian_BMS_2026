/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen_alarm(lv_ui *ui)
{
    //Write codes screen_alarm
    ui->screen_alarm = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_alarm, 240, 280);
    lv_obj_set_scrollbar_mode(ui->screen_alarm, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_alarm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_alarm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_alarm, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_alarm, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_alarm_label_1
    ui->screen_alarm_label_1 = lv_label_create(ui->screen_alarm);
    lv_label_set_text(ui->screen_alarm_label_1, "System Alarm Log");
    lv_label_set_long_mode(ui->screen_alarm_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_alarm_label_1, 29, 12);
    lv_obj_set_size(ui->screen_alarm_label_1, 168, 32);

    //Write style for screen_alarm_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_alarm_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_alarm_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_alarm_label_1, lv_color_hex(0x3bc75e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_alarm_label_1, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_alarm_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_alarm_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_alarm_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_alarm_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_alarm_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_alarm_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_alarm_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_alarm_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_alarm_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_alarm_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_alarm_spangroup_1
    ui->screen_alarm_spangroup_1 = lv_spangroup_create(ui->screen_alarm);
    lv_spangroup_set_align(ui->screen_alarm_spangroup_1, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->screen_alarm_spangroup_1, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->screen_alarm_spangroup_1, LV_SPAN_MODE_BREAK);
    //create span
    ui->screen_alarm_spangroup_1_span = lv_spangroup_new_span(ui->screen_alarm_spangroup_1);
    lv_span_set_text(ui->screen_alarm_spangroup_1_span, "hello");
    lv_style_set_text_color(&ui->screen_alarm_spangroup_1_span->style, lv_color_hex(0x000000));
    lv_style_set_text_decor(&ui->screen_alarm_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->screen_alarm_spangroup_1_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->screen_alarm_spangroup_1, 20, 90);
    lv_obj_set_size(ui->screen_alarm_spangroup_1, 200, 100);

    //Write style state: LV_STATE_DEFAULT for &style_screen_alarm_spangroup_1_main_main_default
    static lv_style_t style_screen_alarm_spangroup_1_main_main_default;
    ui_init_style(&style_screen_alarm_spangroup_1_main_main_default);

    lv_style_set_border_width(&style_screen_alarm_spangroup_1_main_main_default, 0);
    lv_style_set_radius(&style_screen_alarm_spangroup_1_main_main_default, 0);
    lv_style_set_bg_opa(&style_screen_alarm_spangroup_1_main_main_default, 0);
    lv_style_set_pad_top(&style_screen_alarm_spangroup_1_main_main_default, 0);
    lv_style_set_pad_right(&style_screen_alarm_spangroup_1_main_main_default, 0);
    lv_style_set_pad_bottom(&style_screen_alarm_spangroup_1_main_main_default, 0);
    lv_style_set_pad_left(&style_screen_alarm_spangroup_1_main_main_default, 0);
    lv_style_set_shadow_width(&style_screen_alarm_spangroup_1_main_main_default, 0);
    lv_obj_add_style(ui->screen_alarm_spangroup_1, &style_screen_alarm_spangroup_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->screen_alarm_spangroup_1);

    //Write codes screen_alarm_spangroup_2
    ui->screen_alarm_spangroup_2 = lv_spangroup_create(ui->screen_alarm);
    lv_spangroup_set_align(ui->screen_alarm_spangroup_2, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->screen_alarm_spangroup_2, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->screen_alarm_spangroup_2, LV_SPAN_MODE_BREAK);
    //create span
    ui->screen_alarm_spangroup_2_span = lv_spangroup_new_span(ui->screen_alarm_spangroup_2);
    lv_span_set_text(ui->screen_alarm_spangroup_2_span, "hello");
    lv_style_set_text_color(&ui->screen_alarm_spangroup_2_span->style, lv_color_hex(0x000000));
    lv_style_set_text_decor(&ui->screen_alarm_spangroup_2_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->screen_alarm_spangroup_2_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->screen_alarm_spangroup_2, 0, 38);
    lv_obj_set_size(ui->screen_alarm_spangroup_2, 236, 201);

    //Write style state: LV_STATE_DEFAULT for &style_screen_alarm_spangroup_2_main_main_default
    static lv_style_t style_screen_alarm_spangroup_2_main_main_default;
    ui_init_style(&style_screen_alarm_spangroup_2_main_main_default);

    lv_style_set_border_width(&style_screen_alarm_spangroup_2_main_main_default, 0);
    lv_style_set_radius(&style_screen_alarm_spangroup_2_main_main_default, 0);
    lv_style_set_bg_opa(&style_screen_alarm_spangroup_2_main_main_default, 0);
    lv_style_set_pad_top(&style_screen_alarm_spangroup_2_main_main_default, 0);
    lv_style_set_pad_right(&style_screen_alarm_spangroup_2_main_main_default, 0);
    lv_style_set_pad_bottom(&style_screen_alarm_spangroup_2_main_main_default, 0);
    lv_style_set_pad_left(&style_screen_alarm_spangroup_2_main_main_default, 0);
    lv_style_set_shadow_width(&style_screen_alarm_spangroup_2_main_main_default, 0);
    lv_obj_add_style(ui->screen_alarm_spangroup_2, &style_screen_alarm_spangroup_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->screen_alarm_spangroup_2);

    //Write codes screen_alarm_btn_1
    ui->screen_alarm_btn_1 = lv_btn_create(ui->screen_alarm);
    ui->screen_alarm_btn_1_label = lv_label_create(ui->screen_alarm_btn_1);
    lv_label_set_text(ui->screen_alarm_btn_1_label, "");
    lv_label_set_long_mode(ui->screen_alarm_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_alarm_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_alarm_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_alarm_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_alarm_btn_1, 95, 258);
    lv_obj_set_size(ui->screen_alarm_btn_1, 45, 16);

    //Write style for screen_alarm_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_alarm_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_alarm_btn_1, lv_color_hex(0x42c73b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_alarm_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_alarm_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_alarm_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_alarm_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_alarm_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_alarm_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_alarm_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_alarm_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_alarm.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_alarm);

    //Init events for screen.
    events_init_screen_alarm(ui);
}
