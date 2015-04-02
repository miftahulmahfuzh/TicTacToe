/*nama file : mesinkata1.h*/
/*miftahul mahfuzh [13513017]*/

#ifndef __MESINKATA1_H__
#define __MESINKATA1_H__
#include "mesinkar.h"
#include <stdio.h>
#define NMax 50
#define BLANK ' '

typedef struct {
char TabKata[NMax+1];
int Length;
} Kata;

/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
I.S. : CC sembarang
F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA1();
/* I.S. : CC sembarang
F.S. : EndKata = true, dan CC = Mark;
atau EndKata = false, CKata adalah kata yang sudah
diakuisisi,
CC karakter pertama sesudah karakter terakhir kata */

void STARTKATA2();

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
CC adalah karakter pertama dari kata berikutnya,
mungkin MARK
Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
I.S. : CC adalah karakter pertama dari kata
F.S. : CKata berisi kata yang sudah diakuisisi;
CC = BLANK atau CC = MARK;
CC adalah karakter sesudah karakter terakhir yang
diakuisisi */

boolean IsKataSama (Kata K1, Kata K2);
/* Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama dan
urutan karakter yang menyusun kata juga sama */

#endif