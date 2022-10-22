#ifndef STACK_H
#define STACK_H

#include "../boolean.h"

#define IDX_UNDEF -1
#define CAPACITY 100

typedef int ElType; // Masih perlu diubah
typedef struct
{
    ElType buffer[CAPACITY]; /* tabel penyimpan elemen */
    int Top;                 /* alamat TOP: elemen puncak */
} Stack;

/* ********* AKSES (Selektor) ********* */
/* Jika S adalah Stack, maka akses elemen : */
#define IDX_TOP(S) (S).Top
#define InfoTop(S) (S).buffer[(S).Top]

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah S kosong */

/* ************ Prototype ************ */
boolean isStackEmpty(Stack S);
/* Mengirim true jika S kosong: lihat definisi di atas */
boolean isStackFull(Stack S);
/* Mengirim true jika tabel penampung nilai S stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void push(Stack *S, ElType state);
/* Menambahkan val sebagai elemen Stack s */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi InfoTop yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void pop(Stack *S, ElType *state);
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen InfoTop yang lama, IDX_TOP berkurang 1 */

#endif
