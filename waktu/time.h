// ADT Sederhana : ADT Time
/* ADT Waktu wajib memiliki data Hari, Jam, dan Menit. */

/* Header ADT Waktu */

#ifndef TIME_H
#define TIME_H

#include "boolean.h"

typedef struct {
    int dd; // Hari >= 0
    int hh; // Jam [0..23]
    int mm; // Menit [0..59]
} Time;

/* Selektor Point */
#define Day(T) T.dd
#define Hour(T) T.hh
#define Minute(T) T.mm

/* Primitif */
/* Konstruktor Point*/
void CreateTime(Time *T, int dd, int hh, int mm);
/* Membuat sebuah time dengan komponen dd hari, hh jam, mm menit */

/* Input Output */
// void ReadTime(Time *T);
/* Membaca masukkan waktu */
void WriteTime(Time T);
/* Menuliskan ke layar waktu dalam format : dd Hari hh Jam mm Menit */

/* Validasi Time */
boolean isTimeValid(int dd, int hh, int mm);
/* Menghasilkan true jika dd, hh, mm dapat membentuk time yang valid */

/* Konversi TipeData */
int TimeToMinute(Time T);
/* Mengubah tipe data Time(dd, hh, mm) menjadi menit(integer) */
Time MinutetoTime(int N);
/* Mengubah tipe data integer(representasi menit) menjadi Time(dd, hh, mm) */
void fixTime(Time *T);
/* Memperbaiki tipe data time menjadi data yang valid*/

/* Operasi Time */
void nextMinute(Time *T);
/* Time berkurang 1 menit */
void nextNMinute(Time *T, int N);
/* Time berkurang N menit */
void addTime(Time *T, int dd, int hh, int mm);
/* Menambahkan komponen time menjadi time baru */

#endif