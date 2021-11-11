#include <stdio.h>

void ubaci(int niz[], int vel)
{
	int i,j;int broj, ibroj=0;

	
	for(i=1; i<vel; i++)
	{   
		if(i%2!=0)
		{
		broj=niz[i-1]; ibroj=0;
		if(broj<0) broj=-1*broj;
		while(broj!=0)
		{
			ibroj+=broj%10;
			broj/=10;
		}
		for(j=vel;j!=i;j--)
			niz[j]=niz[j-1];
		vel++;
        niz[i]=ibroj;
		}
	}
	
	    broj=niz[vel-1]; ibroj=0;
		if(broj<0) broj=-1*broj;
		while(broj!=0)
		{
			ibroj+=broj%10;
			broj/=10;
		}
    	niz[vel]=ibroj;
	
}

int fibonaci(int x)
{
	long clan[3]={1, 1, 2};
	int da_ne;
	if(x==1 || x==2) return 1;
	while (clan[2]<x)
	{
		clan[0]=clan[1];
		clan[1]=clan[2];
		clan[2]=clan[0]+clan[1];
	}
	if(clan[2]>x) da_ne=0;
	if(clan[2]==x) da_ne=1;
	return  da_ne;
}

int izbaci (int niz[],int vel)
{
	int i,j;
	
	for(i=0;i<vel;i++)
		if(fibonaci(niz[i]))
		{
			for(j=i;j<vel-1;j++)
			 	niz[j]=niz[j+1];
			i--;
			vel--;
			
		}
	return vel;
}

int main()
{
    int niz[200]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, broj_f=0, broj_elemenata=20;

	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	{  
		scanf("%d",&niz[i]);
	}
	
	ubaci(niz, 20);
    broj_elemenata=izbaci(niz,20);
    
	printf("Modificirani niz glasi:");
	for(i=0; i<broj_elemenata; i++)
	{
		if(niz[i]!=0)
		{
		         if(broj_f>0) printf(",");
		         printf(" %d", niz[i]);
		         broj_f++;
	    }
	}
	if(broj_f==0) printf("Prazan niz.");
	else printf(".");
	return 0;
}

