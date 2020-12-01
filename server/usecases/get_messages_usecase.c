#include "../../miniature.h"
#include "../utils/constants.h"
#include "../../miniature.h"

void *client_get_messages(int last_message_id, chat_message *payload)
{
    int index_last_message;

    printf("%d", last_message_id);

    for (int i = 0; i < messagesNumber; i++)
    {
        if (messages[i].id == last_message_id)
        {
            index_last_message = i;
        }
    }

    int count = index_last_message + 1;
    for (int i = index_last_message + 1; i < messagesNumber; i++)
    {
        payload[count++] = messages[i];
    }
}