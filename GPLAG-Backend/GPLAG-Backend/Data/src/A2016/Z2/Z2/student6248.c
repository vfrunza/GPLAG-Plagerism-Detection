#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int n,i,j,stepeni,minute,sekunde;
	double niz[500],clan,pom;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
	{
		scanf("%lf",&niz[i]);
	}

	for(i=0; i<n; i++) 
	{
		clan=fabs((double)(niz[i]*180/PI)); 
		stepeni=(int)clan;                  
		minute=(int)((clan-stepeni)*60);    
		pom=(((clan-stepeni)*60)-minute)*60; 
		if(pom-(int)pom!=0 || pom==0)
		{
			if(pom==0) sekunde=0;
			else pom=(int)(pom+0.5);
			sekunde=pom;  
			if(sekunde==60)
			{
				sekunde=0;
				minute++;
			}
		}
		if(niz[i]==0)
		{
			stepeni=0;
			minute=0;
			sekunde=0;
		}
		if(sekunde>30)   
		{
			for(j=i; j<n-1; j++)
			{
			niz[j]=niz[j+1];
			}
		n--;
		i--;
		}
	}
	printf("Uglovi su:");
	for(i=0; i<n; i++)
	{
		clan=fabs((double)(niz[i]*180/PI));
		stepeni=(int)clan;
		minute=(int)((clan-stepeni)*60);
	
		pom=(((clan-stepeni)*60)-minute)*60;
		if(pom-(int)pom!=0 || pom==0)
		{
			if(pom==0) sekunde=0;
			else pom=(int)(pom+0.5);
			sekunde=pom;
			if(sekunde==60) 
			{
				sekunde=0;
				minute++;
			}
		}
		if(minute==60)
		{
			minute=0;
			stepeni++;
		}
		if(niz[i]==0)
		{
			stepeni=0;
			minute=0;
			sekunde=0;
		}
		if(niz[i]<0)
		{
			stepeni*=(-1);
		}
		printf("\n%d stepeni %d minuta %d sekundi",stepeni,minute,sekunde);
	}
	return 0;
}
