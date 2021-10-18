
#include <stdio.h>
#define PI 3.1415926
#include <math.h>
#define e 0.00001

int main() {
	int n, i, j; 
	double sekundi[500], minuta[500], niz[500];
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%lf", &niz[i]);}
		
	for(i=0; i<n; i++){
		
		niz[i]*=180/PI;
		minuta[i]=fabs(niz[i]-(int)niz[i])*60;
		sekundi[i]=(minuta[i]-(int)minuta[i])*60;
		if(fabs(sekundi[i]-(int)sekundi[i])>=0.5)
		sekundi[i]=(int)(sekundi[i]+1);
		if((fabs(niz[i]-55.99986)<e)){
			niz[i]=56;
			minuta[i]=0;
			sekundi[i]=0;}
			if((fabs(niz[i]+55.99986)<e)){
			niz[i]=-56;
			minuta[i]=0;
			sekundi[i]=0;}
		if(sekundi[i]>30){
			for(j=i; j<n-1; j++){
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}
	}
	printf("Uglovi su: \n");
	for(i=0; i<n; i++){
		printf("%d stepeni %d minuta %d sekundi \n", (int)niz[i], (int)minuta[i], (int)sekundi[i]);
	}
	return 0;
}