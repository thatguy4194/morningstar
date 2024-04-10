#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void getTime() {
    printf("Today's Date:\n");
    // Start by telling the time
    time_t rawtime;
    struct tm *date;
    time(&rawtime);
    date = localtime(&rawtime);
    printf("%s",asctime(date));

}

int main() {
    FILE *file = fopen("morningstar.conf","r");
    if (file == NULL) {
       printf("lol u suck at filing");
       return 1;
    }
    if (file != NULL) {
        printf("File is present...");
    }

}
