#include <stdio.h>
#define pi 3.1415926
#include <math.h>
#include <stdlib.h>
int main() {
	int n,i,p,j, step[500], min[500], sec[500];
	double s[500],r[500], k,o;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for (i=0;i<n; i++ )
	{
		scanf("%lf", &r[i]);
	}
	for (i=0;i<n; i++)
	{
		s[i]=fabs (r[i])*(180./pi);
		p=s[i]*3600;
		k=s[i]*3600;
		o= k-p;
		if(o>0.5)
		p++;
		step[i]= p/3600;
		min[i]=fabs((p%3600)/60);
		sec[i]=(p%3600)%60;
	
	
		if(sec[i]>30)
		{
			for(j=i; j<n; j++)
			{
			s[j]=s[j+1];
		    r[j]=r[j+1];
		    step[j]=step[j+1];
		    min[j]=min[j+1];
		    sec[j]=sec[j+1];
			}
			i--;
			n--;
		}
		
	}
	printf("Uglovi su:\n");
	for (i=0; i<n;i++)
	{
	if(r[i]<0)
	printf("-%d stepeni %d minuta %d sekundi\n", step[i], min[i], sec[i]);
	else
	printf("%d stepeni %d minuta %d sekundi\n", step[i], min[i], sec[i]);
	}
	return 0;
}
