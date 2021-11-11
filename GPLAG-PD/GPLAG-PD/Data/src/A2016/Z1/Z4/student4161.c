#include <stdio.h>

int main() {
	int n,i,j;
	for(;;){
		printf("Unesite broj n: ");
		scanf("%d",&n);
		if(n<=0 || n>50){
			printf("Pogresan unos\n");
			
		}
		else{
			break;
		}
	}
	if(n==1){
		for(i=0;i<3;i++)
			printf("*");
	}
	else{
	for(i=0;i<n;i++){
		for(j=0;j<=4*(n-1);j++){
			if(i==j || 2*(n-1)==j+i || 2*(n-1)==j-i  || 4*(n-1)==j+i)
				printf("*");
			else 
				printf(" ");
		}
		printf("\n");
	}
	}
	return 0;
}
