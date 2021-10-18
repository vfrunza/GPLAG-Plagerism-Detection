#include <stdio.h>

void unesi(char niz[], int velicina){
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}
int provjeri(char *s){
	
}
int main() {
	
	char tekst[100];
	printf("Unesite HTML kod: ");
	unesi(tekst,100);
	printf("%d", provjeri(tekst));
	
	return 0;
}
