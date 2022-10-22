#ifndef TREE_H
#define TREE_H

#include "../makanan/makanan.h"
#include "../listdin/listdin.h"
#include <stdlib.h>

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