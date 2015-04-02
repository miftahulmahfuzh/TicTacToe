/*nama file : mesinkar.h*/
/*miftahul mahfuzh [13513017]*/

#ifndef __MESIN_KAR__
#define __MESIN_KAR__
#include "boolean.h"
#include <stdio.h>
#define MARK '.'

/* State Mesin */
char CC;
boolean EOP;

void START1();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
Karakter pertama yang ada pada pita posisinya adalah pada jendela.
I.S. : sembarang
F.S. : CC adalah karakter pertama pada pita
Jika CC != MARK maka EOP akan padam (false)
Jika CC = MARK maka EOP akan menyala (true) */

void START2();

void ADV();
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : CC adalah karakter berikutnya dari CC yang lama,
CC mungkin = MARK
Jika CC = MARK maka EOP akan menyala (true) */
#endif