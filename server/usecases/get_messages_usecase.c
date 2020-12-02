#include "../../miniature.h"
#include "../utils/constants.h"
#include "../../miniature.h"

void *client_get_messages(int last_message_id, chat_messages *payload)
{
    if (last_message_id == 0)
    {
        for (int i = 0; i < messagesNumber; i++)
        {
            printf("entrou");
            printf("%s", messages[i].message);
            chat_messages result = {.messages = *messages};
            payload = &result;
        }
        return (void *)0;
    }

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
        payload->messages[count++] = messages[i];
    }
}