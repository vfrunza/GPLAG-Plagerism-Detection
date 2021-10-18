/*Zadatak je greskom kucan u Zadaci 4,Zadatku 1 pa sam ga samo prekopirko ovdje gdje treba*/

#include <stdio.h>
int provjeri_duzine(char *tekst,int duzine[], int vel)
{
	int broj_rijeci=0,duzina=0;
	while(*tekst!='\0') {
		if((*tekst>='A' && *tekst<='Z')||(*tekst>='a' && *tekst<='z')) {
			char *kraj=tekst;
			duzina=0;
			broj_rijeci++;
			if(broj_rijeci>vel)
				return 0;
			while(*kraj!='\0') {
				if	(!((*(kraj+1)>='A' && *(kraj+1)<='Z')||(*(kraj+1)>='a' && *(kraj+1)<='z')) || *(kraj+1)<='\0') break;
				else duzina++;
				kraj++;
			}
			duzina++;
			if(duzina!=duzine[broj_rijeci-1]) return 0;
			tekst=kraj;
		}
		tekst++;
	}
	if(broj_rijeci<vel) return 0;
	return 1;
}
int main()
{
	return 0;
}
