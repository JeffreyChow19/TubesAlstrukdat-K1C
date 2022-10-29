#ifndef STRING_H
#define STRING_H

#include "../boolean.h"
#include "../mesinkata/word.h"

typedef struct
{
  char *buffer;
  int nEff;
  int capacity;
} String;
/* Definisi
  Buffer selalu diakhiri \0 atau null terminator.
*/

/* ********** SELEKTOR ********** */
#define LENGTH(s) (s).nEff
#define SBUFFER(s) (s).buffer
#define CHAR(s, i) (s).buffer[i]
#define SCAPACITY(s) (s).capacity

/* ********** KONSTRUKTOR ********** */
/* Membuat string kosong
  I.S. s sembarang
  F.S. terbentuk string kosong dengan besar buffer capacity + 1 dan elemen pertama null terminator
 */
void CreateEmptyString(String *s, int capacity);

/*
  I.S. s terdefinisi
  F.S. s di-free, length = 0, capacity = 0
 */
void dealocateString(String *s);

/*
  Mengembalikan true jika string sudah penuh
 */
boolean isStringFull(String s);

/* Menambahkan karakter ke akhir string
  I.S. s terdefinisi, s bisa penuh
  F.S. menambahkan karakter c ke akhir string, bila penuh mengalokasikan buffer baru dengan panjang 2x lipat
 */
void appendChar(String *s, char c);

void appendWord(String *s, Word w);

/* Mengekspansi string
  I.S. s terdefinisi, literal merupakan char array yang diakhiri null terminator atau string literal
  F.S. mengisi buffer dengan literal
 */
void setLiteral(String *s, char *literal);

void clearString(String *s);

/* Menambahkan capacity s sebanyak num
  I.S. s terdefinisi
  F.S. Capacity s bertambah sebanyak num
*/
void expandString(String *s, int num);

/*
  Mengembalikan true jika string s1 sama dengan string s2
 */
boolean isStringEqual(String s1, String s2);

boolean isStringEqualLiteral(String s, char *literal);

boolean isKataEqualLiteral(Word w, char *literal);

boolean isStringInt(String s);

boolean isWordInt(Word w);

/*
  Mengembalikan nilai integer dari string.
  Prekondisi: string merupakan angka
 */
int stringToInt(String s);

/*
  Mengembalikan nilai berupa banyak kemunculan char c pada string
 */
int countChar(String s, char c);

/*
  Mengembalikan copy dari string s
 */
String getCopyString(String s);

String wordToString(Word w);

int wordToInt(Word w);

void toUpper(String *s);

boolean startsWithLiteral(String s, char *literal);

boolean startsWith(String s1, String s2);

#endif