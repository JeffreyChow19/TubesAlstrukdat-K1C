// ADT Sederhana : ADT Time
/* ADT Waktu wajib memiliki data Hari, Jam, dan Menit. */

/* Driver ADT Waktu */


#include "boolean.h"
#include "time.h"
#include <stdio.h>

int main() {
    Time T1, T2;
    int dd, hh, mm, N;

    /* Konstruktor */
    scanf("%d", &dd);
    scanf("%d", &hh);
    scanf("%d", &mm);
    CreateTime(&T1, dd, hh, mm);
    while (!isTimeValid(dd, hh, mm)){
        scanf("%d", &dd);
        scanf("%d", &hh);
        scanf("%d", &mm);
        CreateTime(&T1, dd, hh, mm);
    }

    /* Input Output */
    WriteTime(T1);

    /* Validasi Time */
    printf("Valid? %d\n", isTimeValid(dd, mm, hh));

    /* Konversi TipeData */
    printf("Konversi to minute %d\n", TimeToMinute(T1));

    printf("N = ");
    scanf("%d", &N);
    printf("%d menit menjadi ", N);
    T2 = MinutetoTime(N);
    WriteTime(T2);
    nextMinute(&T2);
    printf("NextTime : ");
    WriteTime(T2);
    printf("Next %d Menit menjadi ", N);
    nextNMinute(&T2, N);
    WriteTime(T2);
    printf("Tambahkan T1 dan T2 menjadi ");
    addTime(&T1, Day(T2), Hour(T2), Minute(T2));
    WriteTime(T1);

    return 0;
}