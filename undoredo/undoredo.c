#include "undoredo.h"
#include <stdio.h>
#include "../data/data.h"

void undo()
{
    if (isStackEmpty(undoStack))
    {
        printf("Anda belum memulai melakukan command\n");
    }
    else
    {
        push(&redoStack, simulator);
        pop(&undoStack, &simulator);
    }
}

void redo()
{
    if (!isStackEmpty(redoStack))
    {
        push(&undoStack, simulator);
        pop(&redoStack, &simulator);
    }
    else
    {
        printf("Anda belum melakukan undo setelah command terakhir\n");
    }
}