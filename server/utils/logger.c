#include <stdio.h>
#include <time.h>
#include <stdarg.h>

void logger(char *char_format, ...)
{
    va_list valist;

    va_start(valist, char_format);

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    printf("\033[0;32m");
    printf("%s", asctime(tm));
    printf("\033[0m");
    printf("--->");

    vprintf(char_format, valist);
    printf("\n\n");
}