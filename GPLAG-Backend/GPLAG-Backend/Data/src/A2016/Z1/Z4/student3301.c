#include <stdio.h>

int main() {
	int n,i,j,m;
	do{
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<=0 || n>50 ){
		printf("Pogresan unos\n");
	}
	}while(n<=0 || n>50);
	if(n==1) m=n*3;
	else if(n>1){
		m=n*3+n-3;
		
	}
	for(i=0;i<n;i++){
		for(j=0;j<=m;j++){
			if(i==j || i==j-(m/2) || j==m/2-i || j==m-i-1)
			printf("*");
			else 
			printf(" ");
		}
		printf(" \n");
	}
	
	return 0;
}

