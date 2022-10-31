#include "stack.h"
#include <stdio.h>

// gcc driverstack.c stack.c ../simulator/simulator.c ../string/string.c ../makanan/makanan.c ../point/point.c ../waktu/time.c ../queue/prioqueue.c ../kulkas/kulkas.c ../liststring/liststring.c ../matriks/matriks.c ../mesinkata/wordmachine.c ../mesinkarakter/charmachine.c ../../color/color.c ../../error/error.c

int main()
{
    Stack S;
    CreateStack(&S, 10);

    Sim sim, copy;
    String Name;
    Point Pos;
    CreateEmptyString(&Name, 10);
    setLiteral(&Name, "Driver");
    CreatePoint(&Pos, 1, 1);
    CreateSim(&sim, Name, Pos);
    CreateSim(&copy, Name, Pos); // sebagai penyimpan keadaan awal simulator

    // Proses pindah lokasi
    moveSim(&sim, 'N');
    push(&S, sim);

    moveSim(&sim, 'E');
    push(&S, sim);

    moveSim(&sim, 'S');
    push(&S, sim);

    moveSim(&sim, 'W');
    push(&S, sim);

    // Proses Pengisian Inventory
    Time exp, del;
    Point size;

    // Add A
    Makanan A;
    String name1, act1;
    CreateEmptyString(&name1, 10);
    CreateEmptyString(&act1, 10);
    setLiteral(&name1, "Ayam");
    setLiteral(&act1, "CHOP");
    CreateTime(&exp, 0, 2, 0);
    CreateTime(&del, 0, 0, 4);
    CreatePoint(&size, 5, 4);
    CreateMakanan(&A, 2, name1, exp, act1, del, size);
    addFood(&sim, A);
    push(&S, sim);

    // Add B
    Makanan B;
    String name2, act2;
    CreateEmptyString(&name2, 10);
    CreateEmptyString(&act2, 10);
    setLiteral(&name2, "Cabe");
    setLiteral(&act2, "MIX");
    CreateTime(&exp, 0, 5, 0);
    CreateTime(&del, 0, 0, 1);
    CreatePoint(&size, 2, 3);
    CreateMakanan(&B, 4, name2, exp, act2, del, size);
    addFood(&sim, B);
    push(&S, sim);

    // Membaca "history" simulator
    int idx = IDX_TOP(S) + 1;
    while (!isStackEmpty(S))
    {
        printf("------------------------------------\n");
        Sim history;
        pop(&S, &history);
        printf("Proses %d)\n\nPosisi simulator ", idx);
        currPos(history);
        openInv(history);
        idx -= 1;
    }
    printf("------------------------------------\n");
    printf("Keadaan Awal\n\nPosisi simulator ");
    currPos(copy);
    openInv(copy);

    dealocateSim(&sim); // Proses terakhir & selesai

    return 0;
}