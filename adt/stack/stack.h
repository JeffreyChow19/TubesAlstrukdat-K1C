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
/* I.S. S sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah S kosong */
void CreateStack(Stack *S, int max);

/* *** Destruktor *** */
/* Proses: Mengembalikan memori S */
/* I.S. S pernah dialokasi */
/* F.S. S menjadi tidak terdefinisi lagi, MaxStack diset 0, IDX_TOP jadi IDX_UNDEF */
void dealocateStack(Stack *S);

/* ************ Prototype ************ */

/* Mengirim true jika S kosong: lihat definisi di atas */
boolean isStackEmpty(Stack S);

/* Mengirim true jika tabel penampung nilai S stack penuh */
boolean isStackFull(Stack S);

/* ************ Menambahkan sebuah elemen ke Stack ************ */
/* Menambahkan val sebagai elemen Stack s */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi InfoTop yang baru, IDX_TOP bertambah 1 */
void push(Stack *S, ElTypeStack state);

/* ************ Menghapus sebuah elemen Stack ************ */
/* Menghapus val dari Stack S */
/* I.S. S tidak mungkin kosong */
/* F.S. val adalah nilai elemen InfoTop yang lama, IDX_TOP berkurang 1 */
void pop(Stack *S, ElTypeStack *state);

/* ************ Mengubah ukuran Stack ************ */

/* Proses : Menambahkan MaxStack S sebanyak num */
/* I.S. Stack sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
void expandStack(Stack *S, int num);

/* Proses : Mengurangi MaxStack S sebanyak num */
/* I.S. Stack sudah terdefinisi, ukuran MaxStack > num */
/* F.S. Ukuran Stack berkurang sebanyak num. */
void shrinkStack(Stack *S, int num);

/* Operasi Tambahan */

/* Proses : Mengosongkan Stack S dengan cara mengeluarkan dan meng-dealokasi semua elemen Simulator */
/* I.S. S sudah terdefinisi */
/* F.S. S menjadi kosong */
void clearStack(Stack *S);

#endif
