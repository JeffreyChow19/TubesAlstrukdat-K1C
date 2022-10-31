#include "../adt/simulator/simulator.h"
#include "../adt/matriks/matriks.h"

#ifndef MOVENACT_H
#define MOVENACT_H

/* ******* CHECK NEXT POSISI ******* */
/* *** Memastikan simulator tidak terhalangi *** */
/* Mengembalikan true jika posisi selanjutnya dari simulator, berdasarkan arahnya, terdapat elemen ('X', 'T', dll.) */
boolean isBlocked(Sim S, char dir, Matrix M);

/* *** Memastikan simulator tidak keluar peta *** */
/* Mengembalikan true jika posisi selanjutnya dari simulator, berdasarkan arahnya, bukan merupakan indeks efektif matriks */
boolean isOutOfBound(Sim S, char dir, Matrix M);

/* ******* PEMINDAHAN SIMULATOR ******* */
/* *** Memindahkan simulator sesuai arah yang diberikan *** */
/* I.S. Simulator dengan posisinya dan Matriks terdefinisi, arah telah ditentukan */
/* F.S. Simulator berpindah ke arah yang sesuai jika tidak keluar map atau tidak terhalangi, mengembalikan true karena berhasil dipindahkan 
        Simulator tidak berpindah jika terhalangi atau keluar map, mengembalikan false karena tidak berhasil dipindahkan
*/
boolean setPos(Sim *S, char dir, Matrix M);

#endif