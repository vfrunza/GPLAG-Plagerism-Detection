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

void najduzi_bp(char *s1, char *s2)
{
	int brojac, max_brojac, p_brojac;
	char znak, *p, *q, *r;

	/* stavimo pocetak podstringa na \0 ako je uneseni string prazan i kao pocetnu velicinu podniza 0 */
	max_brojac=0;
	*s2='\0';
	while(*s1!='\0') {

		/* ako pokazivac pokazuje na sovo onda brojimo koliko slova ima do kraja rijeci, a da se ne ponavljaju */
		if((*s1>='a' && *s1<='z') || (*s1>='A' && *s1<='Z')) {
			p=s1;
			while(*p!=' ' && *p!='\0' && ((*p>='a' && *p<='z') || (*p>='A' && *p<='Z'))) {
				q=s1;
				brojac=0;

				/* brojimo slova koja se ne ponavljaju */
				while(q<=p) {
					znak=*q;
					if(znak>='a' && znak<='z') znak-='a'-'A';
					p_brojac=0;
					r=s1;

					/* brojimo koliko se puta ponavlja znak u podnizu, te ako se pojavljuje samo jednom onda povecavamo velicinu podniza */
					while(r<=p) {
						if(*r==znak || *r==znak+'a'-'A') p_brojac++;
						r++;
					}
					if(p_brojac==1) brojac++;
					q++;
				}

				/* ako je velicina podniza veca od prethodno najveceg podniza onda postavljamo adresu pocetka podniza kao adresu pocetka najveceg podniza */
				if(brojac>max_brojac) {
					max_brojac=brojac;
					r=s2;
					q=s1;

					/* upisujemo podniz u odgovarajuci string */
					while(q<=p) {
						*r=*q;
						r++;
						q++;
					}
					*r='\0';
				}
				p++;
			}
		}
		s1++;
	}
}

int main()
{
	char s1[1000], s2[1001];
	printf("Unesi recenicu: ");
	unesi(s1, 1000);
	najduzi_bp(s1, s2);
	printf("\n%s", s2);
	return 0;
}
