/*nama file : mainkata.c*/
/*miftahul mahfuzh [13513017]*/
#include "kata.h"
int main() 
{
	/*algoritma*/
  STARTKATA();
  while (CC != MARK)
  {
  	/**/
    if (CKata.TabKata[1] == '#') break;
    else 
    {
      printf("%c",CKata.TabKata[1]);
      ADVKATA();      
    }
  }
  printf("\n");
  return 0;
}
