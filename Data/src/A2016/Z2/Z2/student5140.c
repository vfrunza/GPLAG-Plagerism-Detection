#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	int n,i,j,stepen[500],minuta[500],sekunda[500];
	float uk,um,us,niz[500];
	do{
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	} while(n<1 || n>500);
	
	for(i=0; i<n; i++){
		scanf("%f/n", &niz[i]);
		niz[i]=niz[i]*180/PI;
	}
	
	printf("Uglovi su:\n");
	for(j=0; j<n; j++){
		uk=niz[j];
		stepen[j]=(int)uk;
		um=(uk-stepen[j])*60;
		minuta[j]=(int)um;
		us=(um-minuta[j])*60;
		if(niz[j]>0)
		sekunda[j]=(int)(us+0.5);
		else if(niz[j]<0)
		sekunda[j]=(int)(us-0.5);
		}
	
	sekunda[i]=abs(sekunda[i]);
	minuta[i]=abs(minuta[i]);
	
	for(i=0; i<n; i++){
	    if(abs(sekunda[i])>=60){
	        if(stepen[i]>0){
	            sekunda[i]-=60;
	            minuta[i]++;
	        }
	        else if(stepen[i]<0){
	            sekunda[i]+=60;
	            minuta[i]--;
	        }
	    }
	    if(abs(minuta[i])>=60){
	        if(stepen[i]>0){
	            minuta[i]-=60;
	            stepen[i]++;
	        }
	        else if(stepen[i]<0){
	            minuta[i]+=60;
	            stepen[i]--;
	        }
	    }
	}
	
		for(i=0; i<n; i++){
		if(sekunda[i]>30 || sekunda[i]<-30){
			for(j=i; j<n-1; j++){
				sekunda[j]=sekunda[j+1];
				minuta[j]=minuta[j+1];
				stepen[j]=stepen[j+1];
			}
			n--;
			i--;
		}
		}
	
	
	for(i=0; i<n; i++){
		printf("%d stepeni %d minuta %d sekundi\n", stepen[i], abs(minuta[i]), abs(sekunda[i]));
	}

	
	return 0;
}