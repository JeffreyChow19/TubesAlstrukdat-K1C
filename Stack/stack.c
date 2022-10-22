#include "stack.h"
#include <stdio.h>

void CreateStack(Stack *S)
{
    IDX_TOP(*S) = IDX_UNDEF;
}

boolean isStackEmpty(Stack S)
{
    return (IDX_TOP(S) == IDX_UNDEF);
}

boolean isStackFull(Stack S)
{
    return (IDX_TOP(S) == CAPACITY - 1);
}

void push(Stack *S, ElType state)
{
    IDX_TOP(*S) += 1;
    InfoTop(*S) = state;
}

void pop(Stack *S, ElType *state)
{
    *state = InfoTop(*S);
    IDX_TOP(*S) -= 1;
}