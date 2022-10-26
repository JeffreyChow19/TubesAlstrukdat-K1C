/* DRIVER UNTUK WORDMACHINE.C */

/* COMPILE MESSAGE
gcc driverword.c wordmachine.c ../mesinkarakter/charmachine.c ../string/string.c -o a
*/

#include "wordmachine.h"
#include "../boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
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

    return 0;
}
