#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() {
	float niz[100];
	int i,j,k,a,s,n,stepeni,stepen,minuta,sekunda,sekunde;
	printf("Unesite broj uglova: ");
	do{
	scanf("%d", &n);
	}while(n<1 || n>100);
	for(i=0; i<n; i++){
		scanf("%f", &niz[i]);
	}
	
	for(i=0; i<n; i++){
		sekunde=(niz[i]*180*3600)/PI;
		if(fabs((niz[i]*180*3600)/PI - sekunde)>0.5)
		if(sekunde<0)sekunde--;
		else sekunde++;
		stepen=sekunde/3600;
		minuta=(sekunde%3600)/60;
		sekunda=sekunde%60;
		if(sekunda>30 || sekunda<-30 ){
			for(k=i; k<n-1; k++){
				niz[k]=niz[k+1];
			}
			n--;
			i--;
		}
	}
	printf("Uglovi su:\n");
	for(i=0; i<n; i++){
		k=1;
		sekunde=(niz[i]*180*3600)/PI;
		if(fabs((niz[i]*180*3600)/PI - sekunde)>0.5)
		if(sekunde<0){sekunde--; k=-1;}
		else sekunde++;
		sekunde=fabs(sekunde);
		stepen=sekunde/3600;
		minuta=(sekunde%3600)/60;
		sekunda=sekunde%60;
		if(k==-1)printf("-");
	    printf("%d stepeni %d minuta %d sekundi\n",stepen,minuta,sekunda);
}
	return 0;
}
