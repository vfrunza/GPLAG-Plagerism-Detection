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

int broj_rijeci(char *tekst) {
	int razmak=1, broj_rijeci=0;
	char *s=tekst;
	while(*s!='\0') {
		if(*s==' ') {
			razmak=1;
		}
		else if(razmak==1) {
			razmak=0;
			broj_rijeci++;
		}
	}
	return broj_rijeci;
}
char *ubaci_broj (char *tekst, int broj) {
	char *s = tekst;
	int razmak=1, i;
	
	broj_rijeci(tekst);
	while(*s != '\0') {
	    
	}
	return tekst;
}

int main() {
	char tekst[1000];
	int n;
	printf("Unesite tekst: ");
	unesi(tekst, 1000);
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	
	return 0;
}
