#include <stdio.h>
#include <math.h>

int main() {
	int niz[100],pomocni[10000],ispis[1000],velicina,i=0,h=0,j=0,brojac;
	do
	{
		printf("Unesite velicinu niza: ");
		scanf("%d",&velicina);
	}
	while(velicina<=0);
	printf("Unesite clanove niza: ");
	
	for(i=0;i<velicina;i++)
	{
		do
		{
			scanf("%d",&niz[i]);
		}
		while(niz[i]<0);
	}
	for(i=0;i<velicina;i++)
	{
			int pom=niz[i],brojac=0;
			do
			{	
				
				pom/=10;
				brojac++;
			}
			while(pom>0);
			
			for(j=brojac;j>0;j--)
			{
				pomocni[h]=niz[i]/(pow(10,j-1));
				niz[i]=niz[i]%((int)pow(10,j-1));
				h++;
			}
		
	}

	j=0;
	for(i=0;i<h;i++)
	{	brojac=0;
		ispis[j]=pomocni[i];
		j++;
	
		do
		{
			brojac++;
			if(i+brojac>=h)
			break;
		}
		while(pomocni[i]==pomocni[i+brojac]&&i<h);
		ispis[j]=brojac;
		i+=brojac-1;
		j++;
		
	}
	
	printf("Finalni niz glasi:\n");
	for(i=0;i<j;i++)
	{
		printf("%d ",ispis[i]);
	}
	
	
	
	return 0;
}
