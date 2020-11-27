#include <stdio.h>
#include <stdlib.h>
#include "../usecases/calculator_usecase.h"

void menu(char *host)
{
    int operation;
    int values[2];

    do
    {
        system("clear");
        printf("##################################\n");
        printf("##### BEM VINDO AO MINIATURE #####\n");
        printf("##################################\n\n");
        printf("# Escolha uma das operações: \n\n");
        printf("1. Soma \n");
        printf("2. Subtração \n");
        printf("3. Divisão \n");
        printf("4. Multiplicação \n");
        printf("5. Raíz Quadrada \n\n");
        scanf("%d", &operation);
    } while (operation < 1 || operation > 5);

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

    calculator_usecase(host, values, operation);
}