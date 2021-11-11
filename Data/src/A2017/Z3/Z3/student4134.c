#include <stdio.h>


int izbaci_cifre ( int nizN[], int n, int nizM[], int m )
{
	int i,j,l,brojac=0,predznak=1,temp;
	int brojaccifri=0;
	int broj[100];
	
	for(i=0;i<n;i++)
	{
		brojac=0;
		temp=0;
		predznak=1;
		if(nizN[i]<0)
		{
			predznak=-1;
			nizN[i]*=-1;
		}
		
		/*Rastavljamo broj na cifre i smjestamo cifre u poseban niz*/
		
		while(nizN[i]!=0)
		{
			broj[brojac]=nizN[i]%10;
			nizN[i]/=10;
			brojac++;
		}
		
		/*Sve cifre koje trebamo izbaciti stavljamo na -1*/
		
		for(j=0;j<m;j++)
		{
			for(l=0;l<brojac;l++)
			{
				if (broj[l]==nizM[j]) broj[l]=-1;
			}
		}
		
		/*Pravimo novi broj od cifri koje nisu -1*/
		
		for(l=0;l<brojac;l++)
		{
			if(broj[l]!=-1)
			{
				temp+=broj[l];
				temp*=10;
			}
		}
		temp/=10;
		while(temp!=0)
		{
			nizN[i]+=temp%10;
			nizN[i]*=10;
			temp/=10;
		}
		nizN[i]/=10;
		nizN[i]*=predznak; /*Vracamo brojeve sa izbacenim ciframa u niz*/
	}
	
	/*Ako drugi niz nije pravilno unesen vracamo vrijednost 0*/
	
	for(i=0;i<m;i++)
	{
		brojaccifri=0;
		if(nizM[i]>9 || nizM[i]<0) return 0;
		for(j=0;j<m;j++)
		{
			if(nizM[i]==nizM[j]) brojaccifri++;
		}
		if (brojaccifri>1) return 0;
	}
	return 1;
}

int main () 
{
	int niz1[]={5413,4565,-23634,9146,-606};
	int niz2[]={1,4};
	printf("%d",izbaci_cifre(niz1,5,niz2,2));
	return 0;
}

