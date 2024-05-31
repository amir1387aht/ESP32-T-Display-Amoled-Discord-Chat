#ifndef CHAT_CONTROLLER_H
#define CHAT_CONTROLLER_H

#include <corgi_framwork/Script.h>
#include <ui/ui.h>

class ChatController : public Script
{
public:
    void start() override;
    void update() override;
};

#endif