#include <stdio.h>
#include <math.h>

/*Zaokruzuje clanove niza na jednu decimalu.*/
float zaokruzi1 (float *niz, int vel)
{
	float *p=niz;
	while (p<niz+vel) {
		*p*=10;
		*p=round(*p);
		*p++/=10;
	}
}
/*Racuna sumu cifara*/
float suma_cifara1( int broj)
{

	int sumaCifara1=0, broj1=0, cifra;

	broj1=broj1*10;
	cifra=broj1%10;
	sumaCifara1+=cifra;
	broj1=(int)broj1/10;

	return sumaCifara1;

}
/*Provjerava da li suma cifara veca ili jednaka k i presleze niz */
float preslozi(float *niz, int vel, int k)
{

	int i=0, j=0, temp, broj, sumaCifara1=0, sumaCifara2=0;
	for (i=0; i<vel; i++)
		zaokruzi1(niz, vel);



	sumaCifara1=suma_cifara1(broj);
	if(sumaCifara1>=k) {
		for(i=0; i<vel; i++) {
			for(j=i+1; j<vel; j++) {
				if(*(niz+i) > *(niz+j)) {
					temp=*(niz+i);
					*(niz+i)=*(niz+j);
					*(niz+j)=temp;
				}
			}

		}
	}

}


int main()
{
	float niz[100];
	int i=0, k, vel=0;
	printf("Unesite velicinu niza: ");
	scanf("%d", &vel);

	printf("Unesite niz: ");
	for(i=0; i<vel; i++) {
		scanf("%g", &niz[i]);
	}
	printf("Unesite broj k: ");
	scanf("%d", &k);

	zaokruzi1(niz, vel);

	for(i=0; i<vel; i++) {
		printf("%g ", niz[i]);
	}
	printf("\n");

	preslozi(niz,vel, k);

	for(i=0; i<vel; i++) {
		printf("%g ", niz[i]);
	}

	return 0;
}
