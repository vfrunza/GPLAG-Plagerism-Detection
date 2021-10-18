#include <stdio.h>
#include <math.h>


double *zaokruzi (double *niz, int velicina){
double *p=niz;
while (p<niz+velicina) {
 *p *= 10;
 if (*p>0) *p = (int) (*p+0.5);
 else if (*p<0) *p = (int) (*p-0.5);
 *p++/=10;
}
return niz;
}


void ispisi (double *p, int velicina)
{
 while (velicina--)
 printf ("%.2f", *p++);
}

 float preslozi(float* niz, int broj, int k) {
 
 	int suma=0, j, b=0, a, c, velicina=0;
 	double temp;
 	
 	for (j=0; j<velicina; j++) {
 		
 		do
 		{
 			a = niz[j]*10;
 		    suma += a%10;
		a /= (a-a*10)/10.;
 		} while (niz[j] != 0);
 		
		 if (suma >= k) {
		 temp = niz[b];
		 niz[b] = niz[j];
		 b++;
 	}
 	
 	for (c=j; c>b+2; c--)
 	niz[c] = niz [c-1];
 	niz[b+1] = temp;
 	}
		return *niz;
 }
 
int main() {
	
 float niz[100];
 int i, velicina, u, k, broj, j;
 printf ("Unesite elemente niza :");
 scanf ("%f", &niz[100]);
 printf ("Unesite k: ");
 scanf ("%d", &k);

 
ispisi (zaokruzi (niz, i),velicina);
 printf ("Niz glasi: ");
 for (j=0; j<velicina; j++)
 printf ("%g\n", niz[j]);
	
	preslozi (niz,broj, k);
	printf ("Niz glasi: ");
	for (u=0; u<broj; u++)
	printf ("g\n", niz[u]);
	
	return 0;
}
