
/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "charmachine.h"
#include "../boolean.h"
#include <stdio.h>

char currentChar;
boolean EOP;

FILE *pita;
static int retval;
static boolean isFile;

void START(FILE *input, boolean file)
{
    /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
       Karakter pertama yang ada pada pita posisinya adalah pada jendela.
       I.S. : sembarang
       F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != MARK maka EOP akan padam (false).
              Jika currentChar = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    pita = input;
    isFile = file;
    ADV();
}

void ADV()
{
    /* Pita dimajukan satu karakter.
       I.S. : Karakter pada jendela =
              currentChar, currentChar != MARK
       F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
              currentChar mungkin = MARK.
                    Jika  currentChar = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    if (!isFile)
    {
        retval = fscanf(pita, "%c", &currentChar);
        EOP = (currentChar == MARK);
    }
    else
    {
        currentChar = fgetc(pita);
        EOP = feof(pita);
        if (EOP)
        {
            fclose(pita);
        }
    }
}

// void ReadFile(String filename, LString *ans)
// {
//     pita = fopen(SBUFFER(filename), "r");

//     boolean first = true;

//     while (!feof(pita))
//     {
//         char temp[150];
//         String line;

//         CreateEmptyString(&line, 150);

//         fgets(temp, 150, pita);
//         setLiteral(&line, temp);

//         if (first)
//         {
//             CreateLString(ans, 50);
//             first = false;
//         }

//         insertLastString(ans, line);
//     }
// }
