#include <math.h>
#include "operations.h"

int sum_operation(int value1, int value2)
{
    return value1 + value2;
}

int subtraction_operation(int value1, int value2)
{
    return value1 - value2;
}

int division_operation(int value1, int value2)
{
    return (int) value1 / value2;
}

int multiplication_operation(int value1, int value2)
{
    return value1 * value2;
}

int square_root_operation(int value)
{
    return (int) sqrt(value);
}