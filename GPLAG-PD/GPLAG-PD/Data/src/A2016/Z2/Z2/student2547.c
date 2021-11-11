#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
int main() {
	int i,n,j=0;
	double se=0;
	int nizs[500]={0},nizm[500]={0},nizsekundi[500]={0};
	int s=0,m=0,sekunda=0; 
	double uglovi[500]={0};
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&uglovi[i]);
		if(i==n-1)
		{
			printf("Uglovi su:\n");
		}
	}
	for(i=0;i<n;i++)
	{
		se=(uglovi[i]*180/PI)*3600;
		if(se<0)
		{
			se=(int)(se-0.5);
		}
		else se=(int)(se+0.5);
		s=se/3600;
		m=(se-s*3600)/60;
		sekunda=se-s*3600-m*60;
		sekunda=abs(sekunda);
		m=abs(m);
		if(sekunda>=60)
		{
			m++;
			sekunda-=60;
		}
		if(m>=60)
		{
			s++;
			m-=60;
		}
		nizs[i]=s;
		nizm[i]=m;
		nizsekundi[i]=sekunda;
		if(sekunda>30 || sekunda<-30)
		{
			for(j=i;j<n-1;j++)
			{
				uglovi[j]=uglovi[j+1];
				nizs[j]=nizs[j+1];
				nizm[j]=nizm[j+1];
				nizsekundi[j]=nizsekundi[j+1];
			}
			n--;
			i--;	
		}
		
	}
	for(i=0;i<n;i++)
	{
		printf("%d stepeni %d minuta %d sekundi\n",nizs[i],nizm[i],nizsekundi[i]);
	}
	return 0;
}
