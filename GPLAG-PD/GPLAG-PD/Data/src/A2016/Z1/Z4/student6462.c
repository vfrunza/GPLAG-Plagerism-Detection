#include <stdio.h>

int main() {
	int n, i=0, j=0, s;
	do{
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n>0 && n<=50){
			if(n==1) { printf("***"); break; }
			else {
		for(i=0; i<n; i++){
			s=3*n+n-3;
			for(j=0; j<s; j++){
				if(i==j || i+j==2*n-2 || j-i==2*n-2 || i+j==4*n-4) {
					printf("%c", '*');
				}
				else printf(" ");
			}
			printf("\n");
		}

		break; }
		}
		printf("Pogresan unos\n");
	}while(n<=0 || n>=50);
	
	return 0;
}
