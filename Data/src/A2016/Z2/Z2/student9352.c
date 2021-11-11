#include <stdio.h>
#include <math.h>
#define broj_el 500
#define PI (3.1415926)

int main() 
{
	double niz[broj_el],stepen,minut,sekund;
	int i,n;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&niz[i]);
	}
	for(i=0;i<n;i++)
	{
		niz[i]*=(180./PI);
		stepen=niz[i];
		if(stepen>=0)
		{
			stepen=(int)stepen;
			niz[i]-=stepen;
		}
		else if(stepen<0)
		{
			stepen=(int)stepen;
			niz[i]=stepen-niz[i];
		}
		niz[i]=niz[i]*60;
		minut=niz[i];
		if(minut>=0)
		{
			minut=(int)minut;
			niz[i]-=minut;
		}
		else if(minut<0)
		{
			minut=fabs(minut);
			minut=(int)minut;
			niz[i]-=minut;
		}
		niz[i]*=60;
		sekund=niz[i];
		if(niz[i]<0)
		{
			sekund=fabs(sekund);
		    sekund+=0.5;

		}
		else if(niz[i]>=0)
		{
			sekund+=0.5;
		}
		sekund=(int)sekund;
		if(sekund==60)
		{
			minut += 1;
			sekund=0;
			if(minut==60)
			{
				minut=0;
				if(stepen>=0) stepen+=1;
				else          stepen-=1;
			}
		}
		
		if(i==0)
		{
			printf("Uglovi su:\n");
		}
		if(sekund>30) continue;
	
		printf("%g stepeni %g minuta %g sekundi\n",stepen,minut,sekund);
	}
	return 0;
}
