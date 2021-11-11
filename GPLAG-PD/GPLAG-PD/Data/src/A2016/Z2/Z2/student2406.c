#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
int main() {
	
	double niz[500], stepeni, minute, sekunde;
	double u;
	int  j, i, x;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &x); 
		for(i=0;i<x;i++)
		{
			scanf("%lf", &niz[i]);
		}
		for(i=0;i<x;i++)
{
		u=fabs((niz[i]*180)/PI);
		minute=(u-(int)u)*60;
		sekunde=round((minute-(int)minute)*60);
		if(sekunde==60)
		{sekunde=0; minute++;}
		if (sekunde>30){
			for(j=i;j<x-1;j++)
			{
				niz[j]=niz[j+1];
			}
		x--;
		i--;
		}
}
	
	printf("Uglovi su:\n");
	for(i=0;i<x;i++){
		u=(niz[i]*180)/PI;
		minute=fabs((u-(int)u)*60);
		sekunde=round((minute-(int)minute)*60);
		
		stepeni=(int)u;
		minute=(int)minute;
		sekunde=round(sekunde);
		
			if(stepeni>0){
				if(sekunde==60){
					sekunde=0; minute++;}
					if(minute==60){
						minute=0; stepeni++;
					}
					
				}
				
				if(stepeni<0){
					if(sekunde==60)
					{sekunde=0;minute++;}
					if(minute==60)
					{minute=0;stepeni--;}}
					printf("%.f stepeni %.f minuta %.f sekundi\n", stepeni, minute, sekunde);
					
				}
				
				
			
	
	
	
	return 0;
}
