#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.1415926

int main() {
	double niz[500];
	int i,n,stepen[500],min[500],sek[500],j,neg;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);

	for(i=0;i<n;i++){
	    scanf("%lf",&niz[i]);
	}
	printf("Uglovi su:\n");
	for(i=0;i<n;i++){
		if (niz[i]<0) neg=-1;
		else neg=1;
	    stepen[i]=(niz[i]*180/PI);
	    min[i]=((niz[i]*180/PI-stepen[i])*60);
	    if(min[i]==60 || min[i]==-60){
	    	min[i]=0;
	    	if(stepen[i]>0) stepen[i]++;
	    	else stepen[i]--;
	    }
	    sek[i]=((niz[i]*180/PI-stepen[i])*60 - min[i])*60+neg*0.5;
	    if(sek[i]==60 || sek[i]==-60){
	    	sek[i]=0; 
	    	if(min[i]>0) min[i]++;
	    	else min[i]--;
	    }
	    if(min[i]==60 || min[i]==-60){
	    	min[i]=0;
	    	if(stepen[i]>0) stepen[i]++;
	    	else stepen[i]--;
	    }
	    if(sek[i]>30 || sek[i]<-30){
	    	for(j=i;j<n-1;j++){
	    		niz[j]=niz[j+1];
	    	  }
	       n--;
	       i--;
	    }
	}
	    
	for(i=0;i<n;i++){
		printf("%d stepeni %d minuta %d sekundi\n",stepen[i],min[i],sek[i]);
	}
	return 0;
}
