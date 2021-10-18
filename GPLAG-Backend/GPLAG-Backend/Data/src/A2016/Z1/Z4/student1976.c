#include <stdio.h>

int main() {
	int i, j, n;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n<=0 || n>50){ do {
		printf("Pogresan unos");
		printf("\nUnesite broj n: ");
		scanf("%d",&n);
	}
	while(n<0 || n>50);}
	if(n==1){
		printf("**");
	}
	for (i=1;i<=n;i++){
		for(j=1;j<=5+4*(n-2);j++){
			if(i==j || i==j-2*n+2 || i==2*n-j || j==4*(n-2)-i+6){
				printf("*");} else{ printf(" ");}
			}
			
		
		printf("\n");
	}
	return 0;
}
