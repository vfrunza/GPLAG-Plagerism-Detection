#include <stdio.h>
#define BROJ_EL 100
#define BROJEVI 1000

int main()
{
	int krajnje[2*BROJEVI], niz[BROJ_EL], niz_br[BROJEVI], niz_pravi[BROJEVI], n, i, j, brojac=0, z, k;
	
	
	for(i=0; i<2*BROJEVI; i++)
	{
		krajnje[i]=0;
	}
	
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d", &n);
	}while(n<0 || n>100);


	printf("Unesite clanove niza: ");
	for(i=0; i<n; i++) 
	{
		scanf("%d", &niz[i]);
		if(niz[i]<0) 
		{
			i--;
		}
	}

	for(i=n-1; i>=0; i--) 
	{
		do{
			niz_br[brojac]=niz[i]%10;
			niz[i]=niz[i]/10;
			brojac++;
		}while(niz[i]!=0);
	}

	for(i=brojac-1; i>=0; i--) 
	{
		niz_pravi[brojac-1-i]=niz_br[i];
	}


	k=0;
	printf("Finalni niz glasi: \n");
	z=niz_pravi[0];
	
	for(i=0; i<brojac; i++) 
	{
		j=i;
		krajnje[k]=niz_pravi[i];
	
		while(i<brojac && niz_pravi[i]==z) 
		{
			krajnje[k+1]++;
			i++;
		}
		
		z=niz_pravi[i];
		if(i!=j) i--;
		k=k+2;
	}
	
	for(i=0; i<k; i++)
	{
		printf("%d ", krajnje[i]);
	}

	return 0;
}