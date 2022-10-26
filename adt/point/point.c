// ADT Sederhana : ADT point
/* ADT Point wajib memiliki koordinat X dan Y. ADT ini digunakan untuk
merepresentasikan lokasi. */

/* Implementasi ADT Point */
#include "point.h"
#include <stdio.h>

/* Primitif */
/* Konstruktor Point*/
void CreatePoint(Point *P, int X, int Y)
/* Membuat sebuah Point dengan komponen Absis X dan Ordinat Y */
{
    if (isPointValid(X, Y))
    {
        Absis(*P) = X;
        Ordinat(*P) = Y;
    }
    else
        printf("Point tidak valid\n");
}

/* Input Output */
void WritePoint(Point P)
/* Menuliskan Point P ke layar dengan format (X,Y) */
{
    printf("(%d,%d)\n", Absis(P), Ordinat(P));
}

/* Validasi Point */
boolean isPointValid(int X, int Y)
/* Menghasilkan true jika X dan Y dapat membentuk point yang valid */
{
    return (X >= 0 && X < COL_CAP && Y >= 0 && Y < ROW_CAP);
}

// boolean isBlock(Point P);
/* Mengirimkan true jika point P merupakan batasan/titik lokasi suatu tempat */
/* Batasan peta ditandai dengan * */
/* Titik lokasi yaitu tempat telepon (T), tempat mixing (M), tempat menggoreng (F), tempat memotong (C), dan tempat merebus (B). */

/* Operasi Point */
void nextPoint(Point *P, int nextX, int nextY)
/* Penggeseran nextX point ke kanan dan nextYpoint kebawah */
{
    if (isPointValid(Absis(*P) + nextX, Ordinat(*P) + nextY))
    {
        Absis(*P) += nextX;
        Ordinat(*P) += nextY;
    }
    else
        printf("Point keluar batas!\n");
}
boolean isAdj(Point P, Point X)
/* Menghasilkan true jika Point P adjacent dengan X*/
{
    int distAbsis = Absis(P) - Absis(X);
    int distOrdinat = Ordinat(P) - Ordinat(X);
    return (distAbsis == 1 || distAbsis == 0 || distAbsis == -1) && (distOrdinat == 1 || distOrdinat == 0 || distOrdinat == -1);
}