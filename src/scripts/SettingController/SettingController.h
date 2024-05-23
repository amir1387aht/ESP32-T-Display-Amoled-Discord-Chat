#ifndef SETTING_CONTROLLER_H
#define SETTING_CONTROLLER_H

#include <corgi_framwork/Script.h>
#include <ui/ui.h>

class SettingController : public Script
{
public:
    void start() override;
    void update() override;
};

#endif