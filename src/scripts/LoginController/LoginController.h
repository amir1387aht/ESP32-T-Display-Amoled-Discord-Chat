#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include <corgi_framwork/Script.h>
#include <lcd_helpers/LilyGo_AMOLED.h>
#include <lcd_helpers/LV_Helper.h>
#include <ui/ui.h>

static lv_obj_t *kb;

extern "C" {
    void lv_example_textarea_2(void);
};

class LoginController : public Script
{
public:
    void start() override;
    void update() override;

    LoginController();

private:
    LilyGo_Class amoled;
    lv_obj_t *myScreen;
};

#endif