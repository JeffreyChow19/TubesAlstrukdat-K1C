#include "matriks.h"
#include <stdio.h>
#include "../string/string.h"
#include "../liststring/liststring.h"
#include "../mesinkata/wordmachine.h"
#include "../../error/error.h"
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

boolean isIdxEffMat(Matrix m, IdxType i, IdxType j)
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

void readMatrix(Matrix *m, char *filename, Sim *s)
{
    /* I.S. filename valid, m sembarang */
    /* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol, nRow dan nCol dicari dari file */
    /* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
    /* Selanjutnya membaca nilai elemen per baris dan kolom dari file:filename dan memindahkannya ke matriks, dan jika membaca # dari file akan diganti dengan ' '*/

    STARTWORD(fopen(filename, "r"), true);

    boolean firstLine = true;
    boolean isRow = true;

    int nRow = wordToInt(currentWord);
    ADVWORD();
    int nCol = wordToInt(currentWord);

    createMatrix(nRow, nCol, m);

    int i = 0;
    int j = 0;

    ADVWORD();

    for (i = 0; i < nRow; i++)
    {
        if (endWord)
            throwError("File konfigurasi peta tidak valid\nJumlah baris lebih sedikit daripada yang dispesifikasikan\n");
        if (currentWord.Length != nCol)
        {
            throwError("File konfigurasi peta tidak valid\nTerdapat jumlah kolom tidak sesuai dengan yang dispesifikasikan\n");
        }
        for (j = 0; j < nCol; j++)
        {
            if (currentWord.TabWord[j] == '#' || currentWord.TabWord[j] == 'S')
            {
                if (currentWord.TabWord[j] == 'S')
                {
                    Absis(Pos(*s)) = j;
                    Ordinat(Pos(*s)) = i;
                }
                ELMTMat(*m, i, j) = ' ';
            }
            else
            {
                ELMTMat(*m, i, j) = currentWord.TabWord[j];
            }
        }

        ADVWORD();
    }
    if (!endWord)
    {
        throwError("File konfigurasi peta tidak valid\nJumlah baris lebih banyak daripada yang dispesifikasikan\n");
    }
}

void displayMatrix(Matrix m, Point simPoint)
{
    /* I.S. m terdefinisi */
    /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, matriks diberi border berupa '*'*/
    /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
    int i, j;

    for (i = 0; i < m.colEff + 2; i++)
    {
        printf("* ");
    }
    printf("\n");

    for (i = 0; i < m.rowEff; i++)
    {
        printf("* ");
        for (j = 0; j < m.colEff; j++)
        {
            if (j == Absis(simPoint) && i == Ordinat(simPoint))
                printf("S ");
            else
                printf("%c ", ELMTMat(m, i, j));
        }
        printf("*\n");
    }

    for (i = 0; i < m.colEff + 2; i++)
    {
        printf("* ");
    }
    printf("\n");
}

boolean isActionAdj(Matrix m, Point simPoint, char action)
{
    int i, j;

    for (i = Ordinat(simPoint) - 1; i <= Ordinat(simPoint) + 1; i++)
    {
        for (j = Absis(simPoint) - 1; j <= Absis(simPoint) + 1; j++)
        {
            if (!(i == Ordinat(simPoint) && j == Absis(simPoint)) && isIdxEffMat(m, i, j) && ELMTMat(m, i, j) == action)
            {
                return true;
            }
        }
    }

    return false;
}