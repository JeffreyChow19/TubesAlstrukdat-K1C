#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../string/string.h"
#include "../makanan/makanan.h"
#include "../point/point.h"
#include "../queue/prioqueue.h"

typedef struct
{
    String Name;
    Point Pos;
    Time Clock;
    PrioQueue Inv;
    PrioQueue Delv;
} Sim;

/* ********** SELEKTOR ********** */
#define Name(S) (S).Name
#define Pos(S) (S).Pos
#define Clock(S) (S).Clock
#define Inv(S) (S).Inv
#define FoodInv(S, i) (S).Inv.buffer[(i)]
#define Delv(S) (S).Delv
#define FoodDelv(S, i) (S).Delv.buffer[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : membuat simulator*/
/* I.S. S sembarang */
/* F.S. Terbentuk Simulator dengan nama, posisi terdefinisi dan Inv kosong*/
void CreateSim(Sim *S, String Name, Point Pos);

/* Menyalin Simulator */
/* I.S. Simulator terdefinisi */
/* F.S. Terbentuk salinan simulator */
void copySim(Sim S, Sim *SC);

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* Mendapatkan makanan dengan ID tertentu */
void getFood(Sim S, Makanan *val, int id);

/* ********** MERUBAH POSISI ********** */
/* *** Merubah posisi simulator berdasarkan arah mata angin *** */
/* I.S. Posisi S terdefinisi dan valid */
/* F.S. Posisi S bergeser sesuai dir yang diberikan */
void moveSim(Sim *S, char dir);

/* ********** MERUBAH WAKTU ********** */
/* *** Menambahkan waktu pada simulator *** */
/* I.S. Waktu S terdefinisi dan dd, hh, mm adalah waktu yang ingin ditambahkan */
/* F.S. Waktu pada S bertambah sesuai lama waktu yang diberikan */
void addTime(Sim *S, int dd, int hh, int mm);

/* *** Mengurangkan waktu pada simulator *** */
/* I.S. Waktu S terdefinisi dan dd, hh, mm adalah waktu yang ingin dikurangkan */
/* F.S. Waktu pada S berkurang sesuai lama waktu yang diberikan */
void removeTime(Sim *S, int dd, int hh, int mm);

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

/* *** Menghapus makanan jika sudah expired *** */
/* I.S. Inv tidak kosong */
/* F.S. jika head queue memiliki expiry <= 0, dihapus */
void removeExp(Sim *S, Makanan *val);

/* *** Menghapus makanan jika sudah sampai *** */
/* I.S. Delv tidak kosong */
/* F.S. jika head queue memiliki delivery <= 0, dihapus */
void removeDelv(Sim *S, Makanan *val);

/* ********** DISPLAY OUTPUT ********** */
/* *** Menampilkan inv dari simulator *** */
/* I.S. Inv bisa kosong */
/* F.S. Jika Inv kosong, pesan "Inventory kosong" dimunculkan,
        jika tidak, semua item di inventory akan ditampilkan.
*/
void openInv(Sim S);

/* *** Menampilkan delivery list dari simulator *** */
/* I.S. Delv bisa kosong */
/* F.S. Jika Delv kosong, pesan "Delivery list kosong" dimunculkan,
        jika tidak, semua item di delivery list akan ditampilkan.
*/
void openDelv(Sim S);

/* *** Menampilkan posisi simulator *** */
/* I.S. Posisi terdefinisi */
/* F.S. Koordinat posisi simulator ditampilkan di layar*/
void currPos(Sim S);

/* *** Menampilkan waktu simulator *** */
/* I.S. Waktu terdefinisi */
/* F.S. Waktu simulator ditampilkan di layar */
void currTime(Sim S);

#endif