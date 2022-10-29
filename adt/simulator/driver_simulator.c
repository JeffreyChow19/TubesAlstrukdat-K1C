#include "simulator.h"
#include <stdio.h>

int main()
{
    Sim Sim;
    String Name;
    Point Pos;
    setLiteral(&Name, "BNMO");
    CreatePoint(&Pos, 0, 0);

    CreateSim(&Sim, Name, Pos);

    moveSim(&Sim, 'N');
    printf("Posisi simulator sekarang adalah ");
    currPos(Sim);
    printf("\n");
    moveSim(&Sim, 'E');
    printf("Posisi simulator sekarang adalah ");
    currPos(Sim);
    printf("\n");
    moveSim(&Sim, 'S');
    printf("Posisi simulator sekarang adalah ");
    currPos(Sim);
    printf("\n");
    moveSim(&Sim, 'W');
    printf("Posisi simulator sekarang adalah ");
    currPos(Sim);
    printf("\n");

    Makanan A, B, C, D;
    String FNAME, ACT;
    Time Exp, Delv;
    int id = 21;
    setLiteral(&FNAME, "AYAM GORENG");
    setLiteral(&ACT, "FRY");
    CreateTime(&Exp, 0, 5, 0);
    CreateTime(&Delv, 0, 0, 5);
    CreateMakanan(&A, id, FNAME, Exp, ACT, Delv);

    openInv(Sim);               // Inventory kosong
    addFood(&Sim, A);           // Inventory diisi dengan makanan A
    openInv(Sim);               // Inventory terdapat isi, yaitu makanan A
    removeFoodID(&Sim, &B, 21); // Makanan A dihapus dari inventory dan nilainya dimasukkan ke B
    openInv(Sim);               // Inventory kosong

    addFood(&Sim, B);       // Inventory diisi dengan makanan B
    openInv(Sim);           // Inventory berisi makanan B
    removeLast(&Sim, &C);   // Elemen terakhir inventory dihapus (dalam hal ini adalah makanan B), nilai dimasukkan ke C
    printMakananDetails(C); // menampilkan makanan C, C == B == A

    addFood(&Sim, A);
    getFood(Sim, &D, 21);   // Makanan dengan ID 21 dimasukkan ke D
    printMakananDetails(D); // Menampilkan makanan D
}