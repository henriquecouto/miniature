#include "../../miniature.h"

void unshift(chat_message array[], int length, chat_message value)
{
    for (int i = length++; i > 0; i--)
    {
        array[i] = array[i - 1];
    }
    array[0] = value;
}