#include <stdio.h>

void ubaci (int *niz, int vel)
{	
	int i, j, suma=0,broj;
	for (i=0; i< vel; i++)
	{
		suma=0;
		broj = niz[i];
		while(broj!=0) 
		{
			suma+= broj%10;
			broj/=10;
		}
		if (suma<0) suma*=-1;
		for (j=vel; j>i+1; j--)
			niz[j]= niz[j-1];
		
		niz[i+1]=suma;	
		vel++; 
		i++;
	}
}

int izbaci (int *niz, int vel)
{
	int fib[500];
	int i, j, k, pret=0;
	
	fib[0]=1;
	fib[1]=1;
	for (i=1; i<400; i++)
	{
		fib[i+1]= fib[i] + fib[i-1];
	}
	
	
	for (i=0; i< vel; i++)
	{
		pret=0;
		for (j=0; j<400; j++){
			if(fib[j]==niz[i]) pret=1;
		}	
		if(pret==1)
		{
			for (k=i; k<vel-1; k++)
				niz[k] = niz[k+1];
			i--;
			vel--;
		}
	}
	return vel;
}



int main() {
	int niz[500];
	int i, vel=20;
	printf ("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++)
	{
		scanf ("%d",&niz[i]);
	}
	
	ubaci(niz,10);
	vel = izbaci(niz,20);
	
	printf ("Modificirani niz glasi: ");
	for (i=0; i<vel-1; i++)
	{
		printf ("%d, ",niz[i]);
	}
	printf ("%d.",niz[vel-1]);
	return 0;
}
