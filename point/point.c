// ADT Sederhana : ADT point
/* ADT Point wajib memiliki koordinat X dan Y. ADT ini digunakan untuk 
merepresentasikan lokasi. */

/* Implementasi ADT Point */
#include "point.h"
#include <stdio.h>

/* Primitif */
/* Konstruktor Point*/
void CreatePoint(Point *P, int X, int Y){
/* Membuat sebuah Point dengan komponen Absis X dan Ordinat Y */
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

/* Input Output */
// void ReadPoint(Point *P); (perlu kah?)
/* Membaca nilai absis dan ordinat Point P */

void WritePoint(Point P){
/* Menuliskan Point P ke layar dengan format (X,Y) */
    printf("(%d,%d)\n", Absis(P), Ordinat(P));
}

/* Operasi Point */
void nextPoint(Point *P, int nextX, int nextY){
/* Penggeseran nextX point ke kanan dan nextYpoint kebawah */
    Absis(*P) += nextX;
    Ordinat(*P) += nextY;
}
boolean isAdj(Point P, Point X){
/* Menghasilkan true jika Point P adjacent dengan X*/
    int distAbsis = Absis(P)-Absis(X);
    int distOrdinat = Ordinat(P)-Ordinat(X);
    return (distAbsis == 1 || distAbsis == 0 || distAbsis == -1) && (distOrdinat == 1 || distOrdinat == 0 || distOrdinat == -1);
}
// boolean isBlock(Point P);
/* Mengirimkan true jika point P merupakan batasan/titik lokasi suatu tempat */
/* Batasan peta ditandai dengan * */
/* Titik lokasi yaitu tempat telepon (T), tempat mixing (M), tempat menggoreng (F), tempat memotong (C), dan tempat merebus (B). */
