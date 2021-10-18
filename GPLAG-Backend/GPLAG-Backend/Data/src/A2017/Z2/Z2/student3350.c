#include <stdio.h>

int main() {
	int vel,i=0,j=0,s=0,k=0,l=0,br=0,p=0,n=0,niz[100];
	int pomocni[1000];
	int t=0;
	int final[1000];
	int brojac[9];
	do
	{
	printf("Unesite velicinu niza: ");
	scanf("%d",&vel);
	}
	while (vel>100||vel<0); 
	printf("Unesite clanove niza: ");
	for(i=0;i<vel;i++)
	{
		scanf("%d",&niz[i]);
	}	for(i=0;i<vel;i++)
	{
		if(niz[i]==0)
		{
			pomocni[k]=0;
			k++;
		}	
		while (niz[i]!=0) 
		{
			pomocni[k]=niz[i]%10;
			k++;
			niz[i]=niz[i]/10;
			
		}
		t=k;
		p=s;
		for(j=p;j<k;j++)
		{
		final[j]=pomocni[t-1];
		t--;
		s++;
		}
		}
		i=0;
	for(i=0;i<k;i++)
	{
		br=0;
		for(j=i;j<k;j++)
		{
			if(final[i]==final[j]) { br++; n++; }
			if(final[i]!=final[j]) break;
		}
		pomocni[l]=final[i];
		l++;
		pomocni[l]=br;
		l++;
		i=n-1;
	}
		printf("Finalni niz glasi: \n");
	for(i=0;i<l;i++)
	{
		printf("%d",pomocni[i]);
		printf(" ");
	}
	return 0;
	}	
	