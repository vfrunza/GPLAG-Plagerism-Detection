#include <stdio.h>

int main() {
	double i, j;
	int n;
	A: printf("\nUnesite broj n: ");
	scanf("%d", &n);
while(n<1 || n > 50){
	printf("Pogresan unos");
	goto A;
}
 if(n>1 && n<=50) {
	for (i=0;i<n;i++){
		for(j=0;j<4*n;j++){
				if(j==i || j==2*n-i-2 || j==2*n+i-2 || j==4*n-i-4){
				printf("*");
				}
			else {
				printf(" ");
			}


		}
		printf("\n");
	}
}
			else if(n==1){
				printf("***");
			}
	return 0;
}
