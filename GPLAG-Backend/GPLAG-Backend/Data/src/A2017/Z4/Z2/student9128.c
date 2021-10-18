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

int provjeri_duzine(char *s, int *niz, int velicina) {
	int razmak=1, broj_slova=0, i=0, broj_rijeci=0;
	char *temp, *pom, *povratni=s;
	while(*s!=0) {
		if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) razmak=1;
		else if(razmak==1) {
			broj_rijeci++;
			razmak=0;
		}
		s++;
	}
	if(broj_rijeci<velicina || broj_rijeci>velicina) return 0;
	
	s=povratni;
	broj_rijeci=0;
	razmak=1;
	while(*s!=0) {
		if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) razmak=1;
		else if(razmak==1) {
			broj_rijeci++;
			razmak=0;
			temp=s;
			while((*temp>='A' && *temp<='Z') || (*temp>='a' && *temp<='z')) {
				broj_slova++;
				temp++;
			}
			if(broj_slova!=niz[i]) return 0;
			i++;
		}
		broj_slova=0;

		s++;
	}
	return 1;
}
int main() {
	int niz[100], i, velicina;
	char s[100];
	printf("String: ");
	unesi(s, 100);
	printf("\nVelicina: ");
	scanf("%d", &velicina);
	printf("\nNiz: ");
	for(i=0; i<velicina; i++) {
		scanf("%d", &niz[i]);
	}
	printf("\n%d", provjeri_duzine(s, niz, velicina));
	return 0;
}
