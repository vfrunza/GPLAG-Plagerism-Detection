#include <stdio.h>
#include <math.h>
int zaokruzil(float niz[],int n)
{
	int i;
	for(i=0; i<n; i++) {
		niz[i]=niz[i]-0.009;
		niz[i]=ceilf(niz[i]*100)/100;
		niz[i]=roundf(niz[i]*10)/10;
	}
	return 0;
}
int preslozi(float niz[],int n,int k)
{
	int i,x,y,z=0,br=0;
	float swap;
	zaokruzil(niz,n);
	for(i=0;i<n;i++)
	{
		x=niz[i];
		y=(niz[i]-x)*10;
		while(x>0)
		{
			z=z+(x%10);
			x=x/10;
		}
		z=z+y;
		if(z>=k)
		{
			swap=niz[i];
			niz[i]=niz[br];
			niz[br]=swap;
			br=br+1;
			z=0;
		}
		else
		{
			z=0;
		}
	}
	return 0;
}

int main()
{

	return 0;
}
