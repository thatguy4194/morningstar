#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

char *functionNames[12] = {
    "time",
    "printTest"
};

void getTime() {
    printf("Today's Date:\n");
    // Start by telling the time
    time_t rawtime;
    struct tm *date;
    time(&rawtime);
    date = localtime(&rawtime);
    printf("%s",asctime(date));

}
const int NUMBER_OF_FUNCTIONS = 2;

int main() {
    FILE *file = fopen("morningstar.conf","r");
    int i, lineNum = 0, caseNum = -1;
    char c, command[16];
    // it will be the case number in the switch statement that executes the correct function.
    char *functionNames[12] = {
    "time",
    "printTest"
};

    if (file == NULL) {
       printf("lol u suck at filing");
       return 1;
    }
    else {
        printf("File is present...\n");
        for (c = getc(file); c != EOF; c = getc(file))
            if (c == '\n')
                ++lineNum;
        rewind(file);
        for (i = 0; i < lineNum; ++i) {
            fscanf(file, "%s", command);
            // Find the case number using the corresponding arrays
            for (i = 0; i < NUMBER_OF_FUNCTIONS; ++i) {
                if (strcmp(functionNames[i], command) == 0) {
                    caseNum = i;
                    break;
                }
            }
            if (caseNum == -1) {
                // If a function isnt found, report and stop
                printf("%s is not a function!",command);
                return 1;
            }
            switch (caseNum) {
                case 0:
                    getTime();
                    break;
                case 1:
                    printf("Test successful!");
            }
            caseNum = -1; //Set caseNum back to -1 so that if the next function isnt found,
                          //error function isnt triggered
        }
    }
}
