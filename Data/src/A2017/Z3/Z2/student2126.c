#include <stdio.h>
#include <math.h>
void zaokruzi1 (float *niz, int vel)
{
	int i;
	for (i=0; i<vel; i++) {
		niz[i]=round(niz[i]*10)/10;
	}
}

void preslozi (float *niz, int vel, int k)
{
	int i, cifra=0, x=0, z=0;
	float sum=0, niz1[101]= {0}, y=0;

	zaokruzi1(niz, vel);
	for (i=0; i<vel; i++) {
		y=niz[i]*10;
		x =fabs(y);
		sum=0;
		while (x!=0) {
			cifra=x%10;
			sum+=cifra;
			x/=10;
		}
		
		if (sum>=k) {
			niz1[z]=niz[i];
			z++;
		}
	
	}
		for (i=0; i<vel; i++) {
		y=niz[i]*10;
		x =fabs(y);
		sum=0;
		while (x!=0) {
			cifra=x%10;
			sum+=cifra;
			x/=10;
		}
		
		if (sum<k) {
			niz1[z]=niz[i];
			z++;
		}
	
	}
	
	for (i=0; i<vel; i++) {
		niz[i]=niz1[i];
	}

}

int main()
{
   int i;
    float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
    preslozi(niz, 5, 14);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);
	return 0;
}
