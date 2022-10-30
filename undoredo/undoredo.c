#include "undoredo.h"
#include <stdio.h>
#include "../data/data.h"

boolean undo()
{
    if (isStackEmpty(undoStack))
    {
        printf("Anda belum memulai melakukan command\n");
        return false;
    }
    else
    {
        push(&redoStack, simulator);
        pop(&undoStack, &simulator);
        return true;
    }
}

boolean redo()
{
    if (!isStackEmpty(redoStack))
    {
        push(&undoStack, simulator);
        pop(&redoStack, &simulator);
        return true;
    }
    else
    {
        printf("Anda belum melakukan undo setelah command terakhir\n");
        return false;
    }
}