#include <urls.h>

String Urls_Manager::GetBotApplicationUrl()
{
    return Server_BaseUrl + String("/applications/@me");
}