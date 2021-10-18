#include <stdio.h>

int main() {
	char niz1[50];
	char niz2[10]={"celikovic"};
	
	char *pok=niz1;
	char *pok2=niz2;
	strcpy(pok,pok2);

	printf("%c",*pok);


	return 0;
}
