// ADT Sederhana : ADT point
/* ADT Point wajib memiliki koordinat X dan Y. ADT ini digunakan untuk
merepresentasikan lokasi. */

/* Header ADT Point */

#ifndef POINT_H
#define POINT_H

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 15
#define COL_CAP 15

typedef struct
{
    int X; /* Absis */
    int Y; /* Ordinat */
} Point;

/* Selektor Point */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y

#include "boolean.h"

/* Primitif */
/* Konstruktor Point*/
void CreatePoint(Point *P, int X, int Y);
/* Membuat sebuah Point dengan komponen Absis X dan Ordinat Y */

/* Input Output */
// void ReadPoint(Point *P); (perlu kah?)
/* Membaca nilai absis dan ordinat Point P */
void WritePoint(Point P);
/* Menuliskan Point P ke layar dengan format (X,Y) */

/* Validasi Time */
boolean isPointValid(int X, int Y);
/* Menghasilkan true jika X dan Y dapat membentuk point yang valid */

// boolean isBlock(Point P);
/* Mengirimkan true jika point P merupakan batasan/titik lokasi suatu tempat */
/* Batasan peta ditandai dengan * */
/* Titik lokasi yaitu tempat telepon (T), tempat mixing (M), tempat menggoreng (F), tempat memotong (C), dan tempat merebus (B). */

/* Operasi Point */
void nextPoint(Point *P, int nextX, int nextY);
/* Penggeseran nextX point ke kanan dan nextYpoint kebawah */
boolean isAdj(Point P, Point X);
/* Menghasilkan true jika Point P adjacent dengan X*/

#endif