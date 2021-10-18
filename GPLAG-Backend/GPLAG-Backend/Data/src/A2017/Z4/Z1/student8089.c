#include <stdio.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

char* ubaci_broj(char* tekst, int broj){
   int temp = broj;
   char sbroj[12];
   char* sb=sbroj;
   //Predznak unesenog broja
   if(broj < 0){
    broj=-broj;
   *sb++='-';
   }
   
   
    
}

int main() {
	char tekst[100];
	int broj;
	
	printf("Unesite neki tekst: ");
	unesi(tekst,100);
	printf("Unesite cijeli broj: ");
	scanf("%d",&broj);
	printf("%s",ubaci_broj(tekst,broj));
	return 0;
}
