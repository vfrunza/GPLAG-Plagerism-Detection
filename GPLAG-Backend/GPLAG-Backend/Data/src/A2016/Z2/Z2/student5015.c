#include <stdio.h>
#define PI 3.1415926
#define br_el 500
int main(){
	int i, j, st, mn, sk, uk_sk, br;
	double niz[br_el];
	printf("Unesite broj uglova: ");
	scanf("%d", &br);
	printf("Uglovi su: ");
	for(i=0; i<br; i++){
		scanf("%lf", niz[i]);
		uk_sk=(niz[i]*180/PI)*3600;
		uk_sk=(int)(uk_sk+0.5);
	    int st=uk_sk/3600;
	    int mn=(uk_sk-st*3600)/60;
	    int sk=uk_sk-st*3600-mn*60;
	    printf("%d %d %d", st, mn, sk );
	}
	
	return 0;
}