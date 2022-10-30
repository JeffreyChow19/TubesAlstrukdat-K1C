#include "liststatik.h"
#include "../adt/makanan/makanan.h"
#include <stdio.h>


int main()
{
    ListStatik l;
    Makanan A, B, C, D;

    String FNAME, ACT;
    Time Exp, Delv;
    int id = 21;
    setLiteral(&FNAME, "AYAM GORENG");
    setLiteral(&ACT, "FRY");
    CreateTime(&Exp, 0, 5, 0);
    CreateTime(&Delv, 0, 0, 5);
    CreateMakanan(&A, id, FNAME, Exp, ACT, Delv);

    /* Menginisiasi list */
    CreateListStatik(&l);

    /* Mengisi list */
    insertLast(&l, A);
    insertLast(&l, A);
    insertLast(&l, A);

    /* Selektor */
    int length = listLength(l);
    printf("panjang list : %d\n", length);

    IdxType idx = getFirstIdx(l);
    printf("idx pertama : %d\n", idx);

    idx = getLastIdx(l);
    printf("idx terakhir : %d\n", idx);

    /* test indeks */
    printf("idx valid : %d\n", isIdxValid(l, 200)); /* False */
    printf("idx valid : %d\n", isIdxValid(l, 10)); /* True */

    printf("idx eff : %d\n", isIdxEff(l, 10)); /* False */
    printf("idx eff ; %d\n", isIdxEff(l, 1)); /* True */

    /* Test Kosong */
    printf("Kosong? %d\n", isEmpty(l)); /* False */

    /* Searching */
    idx = indexOf(l, 21);
    printf("idx id %d : %d\n", id, idx);

    /* Menghapus elemen */
    deleteId(&l, &B, 21);
    printMakananDetails(B); /* Makanan dengan id 21 */

    deleteLast(&l, &C);
    printMakananDetails(C); /* Makanan di idx last */

    deleteLast(&l, &D);
    printMakananDetails(D); /* Makanan terakhir di list */

    /* Test kosong */
    printf("Kosong? %d\n", isEmpty(l)); /* True */
    printf("Full? %d\n", isFull(l)); /* False */

    return 0;
}