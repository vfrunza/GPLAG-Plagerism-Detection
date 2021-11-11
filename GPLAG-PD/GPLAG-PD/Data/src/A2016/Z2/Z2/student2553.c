#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
int main() {
	double niz[500];
	double temp;
	int stepen;
	int minuta;
	int sekunda;
	int i=0,n=0;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	if(n<1 || n>500){printf("Prevelik broj!");return 0;}
	printf("Uglovi su:");
	do{
		scanf("%lf",&niz[i]);
		i++;
	}while(i<n);
	
	for(i=0;i<n;i++){
		niz[i]=niz[i]*180/PI;
		stepen=(int)niz[i];
		if(niz[i]<0){temp=-1.0*niz[i];}else{temp=niz[i];}
		sekunda=(int)((temp-abs(stepen))*3600 + 0.5);
		minuta=(int)sekunda/60;
		sekunda=sekunda-minuta*60;
		if(minuta==60){minuta=0; if(stepen<0){stepen--;}else{stepen++;}}
			
		if(sekunda<=30){printf("\n%d stepeni %d minuta %d sekundi",stepen,minuta,sekunda);}
	}
	return 0;
}