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
char* ubaci_broj (char* tekst, int broj)
{
	while(*tekst!='\0'){
		if(*tekst==' '){tekst ++;printf("%d", broj);
			if(*tekst==' ')tekst++;
		}
		
		tekst++;
	}
return 0;
}
int main() {
	char tekst[1000];
	int broj;
	printf("Unesite broj koji treba ubaciti: ");
	scanf("%d", &broj);
	printf("Unesi tekst: ");
	unesi(tekst,1000);

	printf("%s",ubaci_broj(tekst,broj));
	
	return 0;
}
