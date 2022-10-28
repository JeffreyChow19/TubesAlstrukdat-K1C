#include "undoredo.h"
#include <stdio.h>

void undo(Sim *sim, Stack *utama, Stack *penampung)
{
    Sim temp;
    pop(utama, &temp);
    push(penampung, temp);
    if (isStackEmpty(*utama))
    {
        printf("Anda belum memulai melakukan command\n");
    }
    else
    {
        *sim = InfoTop(*utama);
    }
}

void redo(Sim *sim, Stack *utama, Stack *penampung)
{
    if (!isStackEmpty(*penampung))
    {
        Sim temp;
        pop(penampung, &temp);
        push(utama, temp);
        *sim = temp;
    }
    else
    {
        printf("Anda belum melakukan undo setelah command terakhir\n");
    }
}