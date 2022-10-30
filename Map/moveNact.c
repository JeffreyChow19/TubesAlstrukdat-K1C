#include "moveNact.h"

boolean isBlocked(Sim S, char dir, Matrix M)
{
    int X, Y;
    X = Absis(Pos(S));
    Y = Ordinat(Pos(S));
    if (dir == 'E')
    {
        X += 1;
        if (ELMTMat(M, Y, X) == 'X' || ELMTMat(M, Y, X) == 'T' || ELMTMat(M, Y, X) == 'M' || ELMTMat(M, Y, X) == 'C' || ELMTMat(M, Y, X) == 'F' || ELMTMat(M, Y, X) == 'B' || !isIdxEffMat(M, Y, X))
            return true;
        else
            return false;
    }
    else if (dir == 'W')
    {
        X += -1;
        if (ELMTMat(M, Y, X) == 'X' || ELMTMat(M, Y, X) == 'T' || ELMTMat(M, Y, X) == 'M' || ELMTMat(M, Y, X) == 'C' || ELMTMat(M, Y, X) == 'F' || ELMTMat(M, Y, X) == 'B' || !isIdxEffMat(M, Y, X))
            return true;
        else
            return false;
    }
    else if (dir == 'N')
    {
        Y += -1;
        if (ELMTMat(M, Y, X) == 'X' || ELMTMat(M, Y, X) == 'T' || ELMTMat(M, Y, X) == 'M' || ELMTMat(M, Y, X) == 'C' || ELMTMat(M, Y, X) == 'F' || ELMTMat(M, Y, X) == 'B' || !isIdxEffMat(M, Y, X))
            return true;
        else
            return false;
    }
    else if (dir == 'S')
    {
        Y += 1;
        if (ELMTMat(M, Y, X) == 'X' || ELMTMat(M, Y, X) == 'T' || ELMTMat(M, Y, X) == 'M' || ELMTMat(M, Y, X) == 'C' || ELMTMat(M, Y, X) == 'F' || ELMTMat(M, Y, X) == 'B' || !isIdxEffMat(M, Y, X))
            return true;
        else
            return false;
    }
}

boolean isOutOfBound(Sim S, char dir, Matrix M)
{
    int X, Y;
    X = Absis(Pos(S));
    Y = Ordinat(Pos(S));
    if (dir == 'E')
    {
        X += 1;
        if (!isIdxEffMat(M, Y, X))
            return true;
        else
        {
            return false;
        }
    }
    else if (dir == 'W')
    {
        X -= 1;
        if (!isIdxEffMat(M, Y, X))
            return true;
        else
            return false;
    }
    else if (dir == 'N')
    {
        Y -= 1;
        if (!isIdxEffMat(M, Y, X))
            return true;
        else
            return false;
    }
    else if (dir == 'S')
    {
        Y += 1;
        if (!isIdxEffMat(M, Y, X))
            return true;
        else
            return false;
    }
}

boolean setPos(Sim *S, char dir, Matrix M)
{
    if (!isOutOfBound(*S, dir, M))
    {
        if (!isBlocked(*S, dir, M))
        {
            moveSim(S, dir);
            return true;
        }
        else
        {
            printf("Simulator tidak dapat berpindah karena terhalangi!\n");
            return false;
        }
    }
    else
    {
        printf("Simulator tidak dapat berpindah karena akan keluar map!\n");
        return false;
    }
}