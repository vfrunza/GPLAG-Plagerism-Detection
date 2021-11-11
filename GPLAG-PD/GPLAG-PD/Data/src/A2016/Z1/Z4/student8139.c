#include <stdio.h>

int main() {
	
	int n, i, j;
	for(;;){
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n<=0 || n>50){ printf("Pogresan unos\n"); continue;}
		else if(n==1) printf("***");
		else{
			for(i=0; i<n; i++){
				for(j=0; j<4*n-3; j++){
					if(j==i || j==2*n-i-2 || j==2*n-2+i || j==4*n-i-4) printf("*");
					else printf(" ");
				}
				printf("\n");
			}
		}
		break;
	}
	return 0;
}
