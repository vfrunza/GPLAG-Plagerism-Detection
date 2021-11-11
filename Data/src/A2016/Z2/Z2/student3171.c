#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define E 0.00001

int main() {
	
	int n, i;
	float niz[500];
	float stepeni, step, sek, sekz, min, min1; 
	int neg_poz=0;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		scanf("%f", &niz[i]);
	}
	
	printf("Uglovi su: ");
	
	for(i=0; i<n; i++)
	{
		stepeni=0;
		step=0;
		sek=0;
		sekz=0;
		min=0;
		min1=0;
		
		stepeni=fabs(niz[i]*180)/PI;
		step=(int)(stepeni);
		
		if(fabs(stepeni-step)<E || fabs(step-stepeni)<E)
		{
			min1=0;
			sekz=0;
		}
		
		
		else {
		min=(stepeni-step)*60;
		min1=fabs((int)(min));
		
		if(fabs(min-min1)<E || fabs(min1-min)<E)
			sekz=0;
			
		else 
		{
			sek=(fabs(min)-min1)*60;
			sekz=(int)(sek + 0.5);
		
		}
		}
		
		if(sekz>=60) 
		{
			sekz=sekz-60;
			min1=min1+1;
		}
		
		if(min1>=60)
		{
			min1=min1-60;
			step=step+1;
		}
		
		
		if(niz[i]<0) neg_poz=-1;
		else neg_poz=1;
		if(sekz<=30) printf("\n%.f stepeni %.f minuta %.f sekundi", neg_poz*step, min1, sekz);
	
		
	}
	
	
	
	return 0;
}
