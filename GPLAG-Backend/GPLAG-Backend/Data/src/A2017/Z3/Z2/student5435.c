#include <stdio.h>
#include <math.h>
void zaokruzi(float* niz, int k)
{
	int i;

	for(i=0; i<k; i++) {

		niz[i]=niz[i]*10;
		niz[i]=round(niz[i]);
		niz[i]=niz[i]/10;
	}


}

void preslozi(float *niz, int z)
{

	float a;
    int i, suma=0;
	
	while(niz !=0){
		a=(*niz)%10;
		a=a/10;
		suma+=a;
		
	}
		
		
	

    


}

int main()
{

	float  niz[100];
	int n,i,k;

	do {
		printf("Unesite dimenziju niza: ");
		scanf("%d", &n);
	} while (n<1 || n>100);

	printf("Unesite elemente niza: ");
	for(i=0; i<n; i++) {
		scanf("%f", &niz[i]);
	}

	zaokruzi(i,n);
	for(i=0; i<n; i++) {
		printf("%f", niz[i]);
	}
	printf("Unesite broj k: ");
	scanf("%d", &k);

	preslozi(i,k);
	for(i=0; i<n; i++) {

		printf("%f", niz[i]);
	}



	return 0;
}
