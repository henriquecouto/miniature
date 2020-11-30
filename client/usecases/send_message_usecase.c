#include "../../miniature.h"
#include "../utils/constants.h"
#include <string.h>

void send_message_usecase(char username[], char message[])
{
    CLIENT *client;
    chat_message send_message_1_arg;
    strncpy(send_message_1_arg.sender_username, username, sizeof(&username));
    strncpy(send_message_1_arg.message, message, sizeof(&message));

#ifndef DEBUG
    client = clnt_create(host, MINIATURE_PROGRAM, CALCULATOR_VERS, "udp");
    if (client == NULL)
    {
        clnt_pcreateerror(host);
        exit(1);
    }
#endif /* DEBUG */

send_message_1(&send_message_1_arg, client);

#ifndef DEBUG
    clnt_destroy(client);
#endif /* DEBUG */
}