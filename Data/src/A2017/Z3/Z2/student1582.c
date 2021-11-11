#include <stdio.h>
#include <math.h>

float zaokruzil (float niz[], int a)
{
	int i=0;
	
	for (i=0; i<a; i++)
	{
		niz[i]=niz[i]*10;
		niz[i]=round (niz[i]);
		niz[i]=niz[i]/10;
		niz++;
	}
return niz[i];
}

int main ()
{
	float niz[10]; 
	int a;
	int i;
	
	scanf ("%d", &a);
	
	for (i=0; i<a; i++)
	scanf ("%f", &niz[i]);
	
	printf ("Niz glasi: ");
	for (i=0; i<a; i++)
	printf ("%f", zaokruzil(niz, a));
	
return 0;
}