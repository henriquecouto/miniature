#include <stdlib.h>
#include <time.h>
#include "../../miniature.h"
#include "../utils/constants.h"
#include "../utils/array.h"

void client_send_message(chat_message message)
{
    srand(time(0));
    message.id = rand()*sizeof(message);
    printf("%d", message.id);
    unshift(messages, messagesNumber, message);
}