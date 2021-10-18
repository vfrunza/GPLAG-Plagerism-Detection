#include <stdio.h>

int main() {
	
	int i,j,k,l,m,n;
	do{ printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<=0 || n>50) printf("Pogresan unos\n");	}
	while(n<=0 || n>50);
	if(n==1){printf("***");}
	else {
	printf("* ");
	for(i=0;i<2*n-4;i++){printf(" ");}
	printf("* ");
	for(i=0;i<2*n-4;i++){printf(" ");}
	printf("*");
	printf("\n");

	for(i=1;i<n-1;i++){
		for(j=n-i;j<n;j++) {printf(" ");}
		printf("*");
		for(k=2*n-2*i-2;k>1;k--) {printf(" ");}
		printf("*");
		for(l=n-2*i+1;l<n;l++) {printf(" ");}
		printf("*");
		for(m=2*n-2*i-2;m>1;m--) {printf(" ");}
		printf("*");
		printf("\n");
	}
	
	for(i=0;i<n-1;i++) {printf(" ");}
	printf("*");
	for(i=0;i<2*n-3;i++) {printf(" ");}
	printf("*");
	
	}
	
	
	return 0;
}
