#include <stdio.h>
#include <time.h>

int main() {
    char userInput[100];
    scanf("%s", userInput);
    printf("%s\n", userInput);
    printf("Today's Date:\n");
    // Start by telling the time
    time_t rawtime;
    struct tm *date;
    time(&rawtime);
    date = localtime(&rawtime);
    printf("%s",asctime(date));
}
