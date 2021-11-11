#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	double rad,niz[500],sek,min;
	int step,min1,i,n,sek1,j,brojac;
	printf("Unesite broj uglova: ");
	scanf("%d ",&n);
	
	for(i=0; i<n; i++)
		scanf("%lf",&niz[i]);

	for(i=0;i<n;i++){
		rad=(180/PI)*niz[i];
		if(rad<0){rad=-rad;}
		step=(int)rad;
		min=(rad-step)*60;
		min1=(int)min;
		sek=(min-min1)*60;
		sek1=(int)(sek+0.5);
		if(sek1 == 60){
			sek1=0;
			min1++; }
		if(min1 == 60){
			min1 = 0;
			step++;
			}
			
		if(sek1==60 && min1==59) step++;
		if(sek1 > 30){
			for(j=i;j<n-1;j++){
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		} 
		
	}
	printf("Uglovi su:\n");
	for(i=0;i<n;i++){
		brojac=0;
		rad=(180/PI)*niz[i];
		if(rad<0){rad=-rad;brojac++;}
		step=(int)rad;
	    min=(rad-step)*60;
	    min1=(int)min;
		sek=(min-min1)*60;
		sek1=(int)(sek+0.5);
		if(sek1 == 60){
			sek1=0;
			min1++; }
		
		if(min1 == 60){
			min1 = 0;
			step++;}
		if(sek1==60 && min1==59)
			step++;
			if(brojac==1)step=-step;
		printf("%d stepeni %d minuta %d sekundi\n",step,min1,sek1);
	}
	
	return 0;
}
