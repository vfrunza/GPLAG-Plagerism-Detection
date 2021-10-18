#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.1415926

int main() {
	int x, i, j;
	double a[1000], step=0, min=0, sek=0, sekz=0;
	do{
	printf("Unesite broj uglova: ");
	scanf("%d", &x);
	}while(x<=0 || x>500);
	for(i=0; i<x; i++)
		scanf("%lf", &a[i]);

	
	for(i=0; i<x; i++){
		step=a[i];
		step*=180/pi;
		min=(step-(int)step)*60;
		sek=(min-(int)min)*60;
		sek=round(sek);
		min=(int)min;
		if(abs(sek)==60)
			{
				sek=0;
				if(a[i]>=0)
				min++;
				else min--;
				if(abs(min)==60){
					min=0;
					if(a[i]>=0)
					step++;
					else step--;
				}
			}
		if(abs(round(sek)) > 30){
			for(j=i; j<x-1; j++){
				a[j]=a[j+1];
			}
			x--;
			i--;
		}
		
		
	}
	printf("Uglovi su:\n");
	for(i=0; i<x; i++){
		step=a[i];
		step*=180/pi;
		min=(step-(int)step)*60;
		sek=(min-(int)min)*60;
		sek=roundf(sek);
		step=(int)step;
		//min=roundf(min);
		min=(int)min;
		if(abs(sek)==60)
			{
				sek=0;
				if(a[i]>=0)
				min++; //
				else min--;
				if(abs(min)==60){
					min=0;
						if(a[i]>=0)
					step++;
					else step--;
				}
			}
	
		
		printf("%d stepeni %d minuta %d sekundi\n", (int)step, abs((int)min), abs((int)round(sek)));
		
	}

	
	
	
	return 0;
}
