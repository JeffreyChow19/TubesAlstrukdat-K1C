#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void CreateStack(Stack *S, int max)
{
    (*S).buffer = (ElType *)malloc(max * sizeof(ElType));
    MaxStack(*S) = max;
    IDX_TOP(*S) = IDX_UNDEF;
}

void dealocateStack(Stack *S)
{
    IDX_TOP(*S) = IDX_UNDEF;
    MaxStack(*S) = 0;
    free((*S).buffer);
}

boolean isStackEmpty(Stack S)
{
    return (IDX_TOP(S) == IDX_UNDEF);
}

boolean isStackFull(Stack S)
{
    return (IDX_TOP(S) == MaxStack(S) - 1);
}

void push(Stack *S, ElType state)
{
    if (isStackFull(*S))
    {
        expandStack(S, MaxStack(*S));
    }
    IDX_TOP(*S) += 1;
    InfoTop(*S) = state;
}

void pop(Stack *S, ElType *state)
{
    *state = InfoTop(*S);
    IDX_TOP(*S) -= 1;
}

void expandStack(Stack *S, int num)
{
    MaxStack(*S) += num;
    (*S).buffer = realloc((*S).buffer, MaxStack(*S) * sizeof(ElType));
}

void shrinkStack(Stack *S, int num)
{
    MaxStack(*S) -= num;
    (*S).buffer = realloc((*S).buffer, MaxStack(*S) * sizeof(ElType));
}