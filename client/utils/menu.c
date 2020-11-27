#include <stdio.h>
#include <stdlib.h>
#include "../usecases/calculator_usecase.h"
#include "constants.h"

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

void chat_menu()
{
    system("clear");
    printf("# Digite o seu nome: "); 
    scanf("%s", username);
    printf("%s", username);
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