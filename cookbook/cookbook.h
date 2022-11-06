#ifndef COOKBOOK_H
#define COOKBOOK_H

#include "../adt/tree/tree.h"

/* Menghasilkan true jika bahan dengan id ada */
boolean hasBahan(int id);

/* Menampilkan resep-resep yang tersedia pada system */
void displayCookbook();

/* Menampilkan resep makanan dengan meninjau treenya */
void displayRecipe(Tree node);

#endif
