#include <stdio.h>

int main() 
{
	char a;
	int n,i,clan,niz1[100]={0},niz2[1000]={0},brojac=0;
	int brojac2=0;
	int cifra;
	do
	{
		printf("Unesite velicinu niza: ");
		scanf("%d",&n);
		if(n<=0 || n>100) printf("Unesite prirodan broj!\n");
	}while(n<=0 || n>100);
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++)
	{
		int uspjeh=1;
		do
		{
			uspjeh=scanf("%d",&clan);
			if(clan<0) printf("Unesite prirodan broj!");
			else if(uspjeh==0) 
			{
				printf("Ne mozete unijeti slovo\n");
				a=getchar();
			}
		}while(clan<0 || uspjeh==0);
		niz1[brojac]=clan;
		brojac++;
	}
	brojac--;
	cifra=niz1[brojac]%10;
	for(i=brojac;i>=0;i--)
	{
		if(niz1[i]==0) 
		{
			
			niz2[brojac2+1]=0;
			niz2[brojac2]=1;
			brojac2+=2;
		}
		while(niz1[i]>0)
		{
			cifra=niz1[i]%10;
			niz2[brojac2+1]=cifra;
			niz2[brojac2]++;
			if(cifra!=(niz1[i]/10)%10 && niz1[i]>=10) 
			{
				brojac2+=2;
			}
			else 
			{
				if(i>0)
				{
					if(niz1[i]<10 && niz1[i-1]%10!=cifra) brojac2+=2;
				}
			}
			niz1[i]/=10;
		}
	}
	printf("Finalni niz glasi: \n");
	for(i=brojac2+1;i>=0;i--)
	{
		printf("%d ",niz2[i]);
	}
	return 0;
}