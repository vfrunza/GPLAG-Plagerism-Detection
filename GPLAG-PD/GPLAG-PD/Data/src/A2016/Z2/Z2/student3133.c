#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	int n, i, j, step[500], min[500], sek[500];
	double niz[500];
	printf("Unesite broj uglova: ");
	scanf ("%d", &n);
	if (n>500) return 1;
	for(i=0; i<n; i++){
		scanf("%lf", &niz[i]);
		step[i]=niz[i]*180/PI;
		niz[i]=niz[i]*180/PI;
	    niz[i]=niz[i]-(int)niz[i];
	    min[i]=niz[i]*60;
	    niz[i]=niz[i]*60 - min[i];
	    if(niz[i]>0)
	    sek[i]=(int)(niz[i]*60 + 0.5);
	    else sek[i]=(int)(niz[i]*60 - 0.5);
	    if(abs(sek[i])>=60)
	    { 
	    	if(sek[i]>0){sek[i]-=60; min[i]++;
	    		
	    	}
	    	else { 
	    		sek[i]+=60; min[i]--;
	    	}
	    	
	    }
	    if(abs(min[i])>=60){
	    	if(min[i]>0){
	    		(min[i])-=60;
	    	   step[i]++;
	    	  }
	    	else {
	    		min[i]+=60; step[i]--;
	    	}
	    }
	}
	for(i=0; i<n; i++){
		if(abs(sek[i])>30){
			for(j=i; j<n-1; j++){
				niz[j]=niz[j + 1];
				step[j]=step[j + 1];
				min[j]=min[j + 1];
				sek[j]=sek[j + 1];
			}
			n--;
			i--;
		}
	}
	printf("Uglovi su:\n");
	for(i=0; i<n; i++){
		if(step[i]<0||min[i]<0||sek[i]<0) printf("-%d stepeni %d minuta %d sekundi\n", abs(step[i]), -min[i], -sek[i]);
		else
		printf("%d stepeni %d minuta %d sekundi\n", step[i], min[i], sek[i]);
	}
	return 0;
}
