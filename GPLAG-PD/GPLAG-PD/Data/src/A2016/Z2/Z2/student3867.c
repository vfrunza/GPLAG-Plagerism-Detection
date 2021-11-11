#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() 
	{
		int i=0,j=0,n,step[500],min[500],sek[500];
		double rad[500];
		double ugao,psek;
		printf("Unesite broj uglova: ");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lf",&rad[i]);
			ugao=rad[i]*(180/PI);
			step[i]=(int)ugao;
			min[i]=(int)((ugao-step[i])*60);
			psek=((((ugao-step[i])*60)-min[i])*60);
			min[i]=abs(min[i]);
			sek[i]=round(psek);
			sek[i]=abs(sek[i]);
			if(sek[i]-59.5>0.00000000000000000000000000001)
			{
				sek[i]=0;
				min[i]+=1;
				if(min[i]==60)
				{
					min[i]=0;
					if(step[i]<0)
						step[i]-=1;
					else step[i]+=1;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			if(sek[i]>30)
			{
				for(j=i;j<n-1;j++)
				{
					step[j]=step[j+1];
					min[j]=min[j+1];
					sek[j]=sek[j+1];
				}
				n--;
				i--;
			}
		}
		printf("Uglovi su:\n");
		for(i=0;i<n;i++)
				printf("%d stepeni %d minuta %d sekundi\n",step[i],min[i],sek[i]);
		return 0;
	}