#include <stdio.h>
char* obuhvat (char*s, float x1, float x2, float y1, float y2)
{
	/*u pomocni pokazivas zapamtimo pocetak stinga s da bi mogli vrati na kraju*/
	char *p= s;
	char *pocetak;
	char *kraj;
	int k, q, negativno;
	float x, y, x_dec, y_dec;

	while(*s != '\0') {
		/*postavimo novi pokazivac na pocetak tacke da bi ga zapamtili*/
		if(*s == '(') {
			pocetak = s;
			x=0;
			y=0;
			x_dec=0;
			y_dec=0;
			k=1;
			q=1;
			negativno=1;
			s++;
		}
		/*ako sting nije zadan u korektnom formatu vracamo NULL */
		else return NULL;

		/*u slucaju da je broj negativan mjenjamo vrijednost predznaka*/
		if(*s == '-') {
			negativno=-1;
			s++;
		}

		if(*s<'0' || *s>'9') return NULL;

		while(*s>='0' && *s<='9') {
			x= x*10 + negativno*(*s-'0'); /*pretvaranje iz tipa char u int*/
			s++;
		}

		if(*s=='.') {
			s++;

			/*ako je broj decimalan pretvaramo decimalni dio iz tipa char u int i dodajemo na broj*/

			while(*s>='0' && *s<='9') {
				k=k*10;
				x_dec = x_dec + (*s-'0')/k;
				s++;
			}
			x = x + negativno*x_dec;
		} else return NULL;

		/* ponavljamo postupak za y koordinatu*/
		if(*s==',')
			s++;
		else return NULL;

		negativno = 1;

		if(*s == '-') {
			negativno=-1;
			s++;
		}

		if(*s<'0' || *s>'9') return NULL;

		while(*s>='0' && *s<='9') {
			y = y*10 + negativno*(*s-'0');
			s++;
		}

		if(*s == '.') {
			s++;

			while(*s>='0' && *s<='9') {
				q = q*10;
				y_dec = y_dec + (*s - '0')/q;
				s++;
			}
			y = y + negativno*y_dec;
		} else return NULL;

		/*postvljamo pokazivac kraj da bi upamtili kraj jedne tacke*/
		if(*s == ')') {
			s++;
			kraj = s;
		} else return NULL;

		/*uslov izbacivanja*/
		if(x<x1 || x>x2 || y<y1 || y>y2) {

			while(*kraj != '\0') {

				*pocetak++ = *kraj++;
			}

			*pocetak = *kraj;
			/*smanjujemo velicinu stinga za broj mjesta koja smo izbacili*/
			s = s - (kraj-pocetak);
		}

		if(*s==',') {
			pocetak=s;
			s++;
			x=0;
			y=0;
			x_dec=0;
			y_dec=0;
			k=1;
			q=1;
			negativno=1;
			if(*s=='\0') return NULL;
		}

	}
	s=p;
	/*izbacivanje zareda izmedju tacaka*/
	if(*s==',') {
		while(*s != '\0') {
			*s = *(s+1);
			s++;
		}
	}
	return p;

}

int main()
{
	printf("Zadaća 4, Zadatak 4");
	return 0;
}
