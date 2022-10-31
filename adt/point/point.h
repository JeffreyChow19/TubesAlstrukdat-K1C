// ADT Sederhana : ADT point
/* ADT Point wajib memiliki koordinat X dan Y. ADT ini digunakan untuk
merepresentasikan lokasi. */

/* Header ADT Point */

#ifndef POINT_H
#define POINT_H

typedef struct
{
    int X; /* Absis */
    int Y; /* Ordinat */
} Point;

/********** Selektor Point **********/
#define Absis(P) (P).X
#define Ordinat(P) (P).Y

#include "../boolean.h"

/********** Primitif **********/
/* Konstruktor Point*/
/* Membuat sebuah Point dengan komponen Absis X dan Ordinat Y */
/* I.S. Point P sembarang, X dan Y terdefinisi dan merupakan komponen point yang valid */
/* F.S. Point P terdefinisi dengan komponen Absis X dan ordinat Y */
void CreatePoint(Point *P, int X, int Y);

/********** Input Output **********/
/* Menuliskan Point P ke layar dengan format (X,Y) */
/* I.S. Point P terdefinisi */
/* F.S. Point P tertampil di layar dengan format (Absis,Ordinat) */
void WritePoint(Point P);

/********** Validasi Time **********/
/* Menerima input komponen Absis X, ordinat Y, jumlah baris matriks rowCap, dan jumlah kolom matriks colCap */
/* Menghasilkan true jika X dan Y dapat membentuk point yang valid */
/* Point valid : 0 <= X < colCap dan 0 <= Y < rowCap */
boolean isPointValid(int X, int Y, int colCap, int rowCap);

/* Menerima input point P */
/* dan Mengirimkan true jika point P merupakan batasan/titik lokasi suatu tempat */
/* Batasan peta ditandai dengan * */
/* Titik lokasi yaitu tempat telepon (T), tempat mixing (M), tempat menggoreng (F), tempat memotong (C), dan tempat merebus (B). */
// boolean isBlock(Point P);

/********** Operasi Point **********/
/* Penggeseran nextX point ke kanan dan nextYpoint kebawah */
/* I.S. Point P, banyak penggeseran absis nextX, dan banyak penggeseran ordinat NextY terdefinisi */
/* F.S. Point P yang telah dilakukan penggeseran sebanyak NextX secara horizontal dan NextY secara vertikal */
/*      dengan (X += nextX) dan (Y += nextY) merupakan point yang valid */
void nextPoint(Point *P, int nextX, int nextY);

/* Menerima input Point P dan Point X */
/* kemudian Menghasilkan true jika Point P adjacent dengan X*/
boolean isAdj(Point P, Point X);

#endif