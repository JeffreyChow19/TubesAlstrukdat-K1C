#ifndef OLAH_H
#define OLAH_H
#include "../adt/simulator/simulator.h"
#include "../adt/string/string.h"

void processFood(String process);
/* I.S. process valid dan terdefinisi
   F.S. dilakukan proses fry/mix/boil/chop
        jika berhasil, bahan dikeluarkan dari inventory dan makanan yang dibuat dimasukkan ke inventory
        jika gagal, mengeluarkan pesan gagal, dan bahan apa yang tidak tersedia
*/

#endif
