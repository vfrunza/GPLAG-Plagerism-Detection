#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void zaokruzi1(float niz[], int vel)
{
	int i=0;
	for(i=0; i<vel; i++) {
		niz[i]=round(niz[i]*10)/10;
	}
}

void preslozi(float arr[], int velicina, int n)
{
	int i, j, cifra, suma=0, priv, brojac=0;
	float element;
	zaokruzi1(arr, velicina);
	/* Dijeljenje i suma */
	for(i=0; i<velicina; i++) {
		priv=abs((int)(10*arr[i]));
		do {
			cifra=priv%10;
			priv=priv/10;
			suma+=cifra;
		} while(priv>0);
		/* Preslaganje clanova niza */
		if(suma>=n) {
			element=arr[i];
			for(j=i; j>brojac; j--) {
				arr[j]=arr[j-1];
			}
			arr[brojac]=element;
			brojac++;
		}
		/* Restartovanje sume */
		suma=0;
	}
}

int main()
{

	return 0;
}
