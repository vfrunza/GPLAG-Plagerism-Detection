#include <stdio.h>

int main() {
	int n=0, i, j;
	while(n<=0 || n>50){
	printf("\nUnesite broj n: " );
	scanf("%d", &n);
	if(n<=0 || n>50){
		printf("Pogresan unos ");}
	} 
	if(n==1){
		printf("**");
	}
	for(i=0;i<n;i++){
	{
		for(j=0;j<4*n-1;j++){
			if((j==i) || (j==2*n-i-2) || (j==2*n+i-2) || (j==4*n-i-4)){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	}
	return 0;
}




