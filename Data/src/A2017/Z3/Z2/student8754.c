#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void zaokruzi1 (float *niz, int vel)
{
	int i=0;
	for (i=0; i<vel; i++)
	{
		*niz=round(*niz*10)/10;
	     niz++;
	}
}

void preslozi (float *niz, int vel, int k)
{
	zaokruzi1 (niz,vel);
	float nizvecih[1000], nizmanjih[1000];
	int var,i,j=0,p=0,r=0,suma;


	for (i=0; i<vel; i++)
	{
		suma=0;
		var=fabs(niz[i]*10);
		
		while (var>0)
		{
		suma=suma+var%10;
		var=var/10;
		
		}
		
		 if (suma<k)
		{
			nizmanjih[p]=niz[i];
			p++;
		}
		
		else 
		{
			nizvecih[j]=niz[i];
			j++;
		}
	   
		
	}
	
	for (i=0; i<j; i++)
	{
		niz[i]=nizvecih[i];
		
		
	}
	
	for (i=j; i<vel; i++)
	{
		niz[i]=nizmanjih[r];
		r++;
		
	}

}




int main() {
float niz[1000];
int i,vel=0,k;

printf ("Unesite velicinu niza: ");
scanf ("%d", &vel);
printf ("Unesite niz: ");
for (i=0; i<vel; i++)
{
	scanf ("%f", &niz[i]);
	
}
printf ("Unesite k: ");
scanf ("%d", &k);
zaokruzi1(niz,vel);
for (i=0; i<vel; i++)
{
	printf ("\n%g", niz[i]);
}
printf ("\n");
printf ("\n");
preslozi (niz,vel,k);
for (i=0; i<vel; i++)
{
	printf ("%g\n", niz[i]);
}



	return 0;
}
