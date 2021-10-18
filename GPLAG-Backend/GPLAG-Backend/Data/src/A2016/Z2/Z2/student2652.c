#include <stdio.h>
#define PI 3.1415926
#include <math.h>
#define EPSILON 0.000001

int main() {
	int n,i,j;
	double niz[500],sekunde[500],minute[500],stepeni[500],sekunde0[500];
	printf("Unesite broj uglova: ");
	do
	{
		scanf("%d",&n);
	}
	while (n<1 || n >500);
	
	for (i = 0; i<n; i++)
	{
		scanf("%lf",&niz[i]);
		niz[i]=niz[i]*180/PI;
		stepeni[i]=niz[i];
		minute[i]=(stepeni[i]-(int)stepeni[i])*60;
		stepeni[i] = (int)stepeni[i];
		sekunde[i]=(minute[i]-(int)minute[i])*60;
		minute[i] = (int)minute[i] ;
		sekunde0[i]=sekunde[i];
		sekunde[i]=round(sekunde[i]); 
		if (fabs(sekunde[i]-60)<EPSILON){minute[i]=minute[i]+1;sekunde[i]=0;}
		if (fabs(sekunde[i]+60)<EPSILON){minute[i]=minute[i]-1;sekunde[i]=0;}
		if (fabs(minute[i]-60)<EPSILON){stepeni[i]=stepeni[i]+1;minute[i]=0;}
		if (fabs(minute[i]+60)<EPSILON){stepeni[i]=stepeni[i]-1;minute[i]=0;}
		/*printf("*%g* %g* %g*",stepeni[i],minute[i],sekunde[i]);*/
	}
	
	for (i = 0; i<n; i++)
	{
	/*	printf("%f",sekunde[i]); */
		if ((sekunde[i]>30) || (sekunde[i]<-30))
		{
			for (j = i; j<n-1;j++)
			{
				niz[j]=niz[j+1];
				stepeni[j]=stepeni[j+1];
				minute[j]=minute[j+1];
				sekunde[j]=sekunde[j+1];
			}
			i = i-1;
			n = n-1;
		}
/*	printf("##%d##",n); */	
	}
/*	printf("$$%d$$",n); */
	printf("Uglovi su: \n");
	for (i = 0; i<n;i++)
	{
		if (stepeni[i]<0) {minute[i]=fabs(minute[i]); sekunde[i] = fabs(sekunde[i]);} 
		printf("%g stepeni %g minuta %g sekundi\n",stepeni[i],minute[i],sekunde[i]);
	}
	
	
	return 0;
}
