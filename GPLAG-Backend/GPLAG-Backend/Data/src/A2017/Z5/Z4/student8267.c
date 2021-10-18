#include <stdio.h>

int main() {
	printf("Zadaća 5, Zadatak 4");
	return 0;
}
/*#include <stdio.h>

void preslozi(int niz[], int n)
{
	int brojac=0;
	int cifra;
	int temp;
	int i;
	int prebaci=1;
	int j;
	for(i=0;i<n;i++)
	{
		prebaci=1;
		temp=niz[i];
		if(temp<0) temp*=-1;
		while(temp>0)
		{
			cifra=temp%10;
			temp/=10;
			if(cifra!=temp%10 && temp>0) prebaci=0;
		}
		if(prebaci) 
		{
			if(brojac!=i)
			{
				temp=niz[brojac];
				niz[brojac]=niz[i];
				for(j=i;j>brojac;j--) 
				{
					niz[j]=niz[j-1];
				}
				brojac++;
				niz[brojac]=temp;
			}
			else brojac++;
		}
	}
}

int main() 
{
	int niz[100],i=0,unos;
	int j;
	printf("Unesite brojeve: ");
	do
	{
		scanf("%d",&unos);
		if(unos==-1) break;
		else niz[i]=unos;
		i++;
	}while(i<100);
	preslozi(niz,i);
	printf("\nNakon poziva funkcije niz glasi: \n");
	for(j=0;j<i;j++)
	{
		if(j!=i-1) printf("%d,",niz[j]);
		else printf("%d.",niz[j]);
	}
	return 0;
}*/