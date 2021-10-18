#include <stdio.h>

void unesi(char niz[], int velicina) {
    int i = 0;
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

char* ubaci_broj (char* tekst, int broj) {
	char* ret=tekst;
	int brojac=0;
	int* br=&broj;
		char sbroj[12];
	char* sb= sbroj;
	int tmp=broj;
	int* brdva=&broj;
	char* pom=sbroj;
	/*duzina za koju prosirujemo string*/
	
	if (*br<0) brojac++;
	do {
		*br=(int) *br/10;
		brojac++;
	}
	while(*br!=0);
	
	/*pretvaranje int u string*/

	
	/*predznak*/ 
	if (broj<0) {
		broj=-broj;
		*sb++ = '-';
	}
	
	/*prebrojavamo cifre*/
	do {
		sb++;
		tmp /=10;
	}
	while (tmp!=0);
	*sb--='\0';
	
	do {
		*sb-- = *brdva % 10 + '0';
	*brdva /=10;
	}
	while(*brdva !=0);
	
	/*unacujemo broj u teskt*/
	
       while (*tekst!= '\0') {
       	if (*tekst==' ') {
       		brojac++;
       		char* kraj= tekst;
       		while (*kraj != '\0') kraj++;
       		while (kraj > tekst) {
       			*(kraj+brojac) = *kraj;
       			kraj--;
       		}
       		
       	while (*pom != '\0')  *tekst++ = *pom++;
       	}
       	tekst++;
       }
	return ret;
}
int main() {
	char tekst[100];
	int broj;
	printf("Unesite tekst: ");
	unesi(tekst,100);
	printf("Unesite broj koji treba ubaciti: ");
	scanf("%d",&broj);
	printf("%s",ubaci_broj(tekst,broj)); 
	return 0;
}
