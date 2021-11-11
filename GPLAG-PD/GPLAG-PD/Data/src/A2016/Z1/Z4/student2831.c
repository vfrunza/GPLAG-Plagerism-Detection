#include <stdio.h>

int main() {
	int n=0;
	do{
		printf("Unesite broj n: ");
		scanf("%d",&n);
		if(n>0 && n<=50) break;
		printf("Pogresan unos\n");
	} while(1);
	
	int m=(n-1)*4;
	int i=0, j=0;
	int r=(m+1-3)/2;
	int r2=1;
	int r3=1;
	
	for(i=0;i<n;i++){
		if(i!=0 && i!=(n-1)){
			for(j=0; j<r2; j++) printf(" ");
			printf("*");
			
			for(j=0; j<r; j++) printf(" ");
			printf("*");
			
			for(j=0; j<r3; j++) printf(" ");
			printf("*");
			
			for(j=0; j<r; j++) printf(" ");
			printf("*");
			
			for(j=0; j<r2; j++) printf(" ");
			r-=2;
			r2++;
			r3+=2;
		}
		
		else if(i==0){
			printf("*");
			for(j=0;j<r;j++) printf(" ");
			printf("*");
			for(j=0;j<r;j++) printf(" ");
			printf("*");
			r-=2;
		}
			else if(i==n-1){
				for(j=0;j<r2;j++) printf(" ");
				printf("*");
				for(j=0; j<r3;j++) printf(" ");
				printf("*");
				for(j=0;j<r;j++) printf(" ");
			}
	printf("\n");
	}
	return 0;
}
