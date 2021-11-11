#include <stdio.h>
int daj_prost ()
{
    int i,niz[170]={0},j,k=0,prost;
    static int broj=2,pom,pom1=0;
	for (i=2; i<1014; i++)
	{
	    prost=1;
		for (j=2;j<i; j++)
		   if (i%j==0)
		   {
		      prost=0;
		      break;
		   }
		if (prost)
		{
			niz[k]=i;
			k++;
		}
	}
	for (i=pom1;i<169;i++)
	
		if (niz[i]==broj)
		    break;
	broj=niz[i+1];
	pom=niz[i];
	pom1=i;
	return pom;
	
}

int main() {
	int A,B, i,j, suma=0;
	for(;;)
	{
		printf ("Unesite brojeve A i B: ");
		scanf ("%d %d", &A, &B);
		if (A<=0)
		{
			printf ("A nije prirodan broj.\n");
			continue;
		}
		if (A>=B)
		{
			printf ("A nije manje od B.\n");
			continue;
		}
		break;
	}
	for (i=0;i<B;i++)
	{
		j=daj_prost();
		if (j>A && j<B)
		   suma+=j;
	}
	printf ("Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma);
	return 0;
}