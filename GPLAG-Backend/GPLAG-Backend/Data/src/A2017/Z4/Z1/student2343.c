#include <stdio.h>

void unesi(char niz[], int velicina);
	void unesi(char niz[], int vel){
	char znak=getchar();
	if(znak=='\n') znak = getchar();
	int i=0;
	while(i<vel-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
		
	}
	niz[i]='\0';
	
}
int main() {
	int broj;
	printf("Unesite tekst: ");
	unesi(tekst, 100);
	printf("Unesite broj: ");
	scanf("%d"&a);
	return 0;
}
