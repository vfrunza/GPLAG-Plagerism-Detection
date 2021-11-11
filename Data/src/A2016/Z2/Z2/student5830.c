#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
int main() {
	double a[500],us;
	int n,i,j,step,min,sec;
	

	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&a[i]);
	}
	printf("Uglovi su:\n");
	
	for(i=0;i<n;i++)
	{if(a[i]<0){us=-(((a[i]*180)/PI)*3600);}else{
			us=(((a[i]*180)/PI)*3600);}
	    us=(int)(us+0.5);
	    step=us/3600;
	    min=(us-step*3600)/60;
	    sec=(us-3600*step-60*min);
	    if(sec>=60){min++; sec=sec-60;}
	    if(min>=60){step++; min=min-60;}

		if(sec>30){
			for(j=i;j<n-1;j++)
			{
				a[j]=a[j+1];
			}
		n--;
		i--;
}
	}
	for(i=0;i<n;i++)
	{
if(a[i]<0){us=-(((a[i]*180)/PI)*3600);}else{
			us=(((a[i]*180)/PI)*3600);}

	    us=(int)(us+0.5);
	    step=us/3600;
	    min=(us-step*3600)/60;
	    sec=us-3600*step-60*min;
	    if(sec>=60){min++; sec=sec-60;}
	    if(min>=60){step++; min=min-60;}
	    if(a[i]<0){step=-step;}
			printf("%d stepeni %d minuta %d sekundi\n",step,min,sec);
	}

	return 0;
}
