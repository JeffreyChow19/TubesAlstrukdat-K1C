/* Definisi ADT Priority Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi I */

#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H

#include "../boolean.h"
#include "../makanan/makanan.h"

#define IDX_UNDEF -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

typedef Makanan QElType;

typedef struct
{
        QElType *buffer; /* tabel penyimpan elemen */
        int idxHead;     /* alamat penghapusan */
        int idxTail;     /* alamat penambahan */
        int maxQueue;    /* Max elemen queue */
        char QueueType;  /* Ini Queue untuk jenis apa ?
                            i jika untuk Inventory;
                            d jika untuk Delivery;
                            p jika untuk Process;  */
} PrioQueue;
/* Definisi Queue kosong: idxHead=IDX_UNDEF; idxTail=IDX_UNDEF. */

/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen : */
#define Head(Q) (Q).idxHead
#define Tail(Q) (Q).idxTail
#define InfoHead(Q) (Q).buffer[(Q).idxHead]
#define InfoTail(Q) (Q).buffer[(Q).idxTail]
#define MaxQueue(Q) (Q).maxQueue
#define Elmt(Q, i) (Q).buffer[(i)]
#define QueueType(Q) (Q).QueueType

/* ********* Prototype ********* */

/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean isQueueEmpty(PrioQueue Q);

/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak maxQueue */
boolean isQueueFull(PrioQueue Q);

/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
int queueLength(PrioQueue Q);

/* *** Kreator *** */

/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg maxQueue=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
void CreateQueue(PrioQueue *Q, int Max, char type);

/* *** Destruktor *** */

/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxQueue(Q) diset 0 */
void dealocateQueue(PrioQueue *Q);

/* *** Primitif Enqueue/Dequeue *** */

/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time jenis queue*/
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju";
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
void enqueue(PrioQueue *Q, QElType X);

/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S.; memajukan elemen sisanya;
        Q mungkin kosong */
void dequeue(PrioQueue *Q, QElType *X);

/* Operasi Tambahan */

/* Proses: Menghapus elemen akhir pada Q */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen TAIL pd I.S.; TAIL "mundur";
        Q mungkin kosong */
void removeLast(PrioQueue *Q, QElType *X);

/* Mencari indeks pada Q sesuai ID elemen */
int searchIdx(PrioQueue Q, int id);

/* Menghapus elemen pada indeks ditemukannya ID */
void removeIdx(PrioQueue *Q, QElType *val, int id);

/* Menghapus elemen pada indeks yang diinput */
void removeByIndex(PrioQueue *Q, QElType *val, int idx);

/* Proses: Membentuk salinan simulator */
/* I.S. Q sudah terdefinisi */
/* F.S. Terbentuk salinan simulator Q2 */
void copyQueue(PrioQueue Q, PrioQueue *Q2);

/* Mengecek apakah Q merupakan PrioQueue untuk mengurutkan waktu delivery makanan */
boolean isForDelivery(PrioQueue Q);

/* Mengecek apakah Q merupakan PrioQueue untuk mengurutkan waktu expiry makanan */
boolean isForInventory(PrioQueue Q);

/* Mengecek apakah Q merupakan PrioQueue untuk mengurutkan waktu pengolahan makanan */
boolean isForProcess(PrioQueue Q);

/* Proses: Menambahkan capacity Q sebanyak num */
/* I.S. Q sudah terdefinisi */
/* F.S. Ukuran Q bertambah sebanyak num */
void expandQueue(PrioQueue *Q, int num);

/* Proses: Mengurangi satu menit waktu sesuai jenis PrioQueue tersebut */
/* I.S. Q sudah terdefinisi */
/* F.S. Time pada Makanan berkurang satu menit sesuai jenis PrioQueue dengan kondisi sbb: */
/* Apabila QueueType berjenis 'i' (Inventory), maka yang dikurangi ialah Time pada expiry Makanan; */
/* Apabila QueueType berjenis 'd' (Delivery) atau 'p' (Pengolahan), */
/* maka yang dikurangi ialah Time pada delivery Makanan; */
void reduceAllTime(PrioQueue *Q);

#endif