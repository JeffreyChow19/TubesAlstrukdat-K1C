/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../boolean.h"
#include "../string/string.h"
#include <stdio.h>

#define MARK '\n'

/* State Mesin */
extern char currentChar;
extern boolean EOP;
extern FILE *pita;
extern boolean isFile;

void START(FILE *input, boolean file);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

// void ReadFile(String filename, LString *ans);
/* Membaca dari suatu file txt kemudian memindahkannya ke list of string.
I.S. filename terdefinisi, ans sembarang
F.S. filename berhasil dibaca dan elemennya akan dipindahkan ke list of string per line. ans terdefinisi.
*/

#endif