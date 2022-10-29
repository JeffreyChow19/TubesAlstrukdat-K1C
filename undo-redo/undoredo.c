#include "undoredo.h"
#include <stdio.h>
#include "../data/data.h"

void undo()
{
    Sim temp;
    pop(&undoStack, &temp);
    push(&redoStack, temp);
    if (isStackEmpty(undoStack))
    {
        printf("Anda belum memulai melakukan command\n");
        push(&undoStack, temp);
        clearStack(&redoStack);
    }
    else
    {
        simulator = InfoTop(undoStack);
    }
}

void redo()
{
    if (!isStackEmpty(redoStack))
    {
        Sim temp;
        pop(&redoStack, &temp);
        push(&undoStack, temp);
        simulator = temp;
    }
    else
    {
        printf("Anda belum melakukan undo setelah command terakhir\n");
    }
}