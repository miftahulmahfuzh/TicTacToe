/*nama file : mesinkar.c*/
/*miftahul mahfuzh [13513017]*/

#include <stdio.h>
#include "mesinkar.h"

static FILE *pita;
static int retval;


void START1() 
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
Karakter pertama yang ada pada pita posisinya adalah pada
jendela.
I.S. : sembarang
F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka
EOP akan padam (false). Jika CC = MARK maka EOP akan menyala (true)
*/
/* Algoritma */
{
 pita = fopen("user.txt","r");
 ADV();
}

void START2()
{
 pita = fopen("comp.txt","r");
 ADV();
} 

void ADV() 
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : CC adalah karakter berikutnya dari CC yang lama,
CC mungkin = MARK. Jika CC = MARK maka EOP akan menyala (true) */
{
 /* Algoritma */
 retval = fscanf(pita,"%c",&CC);
 EOP = (CC == MARK);
 if (EOP) 
   fclose(pita);
}