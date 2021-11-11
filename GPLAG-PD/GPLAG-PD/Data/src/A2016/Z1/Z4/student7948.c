#include <stdio.h>

int main() {
	int n, i, j, k , m, a, b, c, d;
	printf ("Unesite broj n: ");
	scanf("%d", &n);
	while(n<=0 || n>50){
		printf("Pogresan unos \n");
		printf ("Unesite broj n: ");
		scanf("%d", &n);
	}
	m=(n*4)-3;
	c=m-(2*n);
	if (n==1){
		printf("***");
		return 0;
	}
	for (i=0;i<n;i++){
		for (k=0;k<i;k++){
			printf(" ");
		}
		printf("*");
		for (j=0;j<(c-(i*2));j++){
			printf(" ");
		}
		if(i!=(n-1)){
		printf("*");
		}
		for(a=0;a<(i*2)-1;a++){
			printf(" ");
		}
		if (i!=0){
		printf("*");
		}
		for(b=0;b<(c-(i*2));b++){
			printf(" ");
		}
		if(i!=(n-1)){
		printf("*");
		}
		for(d=0;d<i;d++){
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}
