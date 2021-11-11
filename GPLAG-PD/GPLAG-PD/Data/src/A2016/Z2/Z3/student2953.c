#include <stdio.h>

int main() {
	int x[10],y[10], n=-1, a, b, c;
	while(1){
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if((n>0)&&(n<=10)) break;
		printf("Pogresan unos\n");
	}
	for(a=0;a<n;a++) {
		printf("Unesite %d. tacku: ", a+1);
		scanf("%d%d", &x[a], &y[a]);
		if(x[a]>19 || y[a]>19 || x[a]<0 || y[a]<0) {
			printf("Pogresan unos\n");
			a--;
		}
	}
	for(a=0;a<20;a++){
	for(b=0;b<20;b++){
	for(c=0;c<n;c++)
	if(x[c]==b && y[c]==a) {
		printf("*");
		break;
	}
	if(c==n) {printf(" ");}
	}
	printf("\n");
	}
	return 0;
}
