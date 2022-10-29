/* Definisi Word Machine: Model Akuisisi Versi I */

#include "../boolean.h"
#include "../mesinkarakter/charmachine.h"
#include "wordmachine.h"
#include <stdio.h>

boolean endWord;
Word currentWord;
boolean isNewLine;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : (currentChar ≠ BLANK dan currentChar != NEWLINE) atau currentChar = MARK */
    isNewLine = false;
    while (currentChar == BLANK || (currentChar == NEWLINE && !EOP))
    {
        if (currentChar == NEWLINE && !EOP)
        {
            isNewLine = true;
        }
        ADV();
    }
}

void IgnoreWords()
{
    while (!endWord)
        ADVWORD();
}

void STARTWORD(FILE *input, boolean file)
{
    /* I.S. : currentChar sembarang
       F.S. : EndWord = true, dan currentChar = MARK;
              atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START(input, file);
    IgnoreBlanks();
    if (EOP)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, EndWord = true.
       Proses : Akuisisi kata menggunakan procedure SalinWord */

    IgnoreBlanks();
    if (EOP)
    {
        endWord = true;
    }
    else
    {
        CopyWord();
    }
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 0;
    while (currentChar != MARK && currentChar != BLANK && i < 50 && currentChar != EOF)
    {
        currentWord.TabWord[i] = currentChar;
        i++;
        ADV();
    }
    currentWord.Length = i;
}

int readIntWithRange(int min, int max)
{
    int res;
    do
    {
        STARTWORD(stdin, false);
        scanf("%d", &res);
        if (res < min || res > max)
        {
            printf("Input tidak valid. Silahkan coba lagi.\n", min, max);
        }
        IgnoreWords();
    } while (res < min || res > max);
    return res;
}