/* NIM/Nama : 13513017
Nama file   : P05135100171.c
Topik       : mesin token
Tanggal     : 2 oktober 2014
Deskripsi   : meyeleksi token dan angka */

#include "kata.h"
//#include "mesinkar.c"

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
I.S. : CC sembarang
F.S. : CC ≠ BLANK atau CC = MARK */
{
  /* Algoritma */
  while ((CC == BLANK) && (CC != MARK)) 
    ADV();
  /* CC != BLANK or CC = MARK */
}

void STARTKATA1()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = Mark;
       atau EndKata = false, CKata adalah kata yang sudah
diakuisisi, CC karakter pertama sesudah karakter terakhir kata */
{ 
  /* Algoritma*/
  START1();
  IgnoreBlank();
  if (CC == MARK) 
    EndKata = true;
  else 
   {/* CC != MARK */
    EndKata = false;
    SalinKata();
   }
}

void STARTKATA2()
{ 
  /* Algoritma*/
  START2();
  IgnoreBlank();
  if (CC == MARK) 
    EndKata = true;
  else 
   {/* CC != MARK */
    EndKata = false;
    SalinKata();
   }
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
CC adalah karakter pertama dari kata berikutnya,
mungkin MARK
Proses : Akuisisi kata menggunakan procedure SalinKata */
{
  /* Algoritma*/
  IgnoreBlank();
  if (CC == MARK) 
    EndKata = true;
  else /* CC != MARK */ 
    SalinKata();
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
I.S. : CC adalah karakter pertama dari kata
F.S. : CKata berisi kata yang sudah diakuisisi;
CC = BLANK atau CC = MARK;
CC adalah karakter sesudah karakter terakhir yang
diakuisisi */
{
  /* Kamus Lokal */
  int i = 1; /* inisialisasi */
  /* Algoritma*/
  for (;;) 
  {
    CKata.TabKata[i] = CC;
    ADV();
    if ((CC == MARK) || (CC == BLANK))
      break;
    else
      i++;
  } /* CC = MARK or CC = BLANK */
  CKata.Length = i;
}

boolean IsKataSama (Kata K1, Kata K2)
/* Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama dan
urutan karakter yang menyusun kata juga sama */
{ /* Kamus Lokal */
  int i;
  /* Algoritma */
  if (K1.Length!=K2.Length)
    return false;
  else
  {
    i=1;
    while((i<K1.Length) && (K1.TabKata[i]==K2.TabKata[i]))
    {
      i++;
    }
  }
  return (K1.TabKata[i]==K2.TabKata[i]);
}
