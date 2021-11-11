#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define VEL 500
#define EPS 0.001

int main() {
	int stepeni[VEL]={0},minute[VEL]={0},sekunde[VEL]={0};
	int n=0,i,j;
	double niz[VEL]={0},probna[VEL]={0},ostatak[VEL]={0};
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	if (n>500)
	{
		printf("Greska!");
		return 0;
	}
	for (i=0;i<n;i++)
	{
		scanf("%lf",&niz[i]);
	}
	for (i=0;i<n;i++)
	{
		niz[i]=(niz[i]*180)/PI;
	}
	for (i=0;i<n;i++)
	{
		
		stepeni[i]=(int)niz[i];
		probna[i]=(niz[i]-stepeni[i])*60;
		if (probna[i]<0)
		probna[i]*=-1;
		/*printf("stepeni %d\n",stepeni[i]);*/
		minute[i]=(int)probna[i];
		/*if (minute[i]<0)
		minute[i]*=-1;*/
		/*printf("minute %d\n",minute[i]);*/
		probna[i]=(probna[i]-minute[i])*60;
		if (probna[i]<0)
		probna[i]*=-1;
		/*printf("probn %lf\n",probna[i]);*/
		if (fabs(probna[i]-(int)probna[i])>EPS)
		{
			ostatak[i]=(probna[i]-(int)probna[i]);
			if (ostatak[i]<0)
			ostatak[i]*=-1;
			/*printf("ostaatak %lf\n",ostatak[i]);*/
			if (ostatak[i]<0.5)
			sekunde[i]=(int)probna[i];
			else
			sekunde[i]=(int)probna[i]+1;
		
			if (sekunde[i]<0)
			sekunde[i]*=-1;
			/*printf("sekude %d\n",sekunde[i]);*/
		}
		if (fabs(sekunde[i])>=60)
		{
			if (minute[i]<0)
			{
				minute[i]=minute[i]-1;
				minute[i]*=-1;
				sekunde[i]=0;
			}
			else
			{
				minute[i]+=1;
			    sekunde[i]=0;
			}
			/*printf("sad %d\n",minute[i]);*/
		}
		
		if (fabs(minute[i])>=60)
		{
			if (stepeni[i]<0)
			{
				stepeni[i]=stepeni[i]-1;
				minute[i]=0;
			}
			else
			{
				stepeni[i]=stepeni[i]+1;
			    minute[i]=0;
			}
		}
	}
	for (i=0;i<n;i++)
	{
		if (fabs(sekunde[i])>30)
		{
			for (j=i;j<n-1;j++)
			{
				sekunde[j]=sekunde[j+1];
				minute[j]=minute[j+1];
				stepeni[j]=stepeni[j+1];
			}
			n--;
			i--;
		}
	}

	printf("Uglovi su:\n");
	for (i=0;i<n;i++)
    {
		printf("%d stepeni %d minuta %d sekundi\n",stepeni[i],minute[i],sekunde[i]);
	}
	return 0;
}
