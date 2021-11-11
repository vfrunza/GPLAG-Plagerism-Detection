#include <stdio.h>
#define PI 3.1415926

int main() {
	
	double A[500],k,dec,x;
	int i,n,step, min, sek;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	
	printf("Uglovi su:\n");
	for(i=0;i<n;i++){
		scanf("%lf",&A[i]);
	}
	
	for(i=0;i<n;i++){
		
		x=A[i];
		
		if(A[i]<0){
			A[i]=A[i]*(-1);
		}
		
		k=(180/PI)*A[i];
		step=k;
		k=k-step;
		k=k*60.0;
		min=k;
		k=k-min;
		k=k*60.0;
		sek=k;
		
		dec=k-sek;
		
		if(dec>0.5){
			sek++;
		}
		if(sek>59.5){
			sek=0;
			min++;
			if(min>59.5){
				min=0;
				step++;
			}
		}
		if(sek>30) continue;
		
		if(x<0){
			step=step*(-1);
		}
		
		printf("%d stepeni %d minuta %d sekundi\n",step,min,sek);
	}
	
	return 0;
}
