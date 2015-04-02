#ifndef bacatulis_H
#define bacatulis_H
#include <stdio.h>
#include "kata.h"

/*kamus global*/

char m;     //string penyimpan nilai masukan user [1..9]
int tab[9]; //tabel penyimpan kondisi permainan
boolean end; 
/*prosedur yang digunakan*/

void makempty();
//membuat sebuah arena permainan baru

void baca();
/*prosedur ini membaca masukan user lalu */

void arti();
/*prosedur ini mengartikan char CC[a..i] yang ada di file eksternal, lalu
 mencetak hasil sementara*/

void cari(); 

void caril();
/*mencari masukan user (disimpan di m) pada file eksternal :
	# jika m ditemukan, ADVKATA(), lalu artikan CKata nya (CKata 
 		berisi step program).
	# jika m tidak ditemukan -> (not IsKataSama(m,CKata)). isi 'o' 
		di CKata, dan tampilkan pesan bahwa user kalah */

void cari();
/*transition function yang menuju ke state tertentu dengan 
metode pencarian step user di file eksternal*/

void usr1st();
/*prosedur yang dijalankan ketika user mulai duluan*/

void carii();
/*bentuk lain cari()*/

void cari2();

char angka2huruf(char c);

void carip(boolean *found);

void com1st();
/*prosedur yang dijalankan ketika com mulai duluan*/
#endif
