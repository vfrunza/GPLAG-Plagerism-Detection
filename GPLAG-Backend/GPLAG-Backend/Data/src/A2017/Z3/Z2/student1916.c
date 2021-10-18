#include <stdio.h>
#include <math.h>

#define MAX_EL 100

/* mijenja mjesta dvije vrijednosti */
void zamijeni(float* prvi, float* drugi)
{
	float temp=*prvi;
	*prvi=*drugi;
	*drugi=temp;
}

/* zaokruzi vrijednost na jednu decimalu */
void zaokruzi1(float* niz, int velicina_niza)
{
	float* p=niz;
	while(p<niz+velicina_niza) {
		*p=round((*p)*10)/10;
		p++;
	}
}

/* izracuna zbir cifara neke vrijednosti */
int zbir_cifara(int element)
{
	int suma=0, cifra;
	int broj=element;
	while(broj!=0) {
		cifra=broj%10;
		suma+=cifra;
		broj/=10;
	}
	return suma;
}

/* sortira niz tako da su prvi elemnti oni kojima je zbir cifara veci ili jednak nekoj vrijednosti k */
void preslozi(float* niz, int velicina_niza, int k)
{
	float element, broj, *p, *q;

	p=niz;

	/* zaokruzi sve vrijednosti niza na jednu decimalu */
	zaokruzi1(p, velicina_niza);

	while(p<niz+velicina_niza) {
		element=fabs((*p))*10;

		/* provjeravamo da li je zbir cifara vrijednosti na pokazivacu manji od k */
		if(zbir_cifara((int)element)<k) {
			q=p+1;

			/* ako je zbir cifara vrijednosti manji od k onda trazimo prvi element niza nakon onog na koji pokazuje pokazivac kojem je zbir cifara vrijednosti veci ili jednak k  */
			while(q<niz+velicina_niza) {
				broj=fabs((*q))*10;
				if(zbir_cifara((int)broj)>=k) {
					break;
				}
				q++;
			}

			/* kada nade potreban element onda mijenja mjesta svim vrijednostima od elementa na koji pokazuje pokazivac i onog na koji smo nasli */
			if(q<niz+velicina_niza) {
				while(q>p) {
					zamijeni(q, q-1);
					q--;
				}
			}
		}
		p++;
	}

}

int main()
{
	int i, broj_elemenata, zbir_cifara;
	float niz[MAX_EL];

	printf("Koliko realnih brojeva cete unijeti? ");
	do {
		scanf("%d", &broj_elemenata);
	} while(!(broj_elemenata>=1 && broj_elemenata<=MAX_EL));

	printf("Unesite niz: ");
	for(i=0; i<broj_elemenata; i++) {
		scanf("%f", &niz[i]);
	}

	printf("Unesite zbir cifara: ");
	do {
		scanf("%d", &zbir_cifara);
	} while(zbir_cifara<0);

	preslozi(niz, broj_elemenata, zbir_cifara);

	for(i=0; i<broj_elemenata; i++) {
		printf("%.1f ", niz[i]);
	}

	return 0;
}
