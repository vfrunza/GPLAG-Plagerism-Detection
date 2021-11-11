#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.1415926
#define maxi 500
int main() {
	int n,st,m,s1,i,p=0,stepen[maxi],min[maxi],sk[maxi];
	double a[maxi],ugao,s;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lf",&a[i]);
	printf("Uglovi su: \n");
	for(i=0;i<n;i++)
	{
		ugao=a[i]*180/PI;
		
		while(ugao>360)
		{
			ugao-=360;
		}
		while(ugao<-360)
		{
			ugao+=360;
		}
		
		s=ugao*3600;
		s=round(s);
		s1=s;
	
		st=ugao;
		m=(s1-st*3600)/60;
		s1=s1%60;
		if(m==60)
		{
			m=0;
			st++;
		}
		else if(m==-60)
		{
			m=0;
			st--;
		}
		sk[i]=abs(s1);
		stepen[i]=st;
		min[i]=abs(m);
		
	}
	
	for(i=0;i<n;i++)
	{
		if(sk[i]<=30)
		{
			sk[p]=sk[i];
			min[p]=min[i];
			stepen[p]=stepen[i];
			p++;
		}
	}
	
	for(i=0;i<p;i++)
	{
		printf("%d stepeni %d minuta %d sekundi\n",stepen[i],min[i],sk[i]);
	}
	return 0;
}