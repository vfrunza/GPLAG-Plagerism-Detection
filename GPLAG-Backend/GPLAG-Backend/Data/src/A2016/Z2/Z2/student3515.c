#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define epsilon 0.001

int main() {
	double rad[500], deg[500], min1[500], sek1[500];
	double min_2, sek, dg1, dg;
	int i=0, v, j=0, pred[500];
	
	printf("Unesite broj uglova: ");
	scanf("%i", &v);
	
	
		for(i=0; i<v; i++) {
			scanf("%lf", &rad[i]);
			
			if(rad[i]<0)
			{
				
				pred[i]=-100;
					rad[i]=-rad[i];
			}
			else if(rad[i]>=0) 
			{
				pred[i]=100;
			}
			
			dg=rad[i]*(180/PI);
			dg1=abs(dg);
			min_2=dg-dg1;
			
			min_2=min_2*60;
			
			sek=(abs(min_2));
			
			sek=min_2-sek;
			
			sek=sek*60;
		
			sek=(int)(sek + 0.50);
			
			
			min_2=(int)min_2;
			dg=(int)dg;
			
			if(sek>=60){
				sek=0;
				min_2++;
			}
			
			if(min_2>=60) {
				min_2=0;
				dg++;
			}
			
			deg[i]=dg;
			min1[i]=min_2;
			sek1[i]=sek;
			
		}
	
			printf("Uglovi su:");
			
			for(i=0;i<v;i++)
			{
				if(sek1[i]>30)
				{
					
					for(j=i;j<v-1;j++)
					{
						
						sek1[j]=sek1[j+1]; }
						
						for(j=i;j<v-1;j++)
						{
							
							deg[j]=deg[j+1]; }
							
							for(j=i;j<v-1;j++)
							{
								min1[j]=min1[j+1]; }
								
									for(j=i;j<v-1;j++)
							{
								pred[j]=pred[j+1];	}
								
								v--;
								i--; 
					
				}
			
				else if(sek1[i]<=30)
				{
					if(pred[i]<0)
					{
						if((deg[i]-epsilon)==0)
						{
							printf("\n%.0f stepeni -%.0f minuta %.0f sekundi", deg[i], min1[i], sek1[i]);
						}
						
						else if((deg[i]-epsilon)!=0)
						{
							
							printf("\n-%.0f stepeni %.0f minuta %.0f sekundi", deg[i],min1[i],sek1[i]);
						}
					}
					
						else if(pred[i]==100)
						{
							printf("\n%.0f stepeni %.0f minuta %.0f sekundi", deg[i],min1[i],sek1[i]);
						}
				
					
				}
				
				
			}
	
	return 0;
}
