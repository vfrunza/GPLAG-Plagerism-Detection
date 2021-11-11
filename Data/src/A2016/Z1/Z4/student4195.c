#include <stdio.h>

int main() {
	int n,i,j,tacan_unos=0;
	do {
	printf("Unesite broj n: ");	
	scanf("%d",&n);
	if(n<=50 && n>0)
		tacan_unos=1;
	else if(!tacan_unos)
		printf("Pogresan unos\n");
	}while(!tacan_unos);
	
	for(i=0;i<n;i++) {
		for(j=0;j<i;j++) {
			printf(" ");
		}
		printf("*");
		for(j=0;j<2*(n-i)-3;j++){
			printf(" ");
		}
		if(i!=n-1 || n==1)
			printf("*");
		for(j=0;j<2*(i+1)-3;j++){
			printf(" ");
		}
		if(i!=0)
			printf("*");
		for(j=0;j<2*(n-i)-3;j++){
			printf(" ");
		}
		if(i!=n-1 || n==1)
			printf("*");
		printf("\n");
		
	}
	return 0;
}
