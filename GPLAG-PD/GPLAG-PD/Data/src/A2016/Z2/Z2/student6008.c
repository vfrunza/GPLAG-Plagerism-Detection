#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define Z 0.5


int main()
{

	int n, i, j;
	double niz[500], k, stepen, minuta, sekunda, pom;

	printf("Unesite broj uglova: ");
	scanf("%d", &n);

	for(i=0; i<n; i++) {
		scanf("%lf", &niz[i]);
	}


	printf("Uglovi su: \n");
	for(i=0; i<n; i++) {
		k=niz[i]*180/PI*3600;
		if(k>0)
			k=(int)(k+Z);
		else k=(int)(k-Z);
		int stepen=(int)k/3600;
		
		k = fabs(k);
		pom = fabs(stepen);

		int minuta=(k-pom*3600)/60;
		
		int sekunda=k-pom*3600-minuta*60;
		
		if(sekunda>=60){
			while(sekunda>=60){
				minuta++;
				sekunda=sekunda-60;
				}
			}
		if(sekunda<=-60){
			while(sekunda<=-60){
				minuta--;
				sekunda=sekunda+60;
			}
		}
		if(minuta>=60){
			while(minuta>=60){
				stepen++;
				minuta=minuta-60;
			}
		}
		if(minuta<=-60){
			while(minuta<=-60){
				stepen--;
				minuta=minuta+60;
			}
		}
			if(sekunda>30) {
				for(j=i; j<n-1; j++){
					niz[j]=niz[j+1];
				}
				n--;
				i--;
				continue;
			}
			if(sekunda<-30){
				for(j=i; j<n-1; j++){
					niz[j]=niz[j+1];
				}
				n--;
				i--;
				continue;
			}
			


			printf("%d stepeni %d minuta %d sekundi\n", stepen, minuta, sekunda);
		}
		//printf("%d", (int) c);

		return 0;
	}
