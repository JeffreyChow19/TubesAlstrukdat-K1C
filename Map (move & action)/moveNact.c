#include "moveNact.h"

boolean isBlocked(Sim S, char dir, Matrix M)
{
    int X, Y;
    X = Absis(Pos(S));
    Y = Ordinat(Pos(S));
    if (dir == 'E')
    {
        Y += 1;
        if (ELMTMat(M, X, Y) == 'X' || ELMTMat(M, X, Y) == 'T' || ELMTMat(M, X, Y) == 'M' || ELMTMat(M, X, Y) == 'C' || ELMTMat(M, X, Y) == 'F' || ELMTMat(M, X, Y) == 'B' || !isIdxEff(M, X, Y))
            return true;
        else
            return false;
    }  
    else if (dir == 'W')
    {
        Y += -1;
        if (ELMTMat(M, X, Y) == 'X' || ELMTMat(M, X, Y) == 'T' || ELMTMat(M, X, Y) == 'M' || ELMTMat(M, X, Y) == 'C' || ELMTMat(M, X, Y) == 'F' || ELMTMat(M, X, Y) == 'B' || !isIdxEff(M, X, Y))
            return true;
        else
            return false;
    }
    else if (dir == 'N')
    {
        X += -1;
        if (ELMTMat(M, X, Y) == 'X' || ELMTMat(M, X, Y) == 'T' || ELMTMat(M, X, Y) == 'M' || ELMTMat(M, X, Y) == 'C' || ELMTMat(M, X, Y) == 'F' || ELMTMat(M, X, Y) == 'B' || !isIdxEff(M, X, Y))
            return true;
        else
            return false;
    }
    else if (dir == 'S')
    {
        X += 1;
        if (ELMTMat(M, X, Y) == 'X' || ELMTMat(M, X, Y) == 'T' || ELMTMat(M, X, Y) == 'M' || ELMTMat(M, X, Y) == 'C' || ELMTMat(M, X, Y) == 'F' || ELMTMat(M, X, Y) == 'B' || !isIdxEff(M, X, Y))
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
        Y += 1;
        if (!isIdxEff(M, X, Y))
            return true;
        else
        {
            return false;
        }
    }
    else if (dir == 'W')
    {
        Y -= 1;
        if (!isIdxEff(M, X, Y))
            return true;
        else
            return false;
    }
    else if (dir == 'N')
    {
        X -= 1;
        if (!isIdxEff(M, X, Y))
            return true;
        else
            return false;
    }
    else if (dir == 'S')
    {
        X += 1;
        if (!isIdxEff(M, X, Y))
            return true;
        else
            return false;
    }
}

void setPos(Sim *S, char dir, Matrix M)
{
    if (!isBlocked(*S, dir, M) && !isOutOfBound(*S, dir, M))
    {
        moveSim(S, dir);
    }
    else if (isBlocked(*S, dir, M) && !isOutOfBound(*S, dir, M))
    {
        printf("Simulator tidak dapat berpindah karena terhalangi!\n");
    }
    else if (!isBlocked(*S, dir, M) && isOutOfBound(*S, dir, M))
    {
        printf("Simulator tidak dapat berpindah karena akan keluar map!\n");
    }
}

void action(Sim S, char act, Matrix M)
{
    /* Harus ada point tiap lokasi baru bisa di isAdj trus eksekusi command di cook */
}