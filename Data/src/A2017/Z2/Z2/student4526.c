#include <stdio.h>

int main() {
	int niz[100],velicina_niza,i,j, niz2[100];
	int brojac,clan[10],clan1,pomak=0,k=0;
	do{
	printf("Unesite velicinu niza: ");
	scanf ("%d", &velicina_niza);
	}while (velicina_niza<=0 || velicina_niza>100);
	printf ("Unesite clanove niza: ");
	
	for (i=0; i<velicina_niza; i++)
	{
		scanf("%d",&clan1);
		brojac=0;
		do
		{
			clan[brojac]=clan1%10;
			brojac++;
			clan1/=10;
		}while(clan1);
		for(j=0;j<brojac;j++)
		{
			niz[pomak+j]=clan[brojac-j-1];
		}
		pomak+=brojac;
	}
	for(i=0;i<pomak;i++)
	{
		brojac=0;
		for(j=i;j<pomak;j++)
		{
			if(niz[j]==niz[i])
			brojac++;
			else break;
		
		}
		niz2[k++]=niz[i];
		niz2[k++]=brojac;
		i+=brojac-1;
	}
	printf("Finalni niz glasi: \n");
	for(i=0;i<k;i++)
	{
		printf("%d ",niz2[i]);
	}
	return 0;
}
