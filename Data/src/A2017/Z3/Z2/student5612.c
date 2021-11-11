#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz1[], int vel)
{

	float *n = niz1;
	int i;

	for(i = 0; i < vel; i++) {
		*n = round(*n * 10)/10;
		n++;
	}

}

void preslozi(float niz2[], int vel, int k)
{
	int i, j;
	int nova=0, cifra=0;
	int suma = 0;
	float temp;

	zaokruzi1(niz2, vel);

	for(i=0; i < vel; i++) {
 
		nova = fabs(niz2[i] * 10);

		while(nova != 0) {
			cifra=nova % 10;
			suma=suma + cifra;
			nova=nova / 10;
		}

		if(suma < k) {
        
        temp=niz2[i];
			for(j = i; j < vel; j++) {
				niz2[j] = niz2[j+1];
			    niz2[vel-1]=temp; 
			}
		}
		suma = 0;
	    
	}
}

int main()
{
	return 0;
}