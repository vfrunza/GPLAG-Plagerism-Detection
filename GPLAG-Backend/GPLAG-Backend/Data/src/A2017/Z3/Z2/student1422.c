#include <stdio.h>
#include <math.h>

/*Za funkciju preslozi biti ce nam potrebna jos jedna dodatna funkcija zamijeni, jer zelimo promijeniti poredak elemenata u nizu.*/
void zamijeni(float *p1, float *p2)
{
	/*koristimo bubble sort algoritam sa pomocnom varijablom temp*/
	float temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;

}
/*Izrada funkcije zaokruzi koristeci se math.h bibliotekom da bismo zaokruzili elemente niza realnih brojeva na 1 decimalu*/
void zaokruzi1 (float* niz, int velicina)
{
	int i;
	for(i=0; i<velicina; i++) {
		*(niz+i)=round(*(niz+i)*10)/10;
	}
}
void preslozi (float *niz, int vel, int k)
{
	int suma=0, i, j;
	float* p=niz, *q=niz;
	/*poziv funkcije zaokruzi*/
	zaokruzi1(niz, vel);
	for(i=0; i<vel; i++) {
		*p *=10;
		*p=(int) *p%10;
		suma+=*p;
	}
	if(suma>=k) {
		for (i=0; i<vel; i++) {
			q=p+1;
			for(j=i+1; j<vel; j++) {
				if(p<q) {
					
					/*poziv funkcije zamijeni*/
					zamijeni(p,q);
					q++;
				}
			}
			p++;
		}
	} else {
		for(i=k; i<vel; i++) {
			printf("%g", niz[i]);
		}
	}
}
int main(void)
{
	float niz[100];
	int vel, i, k;
	printf("Unesite velicinu niza: ");
	if(vel<100) {
		scanf("%d", &vel);
	} else {
		printf("Pogresan unos!");
		return 0;
	}
	printf("Unesite niz realnih brojeva: ");
	for(i=0; i<vel; i++) {
		scanf("%f", &niz[i]);
	}
	printf("Unesite priorodan broj k: ");
	scanf("%d", &k);
	if(k<1) {
		printf("Pogresan unos!");
	} else {
		/*poziv funkcije zaokruzi*/
		zaokruzi1(niz,vel);
		for(i=0; i<vel; i++) {
			printf("Nakon zaokruzivanja niz glasi: %f", niz[i]);
		}
		/*poziv funkcije preslozi*/
		preslozi(niz,vel,k);
		for(i=0; i<vel; i++) {
			printf("\nNakon poziva funkcije preslozi niz glasi: %f", niz[i]);
		}
	}
	return 0;
}
