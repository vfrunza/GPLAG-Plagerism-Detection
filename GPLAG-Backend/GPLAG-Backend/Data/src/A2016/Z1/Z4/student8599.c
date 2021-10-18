#include <stdio.h>

int main() {
	int  n;
	int i, j;
	do {
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<=0 || n>50)
	printf("Pogresan unos\n");}
	while(n<=0 || n>50);
	for(i=0; i<n; i++){
		if(n==1){
			printf("***");}
		else for(j=0; j<(4*n-i-3); j++){
			if((j==i) || (j==2*n-i-2) || (j==4*n-4-i) || (j==(2*n-2+i))){
			printf("*");
			}
			else{
				printf(" ");}
		}
			printf("\n");
	}
	return 0;
}
