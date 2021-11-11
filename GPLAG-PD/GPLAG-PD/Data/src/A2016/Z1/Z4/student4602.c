#include <stdio.h>

int main() {
	//printf("Zadaća 1, Zadatak 4");
	int n,i,j,x,y;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	while(n<=0 || n>50){
		printf("Pogresan unos\nUnesite broj n: ");
		scanf("%d", &n);
	}
	x=n-2;
	y=4*x+4;
	for(i=0; i<n; i++){
		for(j=0; j<=y; j++){
			if(i==j || (i+j)==2*n-2 || j==i+2*n-2 || i+j==y){
				printf("*");
			}
		
			else{
				printf(" ");
			}
		}
			printf("\n");
		}
	
	
	return 0;
}
