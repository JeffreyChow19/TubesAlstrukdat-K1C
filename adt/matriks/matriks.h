#ifndef MATRIX_H
#define MATRIX_H

#include "../boolean.h"
#include "../string/string.h"
#include "../liststring/liststring.h"
#include "../mesinkarakter/charmachine.h"
#include "../point/point.h"

#define ROW_CAP 100
#define COL_CAP 100

/* Index baris, kolom */
typedef int IdxType;
typedef char MElType;
typedef struct
{
    MElType mem[ROW_CAP][COL_CAP];
    int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
    int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;

/* Selector */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMTMat(M, i, j) (M).mem[(i)][(j)]

/* Constructor */
/* Inisialisasi matrix */
void createMatrix(int nRows, int nCols, Matrix *m);

/*Mengirimkan true jika i, j adalah index yang valid untuk matriks apapun*/
boolean isMatrixIdxValid(int i, int j);

/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxRow(Matrix m);
/* Mengirimkan Index kolom terbesar m */
IdxType getLastIdxCol(Matrix m);
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
boolean isIdxEffMat(Matrix m, IdxType i, IdxType j);

/* Melakukan assignment mOut <- mIn */
void copyMatrix(Matrix mIn, Matrix *mOut);

/* I.S. filename valid, m sembarang*/
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol, nRow dan nCol dicari dari file */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom dari file:filename dan memindahkannya ke matriks*/
void readMatrix(Matrix *m, char *filename, Point *simPoint);

/* I.S. m dan s terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, matriks diberi border berupa '*' dan jika membaca # dari file akan diganti dengan ' '*/
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
void displayMatrix(Matrix m, Point simPoint);

/* mengirimkan true jika adjacent dari simPoint adalah action, vice versa.*/
boolean isActionAdj(Matrix m, Point simPoint, char action);

#endif