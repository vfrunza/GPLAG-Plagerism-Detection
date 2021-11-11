#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define vel 500
#define PI 3.1415926

int main(){
	int n,i,j,step[vel],min[vel],sek[vel],a;
	float niz[vel],b;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%f",&niz[i]);
	}
	
	for(i=0;i<n;i++){
		niz[i]=niz[i]*(180.0/PI);
	}
	
	for(i=0;i<n;i++){
		step[i]=(int)(niz[i]);
		a=abs(step[i]);
		b=fabs(niz[i]);
		min[i]=(int)((b-a)*60);
		sek[i]=(int)(((b-a)*60-min[i])*60 + 0.5);
		if(sek[i]==60){
			sek[i]=0;
			min[i]=min[i] + 1;
		}
		if(min[i]==60){
			min[i]=0;
			if(step[i]>=0)
				step[i]=step[i] + 1;
			else 
				step[i]=step[i] - 1;
		}
	}
	
	for(i=0;i<n;i++){
		if(sek[i]>30 && sek[i]!=30){
			for(j=i;j<n-1;j++){
				step[j]=step[j+1];
				min[j]=min[j+1];
				sek[j]=sek[j+1];
			}
			i--;
			n--;
		}
	}
	
	printf("Uglovi su: ");
	for(i=0;i<n;i++){
		printf("\n%d stepeni %d minuta %d sekundi\n",step[i],min[i],sek[i]);
	}
	return 0;
}