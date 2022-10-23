/* Definisi ADT Priority Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi I */

#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H

#include "../boolean.h"
#include "../makanan/makanan.h"

#define Nil 0
/* Konstanta untuk mendefinisikan address tak terdefinisi */

typedef Makanan ElType;

typedef struct
{
    ElType *buffer; /* tabel penyimpan elemen */
    int idxHead;    /* alamat penghapusan */
    int idxTail;    /* alamat penambahan */
    int MaxEl;      /* Max elemen queue */
} PrioQueue;
/* Definisi Queue kosong: idxHead=Nil; idxTail=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen : */
#define Head(Q) (Q).idxHead
#define Tail(Q) (Q).idxTail
#define InfoHead(Q) (Q).buffer[(Q).idxHead]
#define InfoTail(Q) (Q).buffer[(Q).idxTail]
#define MaxEl(Q) (Q).MaxEl
#define Elmt(Q, i) (Q).buffer[(i)]

/* ********* Prototype ********* */
boolean isQueueEmpty(PrioQueue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean isQueueFull(PrioQueue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int queueLength(PrioQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateQueue(PrioQueue *Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueue *Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Enqueue/Dequeue *** */
void enqueue(PrioQueue *Q, ElType X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time expiry*/
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju";
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */

void dequeue(PrioQueue *Q, ElType *X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S.; memajukan elemen sisanya;
        Q mungkin kosong */

/* Operasi Tambahan */
void removeLast(PrioQueue *Q, ElType *X);
/* Proses: Menghapus elemen akhir pada Q */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen TAIL pd I.S.; TAIL "mundur";
        Q mungkin kosong */

int searchIdx(PrioQueue Q, int id);
/* Mencari indeks pada Q sesuai ID elemen */

void removeIdx(PrioQueue *Q, int id);
/* Proses: Menghapus elemen pada indeks ditemukannya ID */

#endif