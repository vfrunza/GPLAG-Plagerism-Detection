#include <stdio.h>

int main() {
	int i,j,n;
	jump:
	printf("Unesite broj n: ");
	scanf ("%d", &n);
	if(n<=0 || n>50){
		printf("Pogresan unos\n");
		goto jump;
	}
	
	else{
		printf ("*");
		for(i=0; i<2*n-3;i++){
			printf (" ");
		}
		printf ("*");
		for(i=0;i<2*n-3;i++){
				printf(" ");
			
			}
			printf("*\n");
			for(i=0;i<n-2;i++){
				for(j=0;j<=i;j++){
					printf(" ");
				}
				printf("*");
				for(j=0;j<2*n-5-2*i;j++){
					printf(" ");
				}
				printf("*");
				for(j=0;j<2*(i+1)-1;j++){
					printf(" ");
				}
				printf("*");
				for(j=0;j<2*n-5-2*i;j++)
				printf(" ");
			}
	printf("*\n");
		}
		
		if(n>1){
			for(i=0;i<n-1;i++){
				printf(" ");
			}
			printf("*");
			for(i=0;i<2*n-3;i++){
				printf(" ");
			}
			printf("*\n");
		}
	
	return 0;
}
