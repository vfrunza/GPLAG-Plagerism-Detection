#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926



int main() {
	int broj=0,step=0,min=0,sec=0,j,i;
	double niz[500],a,temp=0,temp2=0,sek=0,sek2=0;
	double C;
	C=(double)180/PI;
	do
	{ 
	printf("Unesite broj uglova: ");
	scanf("%d", &broj);
	
	} while(broj<1 || broj>500);
	
	for(i=0; i<broj; i++)
	{
		scanf("%lf", &niz[i]);
		niz[i]=niz[i]*C;
		}
		
		
		
		printf("Uglovi su: \n");
		
		
		for(i=0; i<broj; i++)
		{ if(niz[i]>=0)
		
		{
			temp=niz[i];
		 step=(int)temp;
		 temp2=(temp-step)*60;
		 min=(int)temp2;
		 sek=(temp2-min)*60;
		 sek2=(sek-(int)sek)*10;
		 if (sek2>=5) 
		 {
		 	sec=(int)sek+1;
		 	
		 } else{ sec=(int)sek;}
		 
		 if (sec==60)
		 {
		 	sec=0;
		 	min++;
		 	if (min==60) 
		 	{
		 		min=0;
		 		step++;
		 		
		 		
		 	}
		 	
		 }
		 
		 if (sec>30) {
		 	 
		 	 for(j=i; j<broj-1; j++)
		 	 
		 	 { 
		 	 	niz[j]=niz[j+1]; 
		 	 	
		 	 } 
		 	 
		 	 
		 	 broj--;
		 	 i--;
		 	 continue;
		 	 
		 }
		 printf("%d stepeni %d minuta %d sekundi \n", step, min,sec);
		 
		}
		
		if (niz[i]<0)
		
		
		
		{
			
			
			temp=niz[i];
			step=(int)temp;
			temp2=(temp-step)*(-1)*60;
			min=(int)temp2;
			sek=(temp2-min)*60;
			sek2=(sek-(int)sek)*10;
		
		
			if (sek2>=5) 
			
			
			{sec=(int)sek+1;}
			else
			
			{sec=(int)sek;}
			
			if (sec==60) 
			
			{ sec=0; min++; 
			
				if (min==60)
				
				{ min=0; step--;
				}
				
				}
			
			
			
			if (sec>30)
			{   for(j=i; j<broj-1; j++)
			
			
			{ 
				
				niz[j]=niz[j+1];
				
			}		
			
				
				
				broj--;
				i--;
				
				continue;
			}
		
			
			printf("%d stepeni %d minuta %d sekundi\n", step, min, sec);
		
		

		}
		}
	
	return 0;
}
