#include "undoredo.h"
#include <stdio.h>
#include "../data/data.h"
#include "../color/color.h"

boolean isUndo = false;

boolean undo()
{
    if (isStackEmpty(undoStack))
    {
        red(false);
        printf("\nAnda belum memulai melakukan command\n\n");
        reset();
        return false;
    }
    else
    {
        isUndo = true;
        push(&redoStack, simulator);
        pop(&undoStack, &simulator);
        return true;
    }
}

boolean redo()
{
    if (!isStackEmpty(redoStack))
    {
        isUndo = false;
        push(&undoStack, simulator);
        pop(&redoStack, &simulator);
        return true;
    }
    else
    {
        red(false);
        printf("\nAnda belum melakukan undo setelah command terakhir\n\n");
        reset();
        return false;
    }
}