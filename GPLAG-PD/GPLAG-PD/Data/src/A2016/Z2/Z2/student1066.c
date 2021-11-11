#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.1415926
int main() {
	float ugl[500];
	int n,st[500],min[500],sek[500],i,j;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		scanf("%f",&ugl[i]);
		if(ugl[i]>=0)
		{
		st[i]=(int)(ugl[i]*180/PI);
		min[i]=(int)(fabs(ugl[i]*180/PI-st[i])*60);
		sek[i]=(int)((fabs(ugl[i]*180/PI-st[i])*60-min[i])*60+0.5);
		if(sek[i]==60)
		{
			sek[i]=0;
			min[i]++;
		}
		if(min[i]==60)
		{
			min[i]=0;
			st[i]++;
		}
		}
		else
		{
		st[i]=(int)(ugl[i]*180/PI);
		min[i]=(int)(fabs(ugl[i]*180/PI-st[i])*60);
		sek[i]=(int)((fabs(ugl[i]*180/PI-st[i])*60-min[i])*60+0.5);
		if(sek[i]==60)
		{
		sek[i]=0;
		min[i]++;
		}
		if(min[i]==60)
		{
			min[i]=0;
			st[i]--;
	}
	}
	}
	printf("Uglovi su: \n");
	for(i=0;i<=n-1;i++)
	{
		if(sek[i]>30)
		{
		for(j=i;j<=n-2;j++)
		{
			st[j]=st[j+1];
			min[j]=min[j+1];
			sek[j]=sek[j+1];
		}
		i--;
		n--;
		}
	}
	for(i=0;i<=n-1;i++)
	{
		printf("%d stepeni %d minuta %d sekundi\n",st[i],min[i],sek[i]);
	}
	return 0;
}
