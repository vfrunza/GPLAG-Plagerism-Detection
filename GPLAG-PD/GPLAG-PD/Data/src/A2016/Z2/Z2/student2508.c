#include <stdio.h>
#define PI 3.1415926
#include <stdlib.h>
#include <math.h>
int main() {
	int n,i,j;
	double ugao[500],min[500],sec[500];
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&ugao[i]);
		ugao[i]=ugao[i]*180/PI;
		min[i]=(fabs(ugao[i])-abs((int)ugao[i]))*60;
		sec[i]=(min[i]-(int)min[i])*60;
		sec[i]=(int)(sec[i]+0.5);
		if (sec[i]>=60)
		{
		min[i]=min[i]+1;
		sec[i]=0;
		}
		if(min[i]>=60)
			{
				if(ugao[i]>=0)
				ugao[i]=ugao[i]+1;
				else
				ugao[i]=ugao[i]-1;
			min[i]=0;
			}
			if(sec[i]>30)
		{
			for(j=i;j<n-1;j++)
			{
				ugao[j]=ugao[j+1];
			}
		n--;
		i--;
		}
	}
	
	
	printf("Uglovi su: ");
	for(i=0;i<n;i++)
	{
	printf("\n%d stepeni %d minuta %d sekundi",(int)ugao[i],(int)min[i],(int)sec[i]);	
	}
	return 0;
}
