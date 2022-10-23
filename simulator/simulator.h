#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../string/string.h"
#include "../makanan/makanan.h"
#include "../point/point.h"
#include "../Queue/prioqueue.h"

typedef struct 
{
    String Name;
    Point Pos;
    PrioQueue Inv;
} Sim;

/* ********** SELEKTOR ********** */
#define Name(S) (S).Name
#define Pos(S) (S).Pos
#define Inv(S) (S).Inv
#define Food(S, i) (S).Inv.buffer[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : membuat simulator*/
/* I.S. S sembarang */
/* F.S. Terbentuk Simulator dengan nama, posisi terdefinisi dan Inv kosong*/
void CreateSim(Sim *S, String Name, Point Pos);

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* Mendapatkan makanan dengan ID tertentu */
void getFood(Sim S, Makanan *val, int id);

/* ********** MERUBAH POSISI ********** */
/* *** Merubah posisi simulator berdasarkan arah mata angin *** */
/* I.S. Posisi S terdefinisi dan valid */
/* F.S. Posisi S bergeser sesuai dir yang diberikan */
void moveSim(Sim *S, String dir);

/* ********** MENAMBAH MAKANAN ********** */
/* *** Menambahkan makanan pada Inv *** */
/* Proses: Menambahkan val sebagai MAKANAN terakhir Inv */
/* I.S. Inv boleh kosong, tetapi tidak penuh */
/* F.S. val adalah MAKANAN terakhir Inv yang baru */
void addFood(Sim *S, Makanan val);

/* ********** MENGHAPUS MAKANAN ********** */
/* *** Menghapus MAKANAN dengan id tertentu *** */
/* Proses : Menghapus MAKANAN pada index idx List */
/* I.S. Inv tidak kosong, id valid di Inv */
/* F.S. val adalah nilai MAKANAN dengan id, id sebelum penghapusan, */
/*      Banyaknya MAKANAN List berkurang satu */
/*      Inv l mungkin menjadi kosong */
void removeFoodID(Sim *S, Makanan *val, int id);

/* *** Menghapus MAKANAN terakhir *** */
/* Proses : Menghapus MAKANAN terakhir List */
/* I.S. Inv tidak kosong */
/* F.S. val adalah nilai MAKANAN terakhir Inv sebelum penghapusan, */
/*      Banyaknya MAKANAN Inv berkurang satu */
/*      Inv l mungkin menjadi kosong */
void removeFoodLast(Sim *S, Makanan *val);

/* ********** DISPLAY OUTPUT ********** */
/* *** Menampilkan inv dari simulator *** */
/* I.S. Inv bisa kosong */
/* F.S. Jika Inv kosong, pesan "Inventory kosong" dimunculkan,
        jika tidak, semua item di inventory akan ditampilkan.
*/
void openInv(Sim S);

#endif