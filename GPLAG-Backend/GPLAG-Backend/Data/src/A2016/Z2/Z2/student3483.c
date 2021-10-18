#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int n, i, j;
	double x[500], s, st, m, sk, sf;
	sf=0;
	do{
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	}
	while(n>500);
	for(i=0; i<n; i++){
		scanf("%lf", &x[i]);
	}
	for(i=0; i<n; i++){
		s=x[i]*(180/PI);
		st=floor(fabs(s));
		m=(fabs(s)-st)*60;
		sk=(m-floor(m))*60;
		if(round(sk)==60){
			sk=0;
			m++;
		}
		if(floor(m)==60){
			m=0;
			st++;
		}
		if(round(sk)>30){
			for(j=i; j<n-1; j++)
				x[j]=x[j+1];
			n--;
			i--;
		}
	}
	printf("Uglovi su:\n");
	for(i=0; i<n; i++){
		sf=0;
		if(x[i]<0){
			x[i]=fabs(x[i]);
			sf=1;
		}
		s=x[i]*(180/PI);
		st=floor(s);
		m=(s-st)*60;
		sk=(m-floor(m))*60;
		if(round(sk)==60){
			sk=0;
			m++;
		}
		if(floor(m)==60){
			m=0;
			st++;
		}
		if(sf==1)
			st=-st;
		printf("%.0f stepeni %.0f minuta %.0f sekundi\n", st, floor(m), round(sk));
	}
	return 0;
}
