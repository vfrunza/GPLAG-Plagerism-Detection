#include <stdio.h>

char* zamjena_rijeci (char* tekst, char** rijeci, char** zamjene, int broj_rijeci) {
	char *s=tekst,*p,*q,*r=s,*t,*u;
	int i,duzina_rijeci=0,duzina_zamjene=0;
	while (*s!='\0') {
		for (i=0; i<broj_rijeci; i++) {
			p=rijeci[i];
			if (*s==*p) {
				r=s;
				if (s!=tekst && *(s-1)!=' ') break;
				while (*p!='\0' && *s==*p && *s!='\0') {
					p++;
					s++;
				}
				duzina_rijeci=0;
				duzina_zamjene=0;
				if (*p=='\0' && (*s==' ' || *s=='\0')) {
					duzina_rijeci=s-r;
					q=zamjene[i];
					while (*q!='\0') {
						q++;
						duzina_zamjene++;
					}
				}
				if (duzina_rijeci==duzina_zamjene && duzina_rijeci!=0) {
					s=r;
					q=zamjene[i];
					while (*q!='\0') {
						*s++=*q++;
					}
				}
				else if (duzina_rijeci>duzina_zamjene) {
					s=r;
					q=zamjene[i];
					while (*q!='\0') {
						*s++=*q++;
					}
					r=s;
					t=s;
					s+=duzina_rijeci-duzina_zamjene;
					while (*s!='\0') {
						*t++=*s++;
					}
					*t='\0';
					s=r;
				}
				else if (duzina_rijeci<duzina_zamjene) {
					u=s;
					while (*s!='\0') {
						s++;
					}
					t=s;
					s+=duzina_zamjene-duzina_rijeci;
					while (t!=u) {
						*s--=*t--;
					}
					*s=*t;
					s=r;
					q=zamjene[i];
					while (*q!='\0') {
						*s++=*q++;	
					}
				}
			}
		}
		if (*s=='\0') break;
		s++;
	}
	return tekst;
}

int main() {
	printf("Zadaća 4, Zadatak 3");
	return 0;
}
