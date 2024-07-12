#ifndef URLS_MANAGER_H
#define URLS_MANAGER_H

#include <Arduino.h>

#define Server_BaseUrl String("https://discord.com/api/v10")

class Urls_Manager
{
public:
    static String GetBotApplicationUrl();
};

#endif