#include <stdio.h>
#include <math.h>
#define pi 3.1415926
#define broj_el 500

int main() {
	int i;
	int j;
	int brojuglova;
	double uglovi[broj_el];
	int step[broj_el];
	int sekunde[broj_el];
	int minute[broj_el];
	int neg[broj_el];
	
	do
	{
	printf("Unesite broj uglova: ");
	scanf("%d",&brojuglova);
	}
	while(brojuglova<0 || brojuglova>500);
	
	
	
	for(i=0;i<brojuglova;i++)
	{
		scanf("%lf",&uglovi[i]);
	}
	
	
	for(i=0;i<brojuglova;i++)
	{
		neg[i]=0;
		if(uglovi[i]<0)
		{
			neg[i]=1;
		}
		uglovi[i]=fabs(uglovi[i]); 
		
		uglovi[i]=uglovi[i]*180/pi;
		step[i]=floor(uglovi[i]);
		minute[i]=floor((uglovi[i]-step[i])*60);
		sekunde[i]=floor(((uglovi[i]-step[i])*60-minute[i])*60);
		if(((uglovi[i]-step[i])*60-minute[i])*60-sekunde[i]>0.5)
		{sekunde[i]++;}
		if(sekunde[i]==60)
		{sekunde[i]=0; minute[i]++;}
		if(minute[i]==60)
		{minute[i]=0; step[i]++;} 
	}
	
	for(i=0;i<brojuglova;i++)
	{
		if(sekunde[i]>30)
		{
		for(j=i;j<brojuglova-1;j++)
		{
				step[j]=step[j+1];
				minute[j]=minute[j+1];
				sekunde[j]=sekunde[j+1];
		}
				brojuglova--;
				i--;
		}
	}
	
	printf("Uglovi su: \n");
	for(i=0;i<brojuglova;i++)
	{
		if(neg[i]==1)
		{
			printf("-");
		}
		printf("%d stepeni %d minuta %d sekundi\n",step[i],minute[i],sekunde[i]);
	} 
	
	return 0;
}