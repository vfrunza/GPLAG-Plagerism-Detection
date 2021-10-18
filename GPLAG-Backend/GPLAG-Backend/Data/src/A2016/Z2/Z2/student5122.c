#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define MAX 500

int main() {
	int n, i, j ;
	int pom[500]={0,0,0};
	double niz[MAX], sec, min, step;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%lf", &niz[i]);
	if(niz[i]<0)
	{
		pom[i]=1;
	}
	}
	printf("Uglovi su:\n");
	for(i=0;i<n; i++){
	step=niz[i]*180/PI;
	min=(step-(int)step)*60;
	sec=(min-(int)min)*60;
    if(pom[i])
    {
    	step*=(-1);
    	min=fabs(min);
    	sec=fabs(sec);
    }
	if((sec>0 && sec-(int)sec>=0.5))
	{
	sec+=0.5;
	sec=(int)sec;
	}
	else
	sec=(int)sec;
	if(sec==60)
	{
		sec=0;
		min++;
	}
	if(sec-30>0.00001)
		{
		for(j=i; j<n-1; j++)
		{
			niz[j]=niz[j+1];
		}
		n--;
		i--;
	}
if(sec>=0 && sec-30<0.00001)
{
	step=(int)step;
	min=(int)min;
	if(min==60)
	{
		min=0;
		step++;
	}
 if(pom[i])
    {
    	step*=(-1);
    	
    }
	printf("%g stepeni %g minuta %g sekundi\n", step,min,sec);
}
}
	return 0;
}
