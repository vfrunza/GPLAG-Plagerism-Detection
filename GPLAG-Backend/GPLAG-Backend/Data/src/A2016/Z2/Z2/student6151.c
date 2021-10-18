#include <stdio.h>
#define PI 3.1415926
#define epsilon 0.1
#include <math.h>

int main() {
	int i,x,j;
	printf("Unesite broj uglova: ");
	scanf("%d", &x);
	
	double niz[500], nizst[500], nizm[500], nizs[500];
	
	
	for(i=0;i<x;i++){
		scanf("%lf", &niz[i]);
		nizst[i]=(niz[i]*180)/PI;
		nizm[i]=fabs((nizst[i]-(int)(nizst[i]))*60);
		nizs[i]=fabs((nizm[i]-(int)(nizm[i]))*60);
		
		if(nizs[i]>=59.5){nizm[i]++;nizs[i]-=59.5;}
		
		if(nizm[i]>=60){ 
			if(nizst[i]<0) nizst[i]--;
			else nizst[i]++;
			
			nizm[i]-=60;
		}}
		
					for(i=0;i<x;i++){
				nizs[i]=(int)(nizs[i]+0.5);
				nizm[i]=(int)nizm[i];
				nizst[i]=(int)nizst[i];
			}
		
		for(i=0;i<x;i++){
			if(nizs[i]-30>epsilon){
				for(j=i; j<x-1;j++){
					nizs[j]=nizs[j+1];
                    nizm[j]=nizm[j+1];
                    nizst[j]=nizst[j+1];
				}
			x--;
			i--;  
			}}
			

		
			printf("Uglovi su: ");
		for(i=0;i<x;i++)		
    	printf("\n%d stepeni %d minuta %d sekundi", (int)nizst[i], (int)nizm[i], (int)nizs[i]);
	
	return 0;
}
