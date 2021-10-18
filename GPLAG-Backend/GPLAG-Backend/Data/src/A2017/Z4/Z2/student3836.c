#include <stdio.h>

void unesi(char niz[], int velicina)
{
	int i=0;
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int provjeri_duzine(char* s, int* niz, int vn){
    
   int neslovo=1, broj_slova=0, i=0;
	while(*s!='\0') {
		if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')))
			neslovo=1;
		else if(neslovo==1) {
			neslovo=0;
			
			while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			broj_slova++; 
			s++;}
			if(broj_slova!=niz[i]) return 0;
			broj_slova=0;
			s--; i++;
		}
		s++;
	}
	if(i!=vn) return 0;
	return 1;
}

int main()
{
	char tekst[100];
	int br, i, niz[100];
	printf("Unesite string: ");
	unesi(tekst, 100);
	printf("Unesite velicinu niza: ");
	scanf("%d", &br);
	printf("Unesite clanove niza: ");
	for(i=0; i<br; i++)
	scanf("%d", &niz[i]);

	printf("%d", provjeri_duzine(tekst, niz, br));
	return 0;
}
