#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void word_func(char * givenString, int n) {
    int i;
    int endIndex;
    int startIndex = 0;
    for (i = 0; i < strlen(givenString); i++)
    {
        if (givenString[i] == ' ' || i == strlen(givenString) - 1)
        {
           endIndex = i;
           if ((endIndex - startIndex) > n)
           {
                printf("%.*s = %d\n", (endIndex - startIndex), givenString + startIndex, (endIndex - startIndex));
           }
           else
           {
                printf("NO\n");
           }

           startIndex = i + 1;
        }
    }
}
