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

int provjeri_duzine(char* tekst,int duzina){
	int brojac=0;
	while(*tekst!='\0'){
	if(*tekst!=' ')brojac++;
	else{ printf("%d,",brojac);
	brojac=0;}
	tekst++;}
	return 0;
}
int main() {
	char tekst[1000];
	printf("Unesi tekst: ");
	unesi(tekst,1000);
	provjeri_duzine(tekst,1000);
	return 0;
}
