#include <stdio.h>
#include <time.h>

int main() {
    printf("Hello World!\n");
    // Start by telling the time
    time_t rawtime;
    struct tm *date;
    time(&rawtime);
    date = localtime(&rawtime);
    printf("%s",asctime(date));
}
