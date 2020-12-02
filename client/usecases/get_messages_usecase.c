#include "../../miniature.h"
#include "../utils/constants.h"

chat_messages get_messages_usecase(int last_message_id)
{

    CLIENT *client;
    chat_messages *result;
    int get_messages_1_arg = last_message_id;

#ifndef DEBUG
    client = clnt_create(host, MINIATURE_PROGRAM, CALCULATOR_VERS, "udp");
    if (client == NULL)
    {
        clnt_pcreateerror(host);
        exit(1);
    }
#endif /* DEBUG */
    printf("entrou aqui");
    result = get_messages_1(&get_messages_1_arg, client);
    return *result;

#ifndef DEBUG
    clnt_destroy(client);
#endif /* DEBUG */
}