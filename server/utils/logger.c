#include <stdio.h>
#include <time.h>

void logger(char string[]){
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    printf("\033[0;32m"); 
    printf("%s", asctime(tm));
    printf("\033[0m");
    printf("---> %s\n", string);
}