#include <stdio.h>

void unesi( char*s, int n)
{
	char znak, *p;
	znak=getchar();
	if(znak=='\n') znak=getchar();
	p=s;
	while(p<s+n-1 && znak!='\n') {
		*p=znak;
		p++;
		znak=getchar();
	}
	*p='\0';
}

int provjeri(char *s)
{
	char *p, *q;
	int zatvoren_otvoreni, broj_otvorenih, broj_zatvorenih;

	p=s;
	while(*p!='\0') {
		if(*p=='<') {
			q=p+1;
			zatvoren_otvoreni=0;

			/* ako naidjemo na pocetak taga provjeravamo da li je zatvoren */
			while(*q!='\0' && *q!='>') {
				if(*q=='<') return 0;
				if(*(q+1)=='>') zatvoren_otvoreni=1;
				q++;
			}
			if(!zatvoren_otvoreni) return 0;

			/* provjeravamo da li je dobro definisan tag */
			if(*(p+1)!='\0') {
				if(!((*(p+1)>='a' && *(p+1)<='z') || (*(p+1)>='A' && *(p+1)<='Z')) && *(p+1)!='/') return 0;
			}
		}
		p++;
	}

	/* brojimo koliko je otvorenih tagova */
	p=s;
	broj_otvorenih=0;
	while(*p!='\0') {
		if(*p=='<' && ((*(p+1)>='a' && *(p+1)<='z') || (*(p+1)>='A' && *(p+1)<='Z')) && *(p+1)!='\0') broj_otvorenih++;
		p++;
	}

	/* brojimo koliko je zatvorenih tagova */
	p=s;
	broj_zatvorenih=0;
	while(*p!='\0') {
		if(*p=='<' && *(p+1)=='/' && ((*(p+2)>='a' && *(p+2)<='z') || (*(p+2)>='A' && *(p+2)<='Z')) && *(p+1)!='\0' && *(p+2)!='\0') broj_zatvorenih++;
		p++;
	}

	/* ako je broj otvorenih i zatvorenih tagova razlicit onda se funkcija zavrsava */
	if(broj_otvorenih!=broj_zatvorenih) return 0;

	return 1;
}

int main()
{
	char tekst[1000];
	printf("Unesi tekst: ");
	unesi(tekst, 1000);
	printf("Rezultat je %d", provjeri(tekst));
	return 0;
}
