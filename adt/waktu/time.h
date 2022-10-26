// ADT Sederhana : ADT Time
/* ADT Waktu wajib memiliki data Hari, Jam, dan Menit. */

/* Header ADT Waktu */

#ifndef TIME_H
#define TIME_H

#include "../boolean.h"

typedef struct
{
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
void WriteTime(Time T);
/* Menuliskan ke layar waktu dalam format : dd.hh.mm */
void WriteDuration(Time T);
/* Menuliskan ke layar waktu durasi dalam format : dd Hari hh Jam mm Menit */

/* Validasi Time */
boolean isTimeValid(int dd, int hh, int mm);
/* Menghasilkan true jika dd, hh, mm dapat membentuk time yang valid */
boolean isDurZero(Time T);
/* Menghasilkan true jika durasi menunjukkan 0 Hari 0 Jam 0 Menit*/

/* Konversi TipeData */
int TimeToMinute(Time T);
/* Mengubah tipe data Time(dd, hh, mm) menjadi menit(integer) */
Time MinutetoTime(int N);
/* Mengubah tipe data integer(representasi menit) menjadi Time(dd, hh, mm) */
/* void fixedTime(Time *T); */
/* Memperbaiki tipe data time menjadi data yang valid*/

/* Operasi Time */
void decDuration(Time *T);
/* Durasi berkurang 1 menit */
void decNDuration(Time *T, int N);
/* Durasi berkurang N menit */
void incTime(Time *T);
/* Time bertambah 1 menit */
void incNTime(Time *T, int N);
/* Time T bertambah sebanyak N menit */

#endif