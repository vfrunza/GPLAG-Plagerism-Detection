#include <stdio.h>
int ne_sadrzi(int* niz,int velicina,int broj)
{
	int i;
	for(i=0;i<velicina;i++)
	{
		if(niz[i]==broj)
		return 0;
	}
	return 1;
}
int ne_sadrzi_kopiju(int* niz,int velicina,int broj,int indeks)
{
	int i;
	for(i=0;i<velicina;i++)
	{
       if(niz[i]==broj && i>indeks)
       return 0;
	}
	return 1;
}
int dva_od_tri(int* niza,int velicinaA,int* nizb, int velicinaB,int* nizc,int velicinaC)
{
	int i,j,k;
	int n=0;
	int m=0;
	
	for(i=0;i<velicinaA;i++)
	{
		n=0;
		for(j=0;j<velicinaB;j++)
		{
			if(niza[i]==nizb[j])
			{
				n=1;
				break;
			}
		}
		
		for(k=0;k<velicinaC;k++)
		{
			if(niza[i]==nizc[k] && n==1)
			{
				n=0;
				break;
			}
			else if(niza[i]==nizc[k] && n==0)
			{
				n=1;
				break;
			}
		}
		
		if(n==1 && ne_sadrzi_kopiju(niza,velicinaA,niza[i],i))
		m++;
	}
	
	for(i=0;i<velicinaB;i++)
	{
		for(j=0;j<velicinaC;j++)
		{
			if(nizb[i]==nizc[j] && ne_sadrzi(niza,velicinaA,nizb[i]) && ne_sadrzi(niza,velicinaA,nizc[j]) && ne_sadrzi_kopiju(nizb,velicinaB,nizb[i],i) && ne_sadrzi_kopiju(nizc,velicinaC,nizc[j],j))
	        m++;
		}
	}
	return m;
}
int main() {
	
	int i,velicinaA,velicinaB,velicinaC,niza[1000],nizb[1000],nizc[1000],rezultat;
	
	printf("Unesi velicinu niza A:");
	do 
	{
		scanf("%d", &velicinaA);
	} while(velicinaA<1 || velicinaA>1000);
	
	printf("Unesi clanove niza a:");
	for(i=0;i<velicinaA;i++)
	{
		scanf("%d", &niza[i]);
	}
	
	printf("\nUnesi velicinu niza B:");
	do 
	{
		scanf("%d", &velicinaB);
	} while(velicinaB<1 || velicinaB>1000);
	
	
	printf("\nUnesi  clanove niza b:");
	for(i=0;i<velicinaB;i++)
	{
		scanf("%d", &nizb[i]);
	}
	
	printf("\nUnesi velicinu niza C:");
	do 
	{
		scanf("%d", &velicinaC);
	} while(velicinaC<1 || velicinaC>1000);
	
	printf("Unesi clanove niza C:");
	for(i=0;i<velicinaC;i++)
	{
		scanf("%d",&nizc[i]);
	}
	
	rezultat=dva_od_tri(niza,velicinaA,nizb,velicinaB,nizc,velicinaC);
	printf("%d", rezultat);
	
	
	
	return 0;
}
