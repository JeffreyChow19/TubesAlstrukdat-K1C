// ADT Sederhana : ADT Time
/* ADT Waktu wajib memiliki data Hari, Jam, dan Menit. */

/* Implementasi ADT Waktu */

#include "../boolean.h"
#include "time.h"
#include <stdio.h>

/********** Primitif **********/
/********** Konstruktor Point **********/
void CreateTime(Time *T, int dd, int hh, int mm)
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

/********** Input Output **********/
void WriteTime(Time T)
{
    printf("%02d.%02d.%02d\n", Day(T), Hour(T), Minute(T));
}
void WriteDuration(Time T)
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

/********** Validasi Time **********/
boolean isTimeValid(int dd, int hh, int mm)
{
    return (dd >= 0 && hh >= 0 && hh <= 23 && mm >= 0 && mm <= 59);
}
boolean isDurZero(Time T)
{
    return (Day(T) == 0 && Hour(T) == 0 && Minute(T) == 0);
}

/*********** Konversi TipeData ***********/
int TimeToMinute(Time T)
{
    return (Day(T) * 1440 + Hour(T) * 60 + Minute(T));
}
Time MinutetoTime(int N)
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

/*********** Operasi Time ***********/
void decDuration(Time *T)
{
    int mm = TimeToMinute(*T);
    if (mm > 0)
    {
        mm--;
        *T = MinutetoTime(mm);
    }
}
void decNDuration(Time *T, int N)
{
    int mm = TimeToMinute(*T);
    mm -= N;
    if (mm < 0)
        mm = 0;
    *T = MinutetoTime(mm);
}
void incTime(Time *T)
{
    int mm = TimeToMinute(*T);
    mm++;
    *T = MinutetoTime(mm);
}
void incNTime(Time *T, int N)
{
    int mm = TimeToMinute(*T);
    mm += N;
    *T = MinutetoTime(mm);
}