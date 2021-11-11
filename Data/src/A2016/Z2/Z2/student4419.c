#include <stdio.h>
#include <math.h>

#define PI 3.1415926

int main() {
	
	int n,i,j;
	double niz[500];
	int stepeni,minute2,sekunde2;
	double x, minute1,sekunde1;

	do {
		printf("Unesite broj uglova: ");
		scanf("%d", &n);
	} while (n<1 || n>500);
	
	for(i=0; i<n; i++)
	{
		scanf("%lf", &niz[i]);
	}
	
	printf("Uglovi su: \n");
	
	for(i=0; i<n; i++)
	{
		x=fabs(niz[i]);
		x=x*180/PI;
		stepeni=(int)x;
	
		
		minute1=(x-stepeni)*60;
	    minute2=(int)minute1;
	  
	    
		sekunde1=(minute1-minute2)*60;
		sekunde2=(int)(sekunde1 + 0.5); 
		
		if(sekunde2==60) {
			minute2++;
		} 
		sekunde2=(int)((x-stepeni)*3600+0.5)%60;
		
		if(minute2==60){
			stepeni++;
			minute2=minute2%60;
		}
	
		
		
			if(sekunde2>30)
			{
				for(j=i; j<n-1 ; j++)
				{
					niz[j]=niz[j+1];
				}
				n--;
				i--;
				
			}
			
			else{
				if(niz[i]<0) printf("%d stepeni %d minuta %d sekundi\n", (-1)*stepeni,minute2,sekunde2);
				else 	printf("%d stepeni %d minuta %d sekundi\n", stepeni,minute2,sekunde2);
				
			}
		
	
		
	}
	
	
	return 0;
}
