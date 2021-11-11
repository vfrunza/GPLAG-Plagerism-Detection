#include <stdio.h>
int izbaci_cifre(int niz1[],int v1,int niz2[],int v2)
{
	int i=0,j;
	int q,p,k;
	int temp,brojac;
	int brponavljanja[1000]={0};
	while(i<v2)
	{
		if(niz2[i]<0 || niz2[i]>9) return 0;
		i++;
	}
	
	for(i=0;i<v2-1;i++)
	{
	brojac=0;
	for(j=i;j<v2;j++)
	{
		if(niz2[i]==niz2[j])
		brojac++;
	}
	brponavljanja[i]=brojac;
	}
	for(i=0;i<v2-1;i++)
	if(brponavljanja[i]>1) return 0;
	
	for(i=0;i<v1;i++)
	{
		q=niz1[i];
		k=0;
		temp=1;
		while(q!=0)
		{
			p=(q%10);
			if(p<0) p*=-1;
			brojac=0;
			for(j=0;j<v2;j++)
			{
				if(p!=niz2[j]) brojac++;
			}
				if(brojac==v2 && niz1[i]>=0)
				{
				k+=p*temp;
				temp*=10;
				}
				if(brojac==v2 && niz1[i]<0)
				{
				k-=p*temp;
				temp*=10;
				}
			q/=10;
		}
		niz1[i]=k;
	}
	return 1;
}
int main() 
{
int brojevi[] = {12345, -12345};
int cifre[] = {3,5};
int i;
izbaci_cifre(brojevi,1, cifre, 1);
printf("%d %d", brojevi[0], brojevi[1]);
return 0;
}
