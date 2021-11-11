#include <stdio.h>
#include <math.h>
#include <stdlib.h>
	
/* Funkcija koja sve clanove niza zaokruzuje na jednu decimalu. */

void zaokruzi1 (float *niz, int vel) {
	float* p=niz;
	while (p < niz+vel) {
		*p *= 10;
		*p = round(*p);
		*p++ /= 10;
	}
}

void preslozi (float *niz, int vel, int k) {
  int i, j, duzina, broj;
  float temp;
  duzina=0;
  zaokruzi1(niz, vel);
  
  for(i=vel-1; i>duzina-1; i--)
  {
    int suma=0;
    broj = abs((int)((*(niz+i))*10));
    
    do
    {
      suma+=broj%10; /* Sumiram cifre nekog clana niza. */
      broj/=10;
    } while (broj>0);
    
    
    if (suma>=k) {
      temp = *(niz+i);
      for (j=i; j>0; j--) {
	*(niz+j) = *(niz+j-1);
      }
      *niz = temp;
      duzina++;
      i++;
    }
  }
}

int main() {
	
	float niz[100];
	int i, vel, k;
	
	printf("Koliko realnih brojeva zelite unijeti: ");
	
	do {
		scanf("%d", &vel);
	} while(vel<1 || vel>100);
	
	printf("Unesite clanove niza: ");
	for(i=0; i<vel; i++) 
	scanf("%f", &niz[i]);
	
	zaokruzi1(niz, vel);
	
    printf("Nakon zaokruzivanja niz glasi: \n");
    for(i=0; i<vel; i++) 
    printf("%f \n", niz[i]);
    
    printf("Unesi k: ");
    scanf("%d", &k);
    
    preslozi(&niz[0], 5, 14);
    
    printf("Niz glasi: ");
    for(i=0; i<5; i++) {
    printf("%g ", niz[i]);
  }
  printf("\n");

	return 0;
}