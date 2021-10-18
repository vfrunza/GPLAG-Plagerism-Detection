#include <stdio.h>

int main() {
	int n,i,j,k=0;
	printf("Unesite broj n: ");
	do{
		scanf("%d", &n);
		if(n<1 || n>50){
			printf("Pogresan unos\n");
			printf("Unesite broj n: ");
		}
	} while(n<1 || n>50);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j==i) printf("*");
			else printf(" ");
		}
		for(j=0;j<n-2-i;j++){
			printf(" ");
		}
		if(i!=0 && i!=n-1) printf("*");
		for(j=0;j<i-1;j++){
			printf(" ");
		}
		for(j=0;j<n;j++){
			if(j-k==0) printf("*");
			else printf(" ");
		}
		k++;
		for(j=0;j<n-2-i;j++){
			printf(" ");
		}
		if(i!=n-1) printf("*");
		printf("\n");
	}
	
	/*printf("Zadaća 1, Zadatak 4");*/
	return 0;
}
