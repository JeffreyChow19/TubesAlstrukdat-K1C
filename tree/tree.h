#ifndef TREE_H
#define TREE_H

#include "../makanan/makanan.h"
#include "../listdin/listdin.h"
#include <stdlib.h>

#ifndef LISTDIN_S
#define LISTDIN_S
/* Definisi elemen dan koleksi objek */
typedef struct node *ElType; /* type elemen list */
typedef int IdxType;
typedef struct listdin
{
  ElType *buffer; /* memori tempat penyimpan elemen (container) */
  int nEff;       /* >=0, banyaknya elemen efektif */
  int capacity;   /* ukuran elemen */
} ListDin;
#endif

typedef struct node *Address;
typedef struct node
{
  Makanan info;
  ListDin children;
} Node;

/* ********** SELEKTOR ********** */
#define INFO(n) (n)->info
#define CHILDREN(n) (n)->children

/* ********** KONSTRUKTOR ********** */
/*
 * Mengembalikan sebuah node baru dengan info = val dan children = list kosong
 */
Address newNode(Makanan val);

/*
 * Mengembalikan node dengan info id tertentu, jika tidak ditemukan mengembalikan NULL
 */
Address findNodeInTree(Address t, int id);

/* Mengembalikan node dengan id yang dicari, deep search ke semua root tree */
Address findNodeInList(ListDin l, int id);

#endif