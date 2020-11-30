#include "../../miniature.h"
#include "../utils/constants.h"
#include "../utils/array.h"

void client_send_message(chat_message message)
{
    unshift(messages, messagesNumber, message);    
}