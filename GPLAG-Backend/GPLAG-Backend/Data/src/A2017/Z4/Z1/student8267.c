#include <stdio.h>
void unesi(char niz[], int velicina){
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
char* ubaci_broj(char* tekst, int broj)
{
	char* pom=*tekst;
	int brojac_clanova_teksta=0;
	while(*tekst!='\0')
	{
	    brojac_clanova_teksta++;
	    tekst++;
	}
	while(*tekst!='\0')
	{
	    if(*tekst=' '&&)
	    
	    tekst++;
	}
	return pom;
}
int main() {
	printf("Zadaća 4, Zadatak 1");
	return 0;
}
