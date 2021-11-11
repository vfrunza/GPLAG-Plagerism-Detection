#include <stdio.h>
#include <math.h>

#define PI 3.1415926
int main() {
	int n, stepen, minut, sekund;
	int i, j;
	double niz[500];
	double totalsec=0;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%lf", &niz[i]);
	} printf("Uglovi su:\n");
	for(i=0; i<n; i++) {
		totalsec=fabs(niz[i])*(180/PI)*3600;
		totalsec=(int)(totalsec+0.5);
		stepen=totalsec/3600;
		minut=(totalsec-stepen*3600)/60;
		sekund=(totalsec-stepen*3600-minut*60);
		if(sekund>=60) {
			minut++;
			sekund-=60;
		}
		if(minut>=60) {
			stepen++;
			minut-=60;
		}
		if(sekund<=30) {
			if(niz[i]<0)
		printf("-%d stepeni %d minuta %d sekundi\n", stepen, minut, sekund);
		else { printf("%d stepeni %d minuta %d sekundi\n", stepen, minut, sekund);
			}
		} 
		else {
			for(j=i; j<n-1; j++) {
				niz[j]=niz[j+1];
			} n--;
			  i--;
		}
	}
	return 0;
}