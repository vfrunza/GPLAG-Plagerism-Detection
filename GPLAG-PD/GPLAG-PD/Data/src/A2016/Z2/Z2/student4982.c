#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
int main() {
	
	int n,i,j;
	double uglovi[500],stepeni[500],minute[500],sekunde[500];
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	if(n<=0 || n>500)
	{ printf("Pogresan unos\n"); return 0;}
	for(i=0;i<n;i++)
	{
		scanf("%lf",&uglovi[i]);
	}
	
	for(i=0;i<n;i++)
	{   
		stepeni[i]=uglovi[i]*180/PI;
		minute[i]=(fabs(stepeni[i])-fabs((int)stepeni[i]))*60;
		sekunde[i]=(minute[i]-(int)minute[i])*60;
		if(sekunde[i] - (int)sekunde[i]>=0.5) {sekunde[i]=(int)sekunde[i]+1;}
		if(sekunde[i]>=60) {minute[i]++; sekunde[i]-=60;}
		if(stepeni[i]>0 &&minute[i]>=60) {stepeni[i]++; minute[i]-=60;}
		if(stepeni[i]<0 &&minute[i]>=60) {stepeni[i]--; minute[i]-=60;}
		
		
	}
	for(i=0;i<n; i++) {
		if(sekunde[i]>30)
		{
			for(j=i;j<n-1;j++)
			{
				stepeni[j]=stepeni[j+1];
				minute[j]=minute[j+1];
				sekunde[j]=sekunde[j+1];
				
			}
			n--; i--;
		}
		
	}
	
	printf("Uglovi su:\n");
	for(i=0;i<n;i++)
	{
		printf("%d stepeni %d minuta %d sekundi\n", (int)stepeni[i],(int)minute[i],(int)sekunde[i] );
	}

	
	return 0;
}
