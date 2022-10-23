/* DRIVER UNTUK WORDMACHINE.C */

/* COMPILE MESSAGE
gcc driverword.c wordmachine.c ../mesinkarakter/charmachine.c ../string/string.c ../liststring/liststring.c -o a
*/

#include "wordmachine.h"
#include "../boolean.h"
#include <stdio.h>
#include <stdlib.h>

boolean endWord;
Word currentWord;
char currentChar;

int main()
{
    STARTWORD();
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
