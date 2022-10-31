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
/* Membuat sebuah time dengan komponen dd hari, hh jam, mm menit */
/* I.S. Time T sembarang, day(dd), hour(hh), minute(mm) terdefinisi */
/* F.S. Time T terdefinisi dengan komponen dd hh mm */
void CreateTime(Time *T, int dd, int hh, int mm);

/* Input Output */
/* Menuliskan ke layar waktu dalam format : dd.hh.mm */
/* I.S. Time T terdefinisi */
/* F.S. Waktu aplikasi tertampil pada layar dalam format dd.hh.mm */
void WriteTime(Time T);
/* Menuliskan ke layar waktu durasi dalam format : dd Hari hh Jam mm Menit */
/* I.S. Time T terdefinisi */
/* F.S. Time T tertampil di layar dalam format durasi dd Hari hh Jam mm Menit */
void WriteDuration(Time T);

/* Validasi Time */
/* Menerima input komponen time: dd(day), hh(jam), dan mm (menit) */
/* dan menghasilkan true jika dd, hh, mm dapat membentuk time yang valid */
/* Time valid : 0 <= dd ; 0 <= hh <= 23; 0 <= mm <= 59 */
boolean isTimeValid(int dd, int hh, int mm);
/* Menerima masukkan Time T */
/* Menghasilkan true jika durasi T menunjukkan 0 Hari 0 Jam 0 Menit */
boolean isDurZero(Time T);

/* Konversi TipeData */
/* Menerima masukkan Time T */
/* Mengubah tipe data Time(format dd, hh, mm) menjadi integer(format dalam menit) */
int TimeToMinute(Time T);
/* Menerima masukkan waktu dalam menit (integer) */
/* Mengubah tipe data integer(representasi menit) menjadi Time(dd, hh, mm) */
Time MinutetoTime(int N);

/* Operasi Time */
/* I.S. Time T terdefinisi */
/* F.S. Durasi/Time T berkurang 1 menit */
void decDuration(Time *T);
/* I.S. Time T terdefinisi */
/* F.S. Durasi/Time T berkurang N menit */
void decNDuration(Time *T, int N);
/* I.S. Time T terdefinisi */
/* F.S. Time T bertambah 1 menit */
void incTime(Time *T);
/* I.S. Time T terdefinisi */
/* F.S. Time T bertambah sebanyak N menit */
void incNTime(Time *T, int N);

#endif