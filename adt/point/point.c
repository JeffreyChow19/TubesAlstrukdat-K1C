// ADT Sederhana : ADT point
/* ADT Point wajib memiliki koordinat X dan Y. ADT ini digunakan untuk
merepresentasikan lokasi. */

/* Implementasi ADT Point */
#include "point.h"
#include <stdio.h>

/* Primitif */
/* Konstruktor Point*/
void CreatePoint(Point *P, int X, int Y)
{
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

/* Input Output */
void WritePoint(Point P)
{
    printf("(%d,%d)\n", Absis(P), Ordinat(P));
}

/* Validasi Point */
boolean isPointValid(int X, int Y, int colCap, int rowCap)
{
    return (X >= 0 && X <= colCap && Y >= 0 && Y <= rowCap);
}

/* Mengirimkan true jika point P merupakan batasan/titik lokasi suatu tempat */
// boolean isBlock(Point P);

/* Operasi Point */
void nextPoint(Point *P, int nextX, int nextY)
{
    Absis(*P) += nextX;
    Ordinat(*P) += nextY;
}

/* Menghasilkan true jika Point P adjacent dengan X*/
boolean isAdj(Point P, Point X)
{
    int distAbsis = Absis(P) - Absis(X);
    int distOrdinat = Ordinat(P) - Ordinat(X);
    return ((distAbsis == 1 || distAbsis == -1) && distOrdinat == 0) || ((distOrdinat == 1 || distOrdinat == -1) && distAbsis == 0);
}