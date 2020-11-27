#include "../../miniature.h"
#include "../utils/constants.h"

void calculator_usecase(int values[], int operation)
{
	CLIENT *client;
	int *result;
	numbers_to_calculate sum_1_arg;
	numbers_to_calculate subtraction_1_arg;
	numbers_to_calculate division_1_arg;
	numbers_to_calculate multiplication_1_arg;
	square_root_number square_root_1_arg;

#ifndef DEBUG
	client = clnt_create(host, MINIATURE_PROGRAM, CALCULATOR_VERS, "udp");
	if (client == NULL)
	{
		clnt_pcreateerror(host);
		exit(1);
	}
#endif /* DEBUG */

	switch (operation)
	{
	case 1:
		sum_1_arg.value1 = values[0];
		sum_1_arg.value2 = values[1];
		result = sum_1(&sum_1_arg, client);
		break;
	case 2:
		subtraction_1_arg.value1 = values[0];
		subtraction_1_arg.value2 = values[1];
		result = subtraction_1(&subtraction_1_arg, client);
		break;
	case 3:
		division_1_arg.value1 = values[0];
		division_1_arg.value2 = values[1];
		result = division_1(&division_1_arg, client);
		break;
	case 4:
		multiplication_1_arg.value1 = values[0];
		multiplication_1_arg.value2 = values[1];
		result = multiplication_1(&multiplication_1_arg, client);
		break;
	case 5:
		square_root_1_arg.value = values[0];
		result = square_root_1(&square_root_1_arg, client);
	default:
		printf("Nenhuma operação encontrada");
		break;
	}

	if (result == (int *)NULL)
	{
		clnt_perror(client, "call failed");
	}
	else
	{
		printf("O resultado da operação no servidor é %d\n\n", *result);
	}

#ifndef DEBUG
	clnt_destroy(client);
#endif /* DEBUG */
}