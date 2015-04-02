#include "bacatulis.h"
int main()
{
	/*kamus*/
	char g;
	boolean yn;
	/*algoritma*/
	yn = false;
	do
	{
		printf("apakah anda ingin mengambil giliran pertama ? (y/n) : ");
		scanf("%c",&g);
		if ((g == 'y') || (g == 'Y') || (g == 'n') || (g == 'N')) yn =true;
		else printf("masukan anda salah\n");
	}
	while (!yn);
	makempty();
	if ((g == 'y') || (g == 'Y')) usr1st();
	else com1st();
	return 0;
}


