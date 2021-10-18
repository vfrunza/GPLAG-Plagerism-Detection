#include <stdio.h>
#include <math.h>

void zaokruzi1 (float *niz, int vel)
{
	int i;

	for (i=0; i<vel; i++) {
		niz[i]*=10;
		niz[i]=round(niz[i]);
		niz[i]/=10;
	}
}

int suma_cifara (float i)
{
	int suma=0,pomnozen;

	i=fabs(i);
	pomnozen = i * 10;
	while (pomnozen>0) {
		suma+= pomnozen % 10;
		pomnozen /= 10;
	}
	return suma;
}



void preslozi (float *niz, int vel, int k)
{
	zaokruzi1(niz,vel);

	int suma,i,j,g=0;

	double temp;
	for (i=0; i<vel; i++) {
		suma=suma_cifara(niz[g]);
		if (suma<k) {
			temp = niz[g];
			for (j=g; j<vel-1; j++) {
				niz[j]=niz[j+1];

			}
			niz[vel-1] = temp;
			g--;
		}
		g++;
	}
}

int main()
{
	/* Prvi AT */
	int i;

	float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
	preslozi(niz, 5, 14);
	printf("Niz glasi: ");
	for (i=0; i<5; i++)
		printf("%g ", niz[i]);


	return 0;


}
