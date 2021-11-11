#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() {
	int n, i;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	double niz[500];
	for(i=0; i<n; i++){
		scanf("%lf", &niz[i]);
	}
	printf("Uglovi su: \n");
	for(i=0; i<n; i++){
		double S=niz[i]*180/PI;
		double M=(fabs(S)-(int)fabs(S))*60;
		double sek=(M-(int)M)*60;
		int x=(int) S;
		int m=(int) M;
		int poz=(int)(sek+0.5);
		if(poz==60){
			if(m>0) m++;
			if(m<0) m--;
			poz=0;
		}
		
		if(m==60){
			if(x>0) x++;
			if(x<0) x--;
			m=0;
		}
		 if(poz<=30)printf("%d stepeni %d minuta %d sekundi\n", x, m, poz);
	}
	
	return 0;
}
