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
int provjeri_duzine (char* recenica,int* nizbrojeva,int vel) {
	char* s=recenica;
	char* q= recenica;
	int* s1=nizbrojeva;
	int brojac=0;
	int neslovo=1, broj_rijeci=0;
	while(*q != '\0') {
		if (!((*q>=65  && *q<=90 )||(*q>=97  && *q<=122))) neslovo=1;
		else if (neslovo==1) {
			neslovo=0;
			broj_rijeci++;
		}
		q++;
	}
	if (broj_rijeci != vel) return 0;
	
	while (*s != '\0') {
		if  ((*s>=65  && *s<=90 )||(*s>=97  && *s<=122)) {
			
			while ((*s>=65  && *s<=90 )||(*s>=97  && *s<=122)) {
				brojac++;
				s++;
		}
		if (brojac!= *s1) return 0;
		brojac=0;
		s1++;
		}
		else 	s++;
	}
	return 1;
}
int main() {
	char tekst[100];
	int niz[100],vel;
	int i;
	printf("Unesite tekst: ");
	unesi(tekst,100);
	printf("Unesite vel niza: ");
	scanf("%d",&vel);
	printf("Unesi clanove niza: ");
	for (i=0;i<vel;i++) {
		scanf("%d",&niz[i]);
	}
	provjeri_duzine(tekst,niz,vel);
	 
	return 0;
}
