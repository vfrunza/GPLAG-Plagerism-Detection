#include <stdio.h>

void unesi(char niz[], int velicina)
{
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while (i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int br_rijeci(char *s)  /*f-ija za broj rijeci*/
{
	int br=1;
	while(!((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))) s++; /*da pocistim sve sto nije slovo na pocetku stringa*/

	while(*s!='\0') {
		if(!((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))) {
			br++;
			while(!((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))) s++;
		}
		s++;
	}
	return br;
}
int provjeri_duzine(char *s, int niz[], int n)
{
	int br_slova=0, lokacija_u_nizu=0;
	if(br_rijeci(s)>n || br_rijeci(s)<n) return 0;

	while(*s!='/0') {
		while((*s!='\0') && !((*s>='a' && *s<='z') || (*s>='A' && *s<='Z') )&& *s!='\0') {  /*naislo na slovo*/

			s++;

		}

		while((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) {  /*naislo na slovo*/
			br_slova++;
			s++;
		}
		if(lokacija_u_nizu<n && niz[lokacija_u_nizu]!=br_slova) /*1.nemamo viska rijeci 2. na tom mjetu u nizu nije isto slovo kao sto smo izbrojali*/
			return 0;


		lokacija_u_nizu++;
		if(lokacija_u_nizu==n) break;
		br_slova=0;
		s++;
		
	}
	return 1;
}
int main()
{
	char tekst[100];
	int niz[100], i=0, n=0;

	printf("Unesite tekst: ");
	unesi(tekst, 100);
	printf("Unesite niz pozitivnih cijelih brojeva: ");
	for(i=1; i<=100; i++) {
		scanf("%d", &niz[i]);
		if(niz[i]==-1) break;
	}
	n=i;
	printf("%d", provjeri_duzine(tekst, niz, n));

	return 0;
}
