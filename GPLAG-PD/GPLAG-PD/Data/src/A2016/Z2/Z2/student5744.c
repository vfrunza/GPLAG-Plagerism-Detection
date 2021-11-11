#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.1415926

int main()
{
	int n,i,j;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	int st[500],min[500],sec[500];
	double a[500];
	for(i=0;i<n;i++)
	{
		scanf("%lf",&a[i]);
		a[i]=(a[i]*180)/pi;
		st[i]=a[i];
		a[i]=(a[i]-st[i])*60;
		min[i]=a[i];
		a[i]=(a[i]-min[i])*60;
		sec[i]=round(a[i]);
		if ((sec[i])>=60)
		{
			min[i]++;
			sec[i]=0;
		}
		if((min[i])>=60)
		{
			st[i]++;
			min[i]=0;
		}
		if(sec[i]<=-60)
		{
			min[i]--;
			sec[i]=0;
		}
		if((min[i])<=-60)
		{
			st[i]--;
			min[i]=0;
		}
		if (abs(sec[i])>30)
		{
			for(j=i;j<n-1;j++)
			{
				a[j]=a[j+1];
				st[j]=st[j+1];
				min[j]=min[j+1];
				sec[j]=sec[j+1];
			}
			i--;
			n--;
		}
	}
	printf("Uglovi su:\n");
	for(i=0;i<n;i++)
	{
		printf("%d stepeni %d minuta %d sekundi\n",st[i],abs(min[i]),abs(sec[i]));
	}
	return 0;
}