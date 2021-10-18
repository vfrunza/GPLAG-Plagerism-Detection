#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define PI 3.1415926
int main() {
	int i,j,n;
	float niz[500];
	double ste[500],min[500],sek[500],uk[500],step[500];
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	if(n<1 || n>500){ return 0;}
	for(i=0;i<n;i++){
		scanf("%f",&niz[i]);
	}
	printf("Uglovi su: \n");
	for(i=0;i<n;i++){
		uk[i]=(niz[i]*1296000)/(2.*PI);
		ste[i]=uk[i]/(60*60);
		step[i]=(int)(ste[i]);
		min[i]=(int)((ste[i]-step[i])*60);
		sek[i]=(ste[i]-step[i]-min[i]/60)*3600;
	if(ste[i]>0){
			if(sek[i]>=59.5) {min[i]=min[i]+1; sek[i]=0;}
			if(min[i]>59) {step[i]=step[i]+1; min[i]=0;}
		}else if(ste[i]<=0){
			if(sek[i]<-59.5){min[i]=min[i]-1; sek[i]=0;}
			if(min[i]<-59){step[i]=step[i]-1;min[i]=0;}
			
			if(min[i]<0 && sek[i]<0){
			min[i]=min[i]/(-1);
			sek[i]=sek[i]/(-1);
			}
			else if(step[i]<1&& step[i]>-1 && min[i]<0 && sek[i]<0){
			min[i]=min[i]/(-1);
			}
			else if(step[i]<0 && min[i]<1&& min[i]>-1&& sek[i]<0){
				sek[i]=sek[i]/(-1);
			}
		}
	}
	for(i=0;i<n;i++){
	}
	for(i=0;i<n;i++){
		if(sek[i]>30.5 || sek[i]<-30.5){
				for(j=i;j<n-1;j++){
					sek[j]=sek[j+1];
					min[j]=min[j+1];
					step[j]=step[j+1];
				}
			n--;
			i--;
		
		}
	}
	for(i=0;i<n;i++){
		printf("%.f stepeni %.f minuta %.f sekundi\n",step[i],min[i],sek[i]);
	}
	return 0;
}
