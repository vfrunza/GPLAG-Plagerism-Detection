#include <stdio.h>
#include <stdlib.h>

void unesi (char niz [], int velicina){
	int i=0;
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	while (i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}


int main() {
	char tekst[100];
	int a;
	printf("Unesite tekst: ");
	unesi(tekst,100);
	a=provjeri(tekst);
	printf("%d", a);
	return 0;
}
