#ifndef SETTING_CONTROLLER_H
#define SETTING_CONTROLLER_H

#include <corgi_framwork/Script.h>
#include <helpers/LV_Helper.h>
#include <ui/ui.h>
#include <app.h>

class SettingController : public Script
{
public:
    void start() override;
    void update() override;

    DEFINE_TYPE_TAG(SettingController)

    ~SettingController();
};

#endif