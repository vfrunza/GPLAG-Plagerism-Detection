#include <stdio.h>
#include <math.h>

/* funkcija koja zaokruzuje clanove niza na jednu decimalu*/
void zaokruzi1(float* niz, int vel)
{
	float *p= niz;
	while (p<niz+vel) {
		*p*=10;
		*p=round(*p);
		*p/=10;
		p++;
	}
}

/* funkcija za sabiranje cifara realnog broja sa jednom decimalom */
int zbir_cifara(float br)
{
	int c, suma=0;
	int broj;
	broj= fabs(br*10);
	while(broj!=0) {
		c=broj%10;
		suma=suma+c;
		broj=broj/10;
	}
	return suma;
}

/* funkcija za preslaganje clanova na osnovu zadatog kriterija*/

void preslozi(float* niz, int vel, int k)
{
	float *p=niz;
	float *q, *z, *r, *pomocni;
	float  temp;

	/* pozivanje funkcije zaokruzi*/
	zaokruzi1(niz, vel);

	/*preslaganje niza*/
	while (p<niz+vel) {
		if (zbir_cifara(*p)<k) {
			q=p;
			while (q<niz+vel) {
				if(zbir_cifara(*q)>=k) {
					z=q;
					q=niz+vel;
				}
				q++;
			}
			r=z;
			while (r>p) {
				pomocni=r;
				r--;
				temp=*r;
				*r=*pomocni;
				*pomocni=temp;
			}

		}
		p++;
		z=p;
	}
}

int main()
{
	printf("Zadaća 3, Zadatak 2");
	return 0;
}