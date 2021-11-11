#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	int n, i, j, stepeni, minute, sekunde, c=0;
	double niz[500], x;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%lf", &niz[i]);
	}
	printf("Uglovi su:\n");
	for(i=0; i<n; i++) {
		if(niz[i]<0){
			niz[i]*=-1;
			c=1;
		}
		x=niz[i]*(180/PI);
		stepeni=(int)x;
		x-=stepeni;
		x*=60;
		minute=(int)x;
		x-=minute;
		x*=60;
		sekunde=(int)(x+0.5);
		if(sekunde==60) {
			minute++;
			sekunde=0;
		}
		if(minute==60) {
			stepeni++;
			minute=0;
		}
		if(abs(sekunde)>30) {
			for(j=i; j<n-1; j++) {
				niz[j]=niz[j+1];
			}
			n--;
			i--;
			if(c==1) c--;
			continue;
		}
		if(c==1) {
			printf("-%d stepeni %d minuta %d sekundi\n", stepeni, minute, sekunde);
			c--;
		} else {
			printf("%d stepeni %d minuta %d sekundi\n", stepeni, minute, sekunde);
		}
	}
	return 0;
}
