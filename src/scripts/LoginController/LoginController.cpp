#include <scripts/LoginController/LoginController.h>

LoginController::LoginController()
{
}

void LoginController::start()
{
    amoled.beginAMOLED_191();

    beginLvglHelper(amoled);

    ui_init();

    kb = lv_keyboard_create(lv_scr_act());
    lv_obj_set_size(kb, LV_HOR_RES, LV_VER_RES / 2);

    lv_keyboard_set_textarea(kb, ui_TextArea);

    //lv_example_textarea_2();
}

void LoginController::update()
{
    lv_task_handler();
    delay(5);
}