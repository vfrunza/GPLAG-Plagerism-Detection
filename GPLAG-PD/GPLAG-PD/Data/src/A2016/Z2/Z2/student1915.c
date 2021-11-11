#include <stdio.h>
#include<math.h>
#define PI 3.1415926

int main() {
	double niz[500];
	int j=0,i=0;
	int n=0;
	int stepeni=0,minute=0;
     double sekunde=0;
     int tip;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		
		scanf("%lf",&niz[i]);
	}
	printf("Uglovi su:");
	
	for(i=0;i<n;i++){
		sekunde=3600*niz[i]*(180/PI);
		if(sekunde<0) tip=0;
		else tip=1;
		sekunde=fabs(sekunde);
		minute=(int)(sekunde/60);
		stepeni=(int)(minute/60);
		
		sekunde=sekunde-minute*60+0.5;
		minute=minute-stepeni*60;
		
	


	if((int)sekunde==60){
		minute++;
         sekunde=0;
		}
	if((int)minute==60){
		stepeni++;
		minute=0;
	}
	if((int)sekunde>30){
		for(j=i;j<n;j++){
			niz[j]=niz[j+1];
			
		}
		n--;
		i--;
	} 
	else{
	
	
		if(tip==1)
           printf("\n%d stepeni %d minuta %d sekundi",stepeni,minute,(int)sekunde);
           else 
           printf("\n-%d stepeni %d minuta %d sekundi",stepeni,minute,(int)sekunde);
	}
	}
	
	
	return 0;
}
