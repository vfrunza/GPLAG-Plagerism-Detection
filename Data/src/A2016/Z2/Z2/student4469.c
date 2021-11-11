#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define epsilon 0.1
int main() {
	int a=0,i,j;
	double c,nizr[500], nizs[500], nizm[500],nizsk[500];
	
do{
	printf("Unesite broj uglova: ");
	scanf ("%d",&a);
	} 
	while (a>500 || a<=0);

	for(i=0;i<a;i++){
		scanf("%lf",&nizr[i]);
		nizs[i]=nizr[i]*(180/PI);
		nizm[i]=fabs((nizs[i]-(int)(nizs[i]))*60);
		nizsk[i]=fabs((nizm[i]-(int)(nizm[i]))*60);
		if (nizsk[i]>=59.5){
			nizm[i]=nizm[i]+1;
			nizsk[i]=nizsk[i]-59.5;
		}
		if(nizm[i]>=60){ 
			
			if(nizs[i]<0){
			nizs[i]=nizs[i]-1;
		} else {
			nizs[i]=nizs[i]+1;
		}
			nizm[i]=nizm[i]-60;
		}
	}
	
	
		for(i=0;i<a;i++) {
		nizsk[i]=(int)(nizsk[i]+0.5);
		nizm[i]=(int)(nizm[i]);
		nizs[i]=(int)(nizs[i]);
	}
	
	
	
	
	for(i=0;i<a;i++){
		if((nizsk[i]-30)>epsilon){
		for(j=i;j<a-1;j++){
			nizsk[j]=nizsk[j+1];
			nizm[j]=nizm[j+1];
			nizs[j]=nizs[j+1];
		}
		a--;
		i--;
		
	}
	}
	

	printf("Uglovi su: \n");
	for(i=0;i<a;i++){
		printf("%d stepeni %d minuta %d sekundi\n", (int)nizs[i],(int)nizm[i],(int)nizsk[i]);
	}
	
	
	return 0;
}
	