// ADT Sederhana : ADT Time
/* ADT Waktu wajib memiliki data Hari, Jam, dan Menit. */

/* Driver ADT Waktu */

#include "boolean.h"
#include "time.h"
#include <stdio.h>

int main()
{
    Time T1, T2, T3;
    int dd, hh, mm, N;

    /* Konstruktor */
    scanf("%d", &dd);
    scanf("%d", &hh);
    scanf("%d", &mm);
    CreateTime(&T1, dd, hh, mm);
    while (!isTimeValid(dd, hh, mm))
    {
        scanf("%d", &dd);
        scanf("%d", &hh);
        scanf("%d", &mm);
        CreateTime(&T1, dd, hh, mm);
    }

    /* Input Output */
    WriteTime(T1);
    WriteDuration(T1);

    /* Validasi Time */
    printf("Valid? %d\n", isTimeValid(dd, mm, hh));
    printf("Zero? %d\n", isDurZero(T1));

    printf("T3 : \n");
    CreateTime(&T3, 0, 0, 0);
    WriteDuration(T3);
    printf("Zero? %d\n", isDurZero(T3));
    printf("\n");

    /* Konversi TipeData */
    printf("Konversi to minute %d\n", TimeToMinute(T1));

    printf("N = ");
    scanf("%d", &N);
    printf("%d menit menjadi ", N);
    T2 = MinutetoTime(N);
    WriteTime(T2);
    WriteDuration(T2);
    printf("\n");

    /* Operasi Time */
    // Operasi Time
    printf("Time\n");
    incTime(&T2);
    printf("Increment Time : ");
    WriteTime(T2);
    N = 1410;
    printf("Next %d Menit menjadi ", N);
    incNTime(&T2, N);
    WriteTime(T2);
    printf("\n");

    // Operasi Durasi
    printf("Duration\n");
    decDuration(&T2);
    printf("Decrement duration : ");
    WriteDuration(T2);
    N = 1500 + 1320;
    printf("Decrement %d Menit menjadi ", N);
    decNDuration(&T2, N);
    WriteDuration(T2);

    return 0;
}