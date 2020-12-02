#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <form.h>
#include "../usecases/calculator_usecase.h"
#include "../usecases/send_message_usecase.h"
#include "constants.h"

pthread_t threads1, threads2;

void calculator_menu();
void chat_menu();

void menu()
{
    int operation;
    do
    {
        system("clear");
        printf("##################################\n");
        printf("##### BEM VINDO AO MINIATURE #####\n");
        printf("##################################\n\n");
        printf("# Escolha uma das funcionalidades: \n\n");
        printf("1. Chat \n");
        printf("2. Calculadora \n");
        scanf("%d", &operation);
    } while (operation < 1 || operation > 2);

    operation == 1
        ? chat_menu()
        : calculator_menu();
}

void *call_get_messages()
{
    while (1)
    {
        printf("get message\n\n");
        sleep(10);
    }
}

void chat_screen()
{
    FIELD *field[2];
    FORM *chat_form;
    int ch;
    char message[120];

    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    field[0] = new_field(2, 60, 4, 19, 0, 0);
    field[1] = NULL;
    set_field_back(field[0], A_UNDERLINE);

    chat_form = new_form(field);
    post_form(chat_form);
    refresh();

    set_current_field(chat_form, field[0]);
    mvprintw(4, 2, "Nova mensagem: ");
    refresh();

    while ((ch = getch()) != KEY_F(1))
    {
        int breakWhile = 0;
        switch (ch)
        {
        case '\n':
            form_driver(chat_form, REQ_NEXT_FIELD);
            snprintf(message, 120, "%s", field_buffer(field[0], 0));
            set_field_buffer(field[0], 0, "");
            form_driver(chat_form, REQ_PREV_FIELD);
            send_message_usecase(username, message);
            break;
        case 27:
            breakWhile = 1;
            break;
        default:
            form_driver(chat_form, ch);
            break;
        }

        if (breakWhile == 1)
        {
            break;
        }
    }

    unpost_form(chat_form);
    free_form(chat_form);
    free_field(field[0]);
    endwin();
}

void chat_menu()
{
    int iret1;
    int iret2;
    char message[120];

    system("clear");
    printf("# Digite o seu nome: ");
    scanf("%s", username);
    chat_screen();

    // iret2 = pthread_create(&threads2, NULL, call_get_messages, NULL);
    // iret1 = pthread_create(&threads1, NULL, call_send_message, NULL);

    // pthread_join(threads2, NULL);
    // pthread_join(threads1, NULL);
}

void calculator_menu()
{
    int operation;
    int values[2];

    do
    {
        system("clear");
        printf("# MINIATURE - CALCULATOR\n\n");
        printf("# Escolha uma das operações: \n\n");
        printf("1. Soma \n");
        printf("2. Subtração \n");
        printf("3. Divisão \n");
        printf("4. Multiplicação \n");
        printf("5. Raíz Quadrada \n\n");
        printf("6. <- Voltar\n\n");
        scanf("%d", &operation);
    } while (operation < 1 || operation > 6);

    if (operation == 6)
    {
        menu();
        return;
    }

    if (operation == 5)
    {
        printf("# Agora digite o valor: ");
        scanf("%d", &values[0]);
    }
    else
    {
        printf("# Agora digite o primeiro valor: ");
        scanf("%d", &values[0]);
        printf("# Agora digite o segundo valor: ");
        scanf("%d", &values[1]);
        system("reset");
    }

    calculator_usecase(values, operation);
}