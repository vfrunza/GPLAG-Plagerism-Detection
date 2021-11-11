#include <stdio.h>
#define PI 3.1415926
#include <math.h>
int main() {
	
	double niz[500];
	int i,j,n,minute=0,stepeni=0,sekunde=0;
	
	printf("Unesite broj uglova:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	scanf("%lf",&niz[i]);
		
	
	
	printf("Uglovi su:\n");
	
	
	
	
	
	for(i=0;i<n;i++){
	sekunde=3600*(niz[i]*180/PI);
	sekunde=(int)(sekunde+0.5);
	stepeni=sekunde/3600;
	minute=(sekunde-stepeni*3600)/60;
	minute=minute-stepeni*60;
	stepeni=fabs(stepeni);
	sekunde=(int)(sekunde-stepeni*3600-minute*60);
	if(minute>60)
	{
		minute=0;
		stepeni++;
	}
	


	
		if(sekunde>30){
			for(j=i;j<n-1;j++){
		
		niz[j]=niz[j+1];
				
			}
			n--;
			i--;
			
		}
		else
		printf(" %d stepeni %d minuta %d sekundi\n",stepeni,minute,sekunde);
	}
	
	
	return 0;
}
