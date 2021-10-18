#include <stdio.h>

void unesite (char niz[], int velicina)
{
	char znak = getchar();
	if (znak == '\n') znak = getchar();
	int i = 0;
	while (i<velicina-1 && znak !='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

void najduzi_bp (char* s1, char* s2)
{

	char pomocni_niz[20];
	int  najduzi=0, brojac=0;
	char* hodalica;
	char* pocetak_s2=s2;
	int m=0, k=0;

	while (*s1!='\0') {

		if ((*s1<'A' || *s1>'Z') && (*s1<'a'|| *s1>'z')) {
			s1++;
		}
		brojac=0;
		m=0;
		pomocni_niz[m]=*s1;
		m++;
		brojac++;
		if ((*(s1+1)<'A' || *(s1+1)>'Z') && (*(s1+1)<'a' || *(s1+1)>'z') && *(s1+1)!='\0' && *(s1+2)!='\0') {
			s1=s1+2;
		}
		hodalica=s1+1;
		//uporedujemo jedno slovo sa sljedecim
		while ((*hodalica>='A' && *hodalica<='Z') || (*hodalica>='a' && *hodalica<='z')) {
			if (*s1 != *hodalica && *s1-32!=*hodalica && *s1+32!=*hodalica) {
				pomocni_niz[m]=*hodalica;
				m++;
				brojac++;
				hodalica++;
			} else break;
		}
		//ako je novi niz slova najduzi stavlja u zadati prazni niz
		if (najduzi<brojac) {
			for (k=0; k<brojac; k++) {
				*s2=pomocni_niz[k];
				s2++;
				najduzi++;
			}
		}
		//if (najduzi<brojac)
		s2='\0';
		s2++;
		brojac=0;
		m=0;
		s2=pocetak_s2;
		s1++;
		//prelazi preko znakova
		while ((*s1<'A' || *s1>'Z') && (*s1<'a'|| *s1>'z') && *s1!='\0') {
			*s1++;
		}
	}

}
int main()
{

	char recenica1[1000];
	char recenica2[10];
	unesite (recenica1, 1000);
	najduzi_bp (recenica1,recenica2);
	printf ("%s",recenica2);

	return 0;
}
