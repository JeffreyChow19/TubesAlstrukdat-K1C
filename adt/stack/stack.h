#ifndef STACK_H
#define STACK_H

#include "../boolean.h"
#include "../simulator/simulator.h"

#define IDX_UNDEF -1

typedef Sim ElTypeStack;
typedef struct
{
    ElTypeStack *buffer; /* tabel penyimpan elemen */
    int Top;             /* alamat TOP: elemen puncak */
    int maxStack;        /* Max elemen stack */
} Stack;

/* ********* AKSES (Selektor) ********* */
/* Jika S adalah Stack, maka akses elemen : */
#define IDX_TOP(S) (S).Top
#define InfoTop(S) (S).buffer[(S).Top]
#define MaxStack(S) (S).maxStack

/* *** Konstruktor *** */
void CreateStack(Stack *S, int max);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah S kosong */

/* *** Destruktor *** */
void dealocateStack(Stack *S);
/* Proses: Mengembalikan memori S */
/* I.S. S pernah dialokasi */
/* F.S. S menjadi tidak terdefinisi lagi, MaxStack diset 0, IDX_TOP jadi IDX_UNDEF */

/* ************ Prototype ************ */
boolean isStackEmpty(Stack S);
/* Mengirim true jika S kosong: lihat definisi di atas */
boolean isStackFull(Stack S);
/* Mengirim true jika tabel penampung nilai S stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void push(Stack *S, ElTypeStack state);
/* Menambahkan val sebagai elemen Stack s */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi InfoTop yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void pop(Stack *S, ElTypeStack *state);
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen InfoTop yang lama, IDX_TOP berkurang 1 */

/* ************ Mengubah ukuran Stack ************ */
void expandStack(Stack *S, int num);
/* Proses : Menambahkan MaxStack S sebanyak num */
/* I.S. Stack sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkStack(Stack *S, int num);
/* Proses : Mengurangi MaxStack S sebanyak num */
/* I.S. Stack sudah terdefinisi, ukuran MaxStack > num */
/* F.S. Ukuran Stack berkurang sebanyak num. */

#endif
