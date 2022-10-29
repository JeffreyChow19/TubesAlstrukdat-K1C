// ADT Sederhana : ADT Time
/* ADT Waktu wajib memiliki data Hari, Jam, dan Menit. */

/* Implementasi ADT Waktu */

#include "../boolean.h"
#include "time.h"
#include <stdio.h>

/* Primitif */
/* Konstruktor Point*/
void CreateTime(Time *T, int dd, int hh, int mm)
/* Membuat sebuah time dengan komponen dd hari, hh jam, mm menit */
{
    if (isTimeValid(dd, hh, mm))
    {
        Day((*T)) = dd;
        Hour((*T)) = hh;
        Minute((*T)) = mm;
    }
    else
        printf("Masukkan waktu tidak valid!\n");
}

/* Input Output */
void WriteTime(Time T)
/* Menuliskan ke layar waktu dalam format : dd.hh.mm */
{
    printf("%02d.%02d.%02d\n", Day(T), Hour(T), Minute(T));
}
void WriteDuration(Time T)
/* Menuliskan ke layar waktu durasi dalam format : dd Hari hh Jam mm Menit */
{
    if (Day(T) != 0)
    {
        printf("%d Hari", Day(T));
        if ((Hour(T) != 0) || (Minute(T) != 0))
            printf(" ");
    }
    if (Hour(T) != 0)
    {
        printf("%d Jam", Hour(T));
        if (Minute(T) != 0)
            printf(" ");
    }
    if (Minute(T) != 0)
        printf("%d Menit", Minute(T));
    if ((Day(T) == 0) && (Hour(T) == 0) && (Minute(T) == 0))
        printf("0");
}

/* Validasi Time */
boolean isTimeValid(int dd, int hh, int mm)
/* Menghasilkan true jika dd, hh, mm dapat membentuk time yang valid */
{
    return (dd >= 0 && hh >= 0 && hh <= 23 && mm >= 0 && mm <= 59);
}
boolean isDurZero(Time T)
/* Menghasilkan true jika durasi menunjukkan 0 Hari 0 Jam 0 Menit*/
{
    return (Day(T) == 0 && Hour(T) == 0 && Minute(T) == 0);
}

/* Konversi TipeData */
int TimeToMinute(Time T)
/* Mengubah tipe data Time(dd, hh, mm) menjadi menit(integer) */
{
    return (Day(T) * 1440 + Hour(T) * 60 + Minute(T));
}
Time MinutetoTime(int N)
/* Mengubah tipe data integer(representasi menit) menjadi Time(dd, hh, mm) */
{
    int mm = N;
    int dd = mm / 1440;
    mm -= dd * 1440;
    int hh = mm / 60;
    mm -= hh * 60;

    Time T;
    CreateTime(&T, dd, hh, mm);
    return T;
}

/* Operasi Time */
void decDuration(Time *T)
/* Durasi berkurang 1 menit */
{
    int mm = TimeToMinute(*T);
    if (mm > 0)
    {
        mm--;
        *T = MinutetoTime(mm);
    }
}
void decNDuration(Time *T, int N)
/* Durasi berkurang N menit */
{
    int mm = TimeToMinute(*T);
    mm -= N;
    if (mm < 0)
        mm = 0;
    *T = MinutetoTime(mm);
}
void incTime(Time *T)
/* Time bertambah 1 menit */
{
    int mm = TimeToMinute(*T);
    mm++;
    *T = MinutetoTime(mm);
}
void incNTime(Time *T, int N)
/* Time T bertambah sebanyak N menit */
{
    int mm = TimeToMinute(*T);
    mm += N;
    *T = MinutetoTime(mm);
}

/* void fixedTime(Time *T)
// Memperbaiki tipe data time menjadi data yang valid
{
    int temp;
    if(Minute((*T)) > 59){
        temp = Minute((*T))/60;
        Hour((*T)) += temp;
        Minute((*T)) -= temp*60;
    } else if (Minute((*T)) < 0){
        Minute((*T)) += 60;
        Hour((*T))--;
    }

    if(Hour((*T)) > 23){
        temp = Hour((*T))/24;
        Day((*T)) += temp;
        Hour((*T)) -= temp*24;
    } else if (Hour((*T)) < 0){
        Hour((*T)) += 24;
        Day((*T))--;
    }
} */