/* DRIVER UNTUK WORDMACHINE.C */

/* COMPILE MESSAGE
gcc driverword.c wordmachine.c ../mesinkarakter/charmachine.c ../../color/color.c ../string/string.c -o driverword
*/

#include "wordmachine.h"
#include "../boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* STARTWORD DARI STDIN */
    printf("INPUT CONSOLE\n");
    STARTWORD(stdin, false);
    IgnoreBlanks();

    while (!endWord)
    {
        int i;
        for (i = 0; i < currentWord.Length; i++)
        {
            printf("%c", currentWord.TabWord[i]);
        }
        ADVWORD();
        printf(" ");
    }

    /* START WORD DARI FILE */
    printf("\nREAD INPUT FROM FILE\n");
    STARTWORD(fopen("testFile.txt", "r"), true);
    IgnoreBlanks();

    while (!endWord)
    {
        int i;
        for (i = 0; i < currentWord.Length; i++)
        {
            printf("%c", currentWord.TabWord[i]);
        }
        ADVWORD();
        printf(" ");
    }

    return 0;
}
