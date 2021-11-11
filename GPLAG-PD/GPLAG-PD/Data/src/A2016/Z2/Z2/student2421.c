#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {

	double x[500];
	int sekunde,st,m,s,i,n,j;
	int minu;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&x[i]);
	}
	
	for(i=0;i<n;i++)
	{
		sekunde=(x[i]*180*3600)/PI;
		if(sekunde<0){sekunde*=-1;}
			if(fabs(sekunde-fabs((x[i]*180*3600)/PI))>0.5)sekunde++;
		st=sekunde/3600;
		m=sekunde%3600/60;
		s=sekunde%3600%60;
		if(s>30)
		{
			for(j=i;j<n-1;j++)
			{
				x[j]=x[j+1];
			}
			n--;
			i--;
		}
	}
	printf("Uglovi su:\n");
	for(i=0;i<n;i++)
	{
		minu=0;
		sekunde=x[i]*180*3600/PI;
		if(sekunde<0){sekunde*=-1;minu=1;}
		if(fabs(sekunde-fabs((x[i]*180*3600)/PI))>0.5)sekunde++;
		
		st=sekunde/3600;
		m=sekunde%3600/60;
		s=sekunde%3600%60;
		if(minu==1)printf("-");
		printf("%d stepeni %d minuta %d sekundi\n",st,m,s);
	}
	return 0;
}
