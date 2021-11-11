#include <stdio.h>
void ubaci( int *niz,int vel)
{
	int i,j;
	int n,s;
	for(i=0;i<vel;i++)
	{
		for(j=vel-1;j>i;j--)
		{
			niz[j+1]=niz[j];
		}
		n=niz[i];
		if(n<0)n*=-1;
		s=0;
		while(n!=0)
		{
			s+=n%10;
			n/=10;
		}
		niz[i+1]=s;
		i++;
		vel++;
	}
}

	 

int izbaci (int *niz,int vel)
{
	int i,j,br=0;
	 int prvi, drugi, fibonacijev;
	for( i=0;i<vel-br;i++)
	{
		niz[i]=niz[i+br];
	 prvi=1;
	 drugi=1;
		while(niz[i]>prvi && niz[i]>drugi)
		{
		 prvi=prvi+drugi;
		 drugi=prvi+drugi;
		}
		if(niz[i]==prvi || niz[i]==drugi) fibonacijev=1;
		else fibonacijev=0;
	 	if(fibonacijev==1)
	 	{
	 		br++;
	 		i--;
		}
	}
	return vel-br;
}
int main() {
	int i,vel;
	int niz[20];
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	scanf("%d",&niz[i]);
	ubaci(niz,10);
	vel=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<vel;i++)
	{
	printf("%d",niz[i]);
	if(i!=vel-1)printf(", ");
	else printf(".");
	}
	return 0;
}
