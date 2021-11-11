#include <stdio.h>
#define PI 3.1415926
#include <math.h>
int main() {
	int i,j,n,step,min,sec;
	double niz[500];
	printf("Unesite broj uglova:");
	do
		{scanf("%d",&n);
			
		}
	while(n<0 || n>500);
	for(i=0;i<n;i++)
		{
			scanf("%lf",&niz[i]);
			
		}
	printf(" Uglovi su:\n");
	for(i=0;i<n;i++)
    {
    	niz[i]=niz[i]*180/PI;
    	step=(int)(niz[i]);
    	min=(int)((fabs(niz[i])-fabs(step))*60);
    	sec=(int)((((fabs(niz[i])-fabs(step))*60)-fabs(min))*60+0.5);
    	
    	if (sec==60) {min++;sec=0;}
    		
    	if(niz[i]>0 && min==60) {step++;min=0;}
    		else if(niz[i]<0 && min==60) {step--;min=0;}
    	
    	if (sec>30)
    	{
    		for (j=i;j<n-1;j++)
    		{   
    			niz[j]=niz[j+1];
			}
		n--;
    	i--;
    	}
    
    	else printf("%d stepeni %d minuta %d sekundi\n",step,min,sec);
    	
    	
    }
	return 0;
}
