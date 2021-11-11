#include <stdio.h>
#define PI 3.1415926
#define MAX 500
#include <stdlib.h>

int main(){
	int n,i,j,stepen,min,sec;
	double niz[MAX];
	
	printf("Unesite broj uglova: ");
	scanf("%d", &n);

	for(i=0; i<n; i++){
	scanf("%lf", &niz[i]);
	}
	
	printf("Uglovi su:\n");
	for(i=0; i<n; i++){
	
	if(niz[i]>=0){
		niz[i] = niz[i]*180/PI;
		stepen = niz[i];
		niz[i]-=stepen;
		niz[i]*=60;
		min= niz[i];
		niz[i]-=min;
		niz[i]*=60;
		sec=niz[i]+0.5;
	}
		if(niz[i]<0){
		niz[i] = niz[i]*180/PI;
		stepen = niz[i];
		niz[i]-=stepen;
		niz[i]*=60;
		min = niz[i];
		niz[i]-=min;
		niz[i]*=60;
		sec=niz[i]-0.5;
		min=abs(min);
		sec=abs(sec);
		}	
	
		if(stepen>0 && min==59 && sec>59){
			stepen = stepen + 1;
			min=0;
			sec=0;
		}
		else if(stepen<0 && min==59 && sec>59){
			stepen = stepen - 1;
			min=0;
			sec=0;
		}
		else if(min==60 && stepen>0){
			stepen = stepen +1;
			min=0;
		}
		else if(min==60 && stepen<0){
			stepen = stepen -1;
			min=0;
		}
		else if(min<59 && sec>59){
			min=min+1;
			sec=0;
		}
		if(sec<=30)
		printf("%d stepeni %d minuta %d sekundi\n", stepen, min, sec);
		continue;
				if(sec>30){
				for(j=i; j<n-1; j++){
				niz[i]=niz[i-1];
				n--;
				i--;
		
		
			}
		}
	}
	return 0;
}
