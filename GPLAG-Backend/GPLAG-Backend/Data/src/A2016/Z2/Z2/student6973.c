#include <stdio.h>
#include <math.h>
#define PI 3.1415926


int main() {
	double niz[500],niz1[500];
	int n,i,j,stepeni[500],minute[500],sekunde[500];
	double pom1[500],pom2[500];
	do {
		printf("Unesite broj uglova: ");
		scanf("%d", &n);
		if(n < 0 || n > 500) printf("Pogresan unos\n");
	} while(n < 0 || n > 500);
	for(i = 0; i < n; i++) {
		scanf("%lf", &niz[i]);
	}
	/*for(i = 0; i < n; i++) {
		printf("%.2lf ", niz[i]);
	}*/
	//printf("\n");
	for(i = 0; i < n; i++) {
		niz1[i] = (niz[i] * 180)/PI;
	}
	/*for(i = 0; i < n; i++) {
		printf("%.2lf ", niz1[i]);
	}*/
	for(i = 0; i < n; i++){
		stepeni[i] = (int)niz1[i];
	}
	/*	printf("\n");
	for(i = 0; i < n; i++) {
		printf("%d ", stepeni[i]);
	}*/
	for(i = 0; i < n; i++){
		pom1[i] = niz1[i] - stepeni[i];
	}
	/*printf("AAAAAAAAA\n");
	for(i = 0; i < n; i++) {
		printf("%.2lf ",pom1[i]);
	}*/
	for(i = 0; i < n; i++) {
		pom1[i] = pom1[i]*60;
		//printf("%.2lf\n", pom1[i]);
		minute[i] = (int)pom1[i];
		//minute[i] = fabs(minute[i]);
	}
	/*	printf("\n");
	for(i = 0; i < n; i++) {
		printf("%d ", minute[i]);
	}*/
	for(i = 0; i < n; i++) {
		pom2[i] = pom1[i] - minute[i];
		pom2[i] = pom2[i] * 60;
		//printf("%.2lf ", pom2[i]);
		
		//printf("%.2lf ", pom2[i]);
		if(fabs(pom2[i]) > 59.51){
			sekunde[i] = 0;
			minute[i]++;
			if(fabs(minute[i]) > 59.51){
				minute[i] = 0;
				stepeni[i]++;
			}
		}
		//printf("ss%.2lf ", pom2[i]);
		//pom2[i] = pom2[i] / 10;
		else {
			pom2[i] = fabs(pom2[i]) + 0.5;
			sekunde[i] = (int)pom2[i];
		}
	}
	/*printf("\n");
	for(i = 0; i < n; i++) {
		printf("%d ", sekunde[i]);
	}*/
	for(i = 0; i < n; i++) {
		if(fabs(sekunde[i]) > 30) {
			for(j = i; j < n - 1; j++) {
				sekunde[j] = sekunde[j + 1];
				stepeni[j] = stepeni[j + 1];
				minute[j] = minute[j + 1];
			}
			n--;
			i--;
		}
	}
	for(i = 0; i < n; i++) {
		minute[i] = fabs(minute[i]);
		sekunde[i] = fabs(sekunde[i]);
	}
	printf("Uglovi su: \n");
	for(i = 0; i < n; i++) {
		printf("%d stepeni %d minuta %d sekundi\n", stepeni[i], minute[i], sekunde[i]);
	}
	return 0;
}
