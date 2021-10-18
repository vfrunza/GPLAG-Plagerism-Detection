#include <stdio.h>
#include <math.h>


void zaokruzi1 (float* niz, int velicina)
{
	float* p=niz;
	while (p<niz+velicina) {
		*p=round(*p*10)/10;
		p++;
	}
}

void preslozi(float* niz, int velicina, int k)
{
	int i, j, l, temp1, zbir_cifara, granica=0;
	float temp2;

	zaokruzi1(niz, velicina);

	for(i=0; i<velicina; i++) {
		temp1=(int)(niz[i]*10);
		temp1=fabs(temp1);
		zbir_cifara=0;

		while (temp1>0) {
			zbir_cifara+=temp1%10;
			temp1/=10;
		}

		if(zbir_cifara>=k) {
			/*rotiranje niza*/
			for(j=granica; j<i; j++) {
				temp2=niz[granica];
				for(l=granica; l<i; l++) {
					niz[l]=niz[l+1];
				}
				niz[i]=temp2;
			}
			granica++;
		}
	}

}

int main()
{
	float niz[100];
	int velicina, i, k;

	printf("Unesite k:");
	scanf("%d", &k);

	printf("Unesite velicinu:");
	scanf("%d", &velicina);

	printf("Unesite niz: ");
	for(i=0; i<velicina; i++) {
		scanf("%f", &niz[i]);
	}

	printf("Pocetni niz:\n");
	for(i=0; i<velicina; i++) {
		printf("%g ", niz[i]);
	}

	printf("\nNakon zaokruzivanja niz izgleda ovako:\n");
	zaokruzi1(niz,velicina);
	for(i=0; i<velicina; i++) {
		printf("%g ", niz[i]);
	}

	printf("\nNakon preslaganja niz izgleda ovako za k=%d:\n", k);
	preslozi(niz,velicina,k);
	for(i=0; i<velicina; i++) {
		printf("%g ", niz[i]);
	}
	return 0;
}
