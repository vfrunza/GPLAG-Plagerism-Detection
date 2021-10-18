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

void okreni_broj( int *p)
{
	int broj, novi_broj, cifra;
	broj=*p;
	novi_broj=0;
	while(broj!=0) {
		cifra=broj%10;
		broj/=10;
		novi_broj=novi_broj*10+cifra;
	}
	*p=novi_broj;
}

char* ubaci_broj(char *tekst, int broj)
{
	char cifra, *s, *p, *r;
	int negativan_broj, okrenut_broj, postoji, broj0, p_broj;

	/* ako je broj negativan onda ga pomnozimo sa -1 i logicku varijablu negativan_broj koristimo da bi kasnije upisali minus */
	negativan_broj=0;
	if(broj<0) {
		negativan_broj=1;
		broj=-broj;
	}

	/* kada broj rastavljamo na cifre i ubacujemo cifre kao znakove u string onda se broj okrene */
	/* da bi to sprijecili mi okrenemo broj pa se tokom ubacivanja on vrati u pocetni oblik */
	okrenut_broj=broj;
	okreni_broj(&okrenut_broj);

	s=tekst+1;
	while(*s!='\0') {
		p_broj=okrenut_broj;

		/* dodjemo do razmaka nakon rijeci */
		if(((*(s-1)>='a' && *(s-1)<='z') || (*(s-1)>='A' && *(s-1)<='Z')) && *s==' ') {
			r=s+1;
			postoji=0;

			/* provjerimo da li postoji rijec nakon kraja one na kojoj je pokazivac s */
			while(*r!='\0') {
				if(*r!=' ') postoji=1;
				r++;
			}

			/* ako postoji takva rijec onda ubacujemo broj izmedju njih */
			if(postoji) {
				/* ako su izmedju rijeci vise od jednog razmaka onda izbacimo jedan jer cemo kasnije ubaciti jedan */
				if(*(s+1)==' ') {
					r=s+1;
					while(*(r-1)!='\0') {
						*r=*(r+1);
						r++;
					}
				}

				/* ako je broj negativan onda prvo u string ubacujemo znak -  */
				if(negativan_broj) {
					p=s;
					if(*s=='\0') return tekst;
					while(*p!='\0') p++;
					s++;
					while(p>=s) {
						*(p+2)=*p;
						p--;
					}
					*(p+2)=' ';
					*(p+1)='-';
				}

				/* ako broj nije negativan onda ubacimo samo jedan razmak */
				else {
					p=s;
					if(*s=='\0') return tekst;
					while(*p!='\0') p++;
					while(p>=s) {
						*(p+1)=*p;
						p--;
					}

				}

				/* okrenut broj ubacujemo u string ako sto uziamamo cifre iz broja i ubacujemo ih kao znakove */
				while(p_broj!=0) {
					cifra=p_broj%10+'0';
					p=s;
					if(*s=='\0') return tekst;
					while(*p!='\0') p++;
					s++;
					while(p>=s) {
						*(p+1)=*p;
						p--;
					}
					*(p+1)=cifra;
					p_broj/=10;
				}

				/* ako je broj prije okretanja imao kao prve cifre nule onda uzimamo te nule i ubacujemo ih u string */
				broj0=broj;
				while(broj0!=0 && broj0%10==0) {
					cifra='0';
					p=s;
					if(*s=='\0') return tekst;
					while(*p!='\0') p++;
					s++;
					while(p>=s) {
						*p=*(p-1);
						p--;
					}
					*(p+1)=cifra;
					broj0/=10;
				}

				/* ako je broj nula onda ga prethodne dvije petlje nece ubaciti u string */
				/* zato naknadno postavljamo uslov ako je broj nula onda samo ubacimo jedan znak 0 izedju rijeci */
				if(broj==0) {
					cifra='0';
					p=s;
					if(*s=='\0') return tekst;
					while(*p!='\0') p++;
					s++;
					while(p>=s) {
						*p=*(p-1);
						p--;
					}
					*(p+1)=cifra;
				}
			}
		}
		s++;
	}

	return tekst;
}

int main()
{
	char recenica[1000];
	int broj;
	printf("Unesi recenicu: ");
	unesi(recenica, 1000);
	printf("Unesi broj: ");
	scanf("%d", &broj);
	printf("%s", ubaci_broj(recenica, broj));
	return 0;
}
