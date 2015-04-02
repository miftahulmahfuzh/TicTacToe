#include "bacatulis.h"

/*prosedur yang digunakan*/
void makempty()
//membuat sebuah arena permainan baru
{
	int i;
	for(i=1;i<=9;i++) tab[i] = '-';
}
void baca()
/*prosedur ini membaca masukan user lalu */
{
	/*kamus lokal*/
	int i;
	boolean terisi = true;
	/*algoritma*/
	do 
	{
		printf("masukkan posisi anda [1..9] : ");
		scanf("%d",&i);
		if((tab[i] == 'x') || (tab[i] == 'o'))
			printf("posisi tsb telah terisi\n");
		else terisi = false;
	}
	while (terisi);
	tab[i] = 'x';
	m = (char)(((int)'0')+i);//disini m dikonversi dari int ke char
}

void arti()
/*prosedur ini mengartikan char CC[a..i] yang ada di file eksternal, lalu
 mencetak hasil sementara*/
{
	/*kamus lokal*/
	int i;
	/*algoritma*/
	switch(CKata.TabKata[1])
	{
		case 'a':
				i = 1;
				break;
		case 'b':
				i = 2;
				break;		
		case 'c':
				i = 3;
				break;
		case 'd':
				i = 4;
				break;
		case 'e':
				i = 5;
				break;
		case 'f':
				i = 6;
				break;
		case 'g':
				i = 7;
				break;
		case 'h':
				i = 8;
				break;
		case 'i':
				i = 9;
	}
	tab[i] = 'o';
	//cetak kondisi tabel
	//systm(cls);
	for(i=1;i<=9;i++)
	{
		printf("%c ",tab[i]);
		if(i%3==0) printf("\n");
	}	
	//ambil CKata.TabKata[1] baru
	ADVKATA();	
}

void cari()
{ /* Kamus Lokal */
	int i;
	/* Algoritma */
	while (CKata.TabKata[1] != m)
	{
		for (i=1; i<=7; i++)
			ADVKATA();
		if (CKata.Length>1)
		{
			CKata.Length=1;
			CKata.TabKata[1]=CKata.TabKata[3];
		}
	}
	ADVKATA();
}

void caril()
{
	/*digunakan variable global 
	  tab : array[0..9] untuk menyimpan data posisi keseluruhan
	  m : var penyimpan 
	*/
	/*kamus lokal*/
	int mm; //variabel penyimpan posisi 'o' (program step)
	/*algoritma*/
	if (CKata.TabKata[1] == m) 
	/*variabel m menyimpan nilai posisi masukan user, 
		dan CKata adalah bacaan string CKata pada state.txt*/
	{
		ADVKATA();/*setelah di-ADVKATA, didapatkan CKata.TabKata[1] baru [a..i], 
							yang merupakan step program. ini lalu digunakan pada prosedur arti() selanjutnya*/
	}
	else 
	{
		mm = CKata.TabKata[1] - '0'; /*Ckata dikonversi dari tipe char ke int, lalu disimpan ke mm*/
		tab[mm] = 'o';
		end = true;
		printf("Game Over\n");
	}
}




void usr1st()
/*prosedur yang dijalankan ketika user mulai duluan*/
{
	/*kamus lokal*/		
	int i; //address untuk array tab[]
	int mm,s2,s3; //var penyimpan m sebelumnya 
	boolean sp = false; //penyimpan kasus special (jika user pasti kalah) 
	/*algoritma*/
	STARTKATA1();
	for(i = 1;i <= 4;i++)
	{
		baca();		
		if(i <= 2) cari();
		else caril();
		arti();
		if(end) break;

		/*cek special case*/
		if(i == 1)
		{
			if(m == '5') break;
			if((m-'0')%2 == 0)
			{
				sp = true;
				mm = m-'0';
			}
		}
		if((i == 2) && ((mm==2&&m!='8') || (mm==8&&m!='2') || (mm==4&&m!='6') || (mm==6&&m!='4')))
			sp = false; //special case tidak berlaku pada case diatas
	}

	/*special case*/
	if(m == '5')
	{
		for(i=2;i<=4;i++)
		{
			baca();
			mm = m-'0';
			switch(i)
			{
				case 2:
						cari(); 
						s2 = mm;
						break;
				case 3:
						if(s2 == 2 || s2 == 4 ) cari();
						else caril();
						s3 = mm;
						break;
				case 4:
						if((s2 == 2 && s3 == 3) || (s2 == 2 && s3 == 6) || (s2 == 2 && s3 == 9) || (s2 == 4 && s3 == 8) || (s2 == 4 && s3 == 9) || (s2 == 6 && s3 == 7) || (s2 == 8 && s3 == 3))
							caril();
						else cari();
						if((s2 == 2 && s3 == 3) || (s2 == 4 && s3 == 7)) sp = true;
			}
			arti();
			if(end) break;
		}		
	}

	if(sp) //jika berada pada state special, yaitu kondisi dimana user pasti kalah
	{
		if(!end)
		{
			printf("Game Over\n");
			end = true;
		}
	}

	if (!end)
	{
		baca();	
		for(i=1;i<=9;i++)
		{
			printf("%c ",tab[i]);
			if(i%3==0) printf("\n");
		}	
		printf("Game Tied\n");
	}
}

void carii()
/*bentuk lain cari()*/
{ 	/* Kamus Lokal */
	int j=1;
	int i;
	Kata masukan;
	/* Algoritma */
	masukan.Length=1;
	masukan.TabKata[1]=m;
	while (!IsKataSama(CKata,masukan) && j<=1)
	{
		for (i=1; i<=7; i++)
			ADVKATA();
		j++;
		if (CKata.Length>1)
		{
			CKata.Length=1;
			CKata.TabKata[1]=CKata.TabKata[3];
		}
	}
	ADVKATA();
}


void cari2()
{ /* procedure cari 2 mencari state di special state atau inutan pertama user 5 */	
	/* Kamus Lokal */
	int j=1;
	int i;
	Kata masukan;
	/* Algoritma */
	masukan.Length=1;
	masukan.TabKata[1]=m;
	while (!IsKataSama(CKata,masukan) && j<=7)
	{
		for (i=1; i<=5; i++)
			ADVKATA();
		j++;
		if (CKata.Length>1)
		{
			CKata.Length=1;
			CKata.TabKata[1]=CKata.TabKata[4];// dilinux ini diganti 4, pada windows ini diganti 3
		}
	}
	ADVKATA();
}

char angka2huruf(char c)
/* mengubah karakter angka ke karakter huruf untuk dibaca oleh arti*/
{	/* Kamus Lokal */
	/* Algoritma */
	switch (c)
	{
		case '1':
			return('a');
			break;
		case '2':
			return('b');
			break;
		case '3':
			return('c');
			break;
		case '4':
			return('d');
			break;
		case '5':
			return('e');
			break;
		case '6':
			return('f');
			break;
		case '7':
			return('g');
			break;
		case '8':
			return('h');
			break;
		case '9':
			return('i');
			break;
	}
}


void carip(boolean *found)
{	/* procedure untuk mencari state selanjutnya agr ke final state, jika input tidak diterima state selanjutnya maka Game Over */
	/* Kamus Lokal */
	Kata masukan;
	/* Algoritma */
	masukan.Length=1;
	masukan.TabKata[1]=m;
	if (!IsKataSama(CKata,masukan))
	{
		tab[CKata.TabKata[1]-'0'] = 'o';
		m=angka2huruf(CKata.TabKata[1]);
		arti();
		(*found)=true;
	}
	else
	{
		ADVKATA();
		arti();
	}
}

void com1st()
/*prosedur yang dijalankan ketika com mulai duluan*/
{	/* KAMUS LOKAL*/
	int z=1;
	int ir;
	int Nkata;
	Kata searchkata;
	boolean found=false;
	/* ALGORITMA */
	STARTKATA2();	
	tab[1] = 'o';
	for (ir=1;ir<=9;ir++) 
	{
		printf("%c ",tab[ir]);
		if(ir%3==0) printf("\n");
	}
	baca();	
	if (m != '5')
	{
		cari2();
		arti();
		while(z<=2 && !found)
		{
			baca();
			carip(&found);
			z++;
		}	
		printf("Game Over\n");
	}
	else
	{
		cari2();
		arti();
		while(z<=2 && !found)
		{
			baca();
			carip(&found);
			z++;
		}
		if (found==false)
		{
			baca();
			carii();
			arti();
			printf("Game Tied\n");
		}
		else
			printf("Game Over\n");
	}
}