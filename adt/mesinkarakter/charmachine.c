
/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "charmachine.h"
#include "../boolean.h"
#include <stdio.h>

char currentChar;
boolean EOP;

FILE *pita;
boolean isFile;
static int retval;

void START(FILE *input, boolean file)
{
    /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela. Pita dapat berupa input console (stdin) atau input file. Jika input file, maka boolean file bernilai true, vice versa.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
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
        EOP = currentChar == EOF;
        if (EOP)
        {
            fclose(pita);
        }
    }
}