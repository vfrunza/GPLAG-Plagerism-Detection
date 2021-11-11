#include <stdio.h>
#include <math.h>

void zaokruzi (double niz[], int vel)
{
	double *p = niz;

	
	while (p < niz+vel) {
   *p++ = round(*p*100)/100;
    }

	
	
}


void preslozi (double niz[], int k, int vel)
{
	zaokruzi(niz, vel);
	
	
}


int main() {
    
    double niz[100];
    int k, vel,i;
    
   printf("Unesi k: ");
   scanf("%d", &k);
   
   printf("Unesi velicinu niza: ");
   scanf("%d", &vel);
   
   for (i=0; i<vel; i++)
   {
   	scanf("%lf",&niz[i]);
   }
  
   
   preslozi(niz, k, vel);
 
	return 0;
}
