// ADT Sederhana : ADT Time
/* ADT Waktu wajib memiliki data Hari, Jam, dan Menit. */

/* Implementasi ADT Waktu */


#include "boolean.h"
#include "time.h"
#include <stdio.h>

/* Primitif */
/* Konstruktor Point*/
void CreateTime(Time *T, int dd, int hh, int mm){
/* Membuat sebuah time dengan komponen dd hari, hh jam, mm menit */
    if (isTimeValid(dd, hh, mm)) {
        Day((*T)) = dd;
        Hour((*T)) = hh;
        Minute((*T)) = mm;
    } else printf("Masukkan waktu tidak valid!\n");
}

/* Input Output */
// void ReadTime(Time *T);
/* Membaca masukkan waktu */
void WriteTime(Time T){
/* Menuliskan ke layar waktu dalam format : dd Hari hh Jam mm Menit */
    if (Day(T) != 0) printf("%d Hari ", Day(T));
    if (Hour(T) != 0) printf("%d Jam ", Hour(T));
    if (Minute(T) != 0) printf("%d Menit", Minute(T));
    printf("\n");
}

/* Validasi Time */
boolean isTimeValid(int dd, int hh, int mm){
/* Menghasilkan true jika dd, hh, mm dapat membentuk time yang valid */
    return (dd >= 0 && hh >= 0 && hh <= 23 && mm >=0 && mm <= 59);
}


/* Konversi TipeData */
int TimeToMinute(Time T){
/* Mengubah tipe data Time(dd, hh, mm) menjadi menit(integer) */
    return(Day(T)*1440 + Hour(T)*60 + Minute(T));
}
Time MinutetoTime(int N){
/* Mengubah tipe data integer(representasi menit) menjadi Time(dd, hh, mm) */
    int mm = N;
    int dd = mm/1440;
    mm -= dd*1440;
    int hh = mm/60;
    mm -= hh*60;

    Time T;
    CreateTime(&T, dd, hh, mm);
    return T;
}
void fixTime(Time *T){
/* Memperbaiki tipe data time menjadi data yang valid*/
    if(Minute((*T)) > 59){
        int temp = Minute((*T))/60;
        Hour((*T)) += temp;
        Minute((*T)) -= temp*60;
    }
    if(Hour((*T)) > 23){
        int temp = Hour((*T))/24;
        Day((*T)) += temp;
        Hour((*T)) -= temp*24;
    }
}

/* Operasi Time */
void nextMinute(Time *T){
/* Time berkurang 1 menit */
    if (Minute((*T)) == 0){
        Minute((*T)) = 59;
        if (Hour((*T)) == 0){
            Hour((*T)) = 23;
            Day((*T))--;
        } else Hour((*T))--;
    } else Minute((*T))--;
}
void nextNMinute(Time *T, int N){
/* Time berkurang N menit */
    // Mengubah N menjadi dd hh mm
    Time Tplus = MinutetoTime(N);
    addTime(T, Day(Tplus), Hour(Tplus), Minute(Tplus));
}
void addTime(Time *T, int dd, int hh, int mm){
/* Menambahkan Day sebanyak dd, Hour sebanyak hh, Minute sebanyak mm */
    Day((*T)) += dd;
    Hour((*T)) += hh;
    Minute((*T)) += mm;
    fixTime(T);
}
