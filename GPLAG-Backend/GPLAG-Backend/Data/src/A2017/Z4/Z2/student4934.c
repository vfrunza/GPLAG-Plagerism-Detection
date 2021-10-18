#include <stdio.h>

void unesi(char niz[], int velicina) {
    int i;
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

int provjeri_duzine(char* s, int niz[], int vel) {
	char* pocetak;
	pocetak=s;
	int razmak, i;
	i=0;
	razmak=0;
	int broj_rijeci;
	broj_rijeci=0;
	int duzina=0;
	while (*s != '\0') {
		if (!((*s >= 'a' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))) {razmak=1;}
		else if (razmak==1) {
			razmak=0;
			broj_rijeci++;
		}
		s++;
	}
	s=pocetak;
	if(broj_rijeci!=vel) return 0;
	if(broj_rijeci==vel) {
		while (*s != '\0') {
			if((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) {
				s++;
				duzina++;
		    }
		    if(!((*s>='A' && *s<= 'Z') || (*s>='a' && *s<='z'))) {
		    	s++;
		    	for(i=0; i<=vel; i++) {
		    		if (niz[i]==duzina) s++;
		    		duzina=0;
		    		if (niz[i]!=duzina) return 1;
		    	}
		    }
		    if (*s=='\0') return 0;
	}
}
}

int main() {
	char tekst[100];
	int niz[100];
	int element, vel, i;
	printf("Unesite neki tekst: \n");
	unesi(tekst, 100);
	printf("Unesite niz brojeva: \n");
	for (i=0; i<100; i++) {
		scanf("%d", &element);
		niz[i]=element;
	}
	vel=i;
	printf("%d", provjeri_duzine(tekst, niz, vel));
	return 0;
}
