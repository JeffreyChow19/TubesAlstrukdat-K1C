#ifndef WORD_H
#define WORD_H

#define NMax 50

typedef struct
{
  char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
  int Length;
} Word;

#endif