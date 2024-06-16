#ifndef CHAT_CONTROLLER_H
#define CHAT_CONTROLLER_H

#include <corgi_framwork/Script.h>
#include <ui/ui.h>
#include <Arduino.h>

class ChatController : public Script
{
public:
    void start() override;
    void update() override;

    DEFINE_TYPE_TAG(ChatController)
};

#endif