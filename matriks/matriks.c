#include "matriks.h"
#include <stdio.h>
#include "../string/string.h"
#include "../liststring/liststring.h"
#include "../mesinkarakter/charmachine.h"
#include <stdlib.h>

/* Constructor */
void createMatrix(int nRows, int nCols, Matrix *m)
{
    m->colEff = nCols;
    m->rowEff = nRows;
}

boolean isMatrixIdxValid(int i, int j)
{
    /* Mengirimkan true jika i, j adalah index yang valid untuk matriks apapun*/
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

IdxType getLastIdxRow(Matrix m)
{
    /* Mengirimkan Index baris terbesar m */
    return (ROW_EFF(m) - 1);
}

IdxType getLastIdxCol(Matrix m)
{
    /* Mengirimkan Index kolom terbesar m */
    return (COL_EFF(m) - 1);
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j)
{
    /* Mengirimkan true jika i, j adalah Index efektif bagi m */
    return (i >= 0 && i < ROW_EFF(m) && j >= 0 && j < COL_EFF(m));
}

void copyMatrix(Matrix mIn, Matrix *mOut)
{
    /* Melakukan assignment mOut <- mIn */
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);

    int i, j;
    for (i = 0; i < ROW_EFF(*mOut); i++)
    {

        for (j = 0; j < COL_EFF(*mOut); j++)
        {
            ELMTMat(*mOut, i, j) = ELMTMat(mIn, i, j);
        }
    }
}

void readMatrix(Matrix *m, String filename)
{
    /* I.S. filename valid, m sembarang */
    /* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol, nRow dan nCol dicari dari file */
    /* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
    /* Selanjutnya membaca nilai elemen per baris dan kolom dari file:filename dan memindahkannya ke matriks, dan jika membaca # dari file akan diganti dengan ' '*/

    LString l;
    ReadFile(filename, &l);

    int nRow = 0;
    int nCol = 0;

    boolean isRow = true;

    /* find nRow and nCols elemen */
    String toSearch;
    setLiteral(&toSearch, SBUFFER(ELMTLString(l, 0)));
    int len = LENGTH(toSearch);

    int i, j;
    for (i = 0; i < len - 1; i++)
    {
        if (CHAR(toSearch, i) != ' ')
        {
            if (isRow)
            {
                nRow = (nRow * 10) + ((int)(CHAR(toSearch, i) - 48));
            }
            else
            {
                nCol = (nCol * 10) + ((int)(CHAR(toSearch, i) - 48));
            }
        }
        else
        {
            isRow = false;
        }
    }

    /* pengisian matriks dan inisialisasi matriks */

    createMatrix(nRow, nCol, m);

    for (i = 0; i < nRow; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            if (CHAR(l.buffer[i + 1], j) != '#')
            {
                ELMTMat(*m, i, j) = CHAR(l.buffer[i + 1], j);
            }
            else
            {
                ELMTMat(*m, i, j) = ' ';
            }
        }
    }
}

void displayMatrix(Matrix m)
{
    /* I.S. m terdefinisi */
    /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, matriks diberi border berupa '*'*/
    /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
    int i, j;

    for (i = 0; i < m.colEff + 2; i++)
    {
        printf("*");
    }
    printf("\n");

    for (i = 0; i < m.rowEff; i++)
    {
        printf("*");
        for (j = 0; j < m.colEff; j++)
        {
            printf("%c", ELMTMat(m, i, j));
        }
        printf("*\n");
    }

    for (i = 0; i < m.colEff + 2; i++)
    {
        printf("*");
    }
    printf("\n");
}
