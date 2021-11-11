#include <stdio.h>


int prost (int broj)
{
	int i;
	int prost =1;
	
 	if (broj==2)
 	{
		return 1;
	}
	
	for (i=2; i<broj; i++)
	{
		if (broj%i==0)
		{
			prost=0;
			return 0;
		}
	}
	return 1;
}


int daj_prost ()
{
	int i,j;
	static int prost_broj=1;

	do
	{
		prost_broj++;
	} while (prost(prost_broj)!=1);


	return prost_broj;
}



int main()
{

	int i,prvi_broj,drugi_broj,suma=0,pomocna_varijabla,prost_broj;


	printf ("Unesite brojeve A i B: ");


	do {
		scanf ("%d %d",&prvi_broj,&drugi_broj);



		if (prvi_broj<=0)
		{
			printf ("A nije prirodan broj.\n");
			printf ("Unesite brojeve A i B: ");
			continue;
		}




		if (prvi_broj>=drugi_broj) 
		{
			printf ("A nije manje od B.\n");
			printf ("Unesite brojeve A i B: ");
			continue;
		}

		if (prvi_broj==drugi_broj)

		{
			printf ("A nije manje od B.\n");
			printf ("Unesite brojeve A i B: ");
			continue;
		}


	} while (prvi_broj<=0 || prvi_broj >=drugi_broj);
	
	
	pomocna_varijabla=prvi_broj;


	for (i=2; i<drugi_broj; i++)
	{
		prost_broj=daj_prost();
	
	    	if (prost_broj>prvi_broj && prost_broj<drugi_broj)
	    	{
			suma+=prost_broj;
		    }
	}


	printf ("Suma prostih brojeva izmedju %d i %d je %d.",pomocna_varijabla,drugi_broj,suma);


	return 0;
}
