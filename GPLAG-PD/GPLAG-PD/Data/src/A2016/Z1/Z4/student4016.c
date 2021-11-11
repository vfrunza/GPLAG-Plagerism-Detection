#include <stdio.h>

int main() {
	int m,n,a,b,i,j;
	while(1){
		printf("Unesite broj n: ");
		scanf("%d",&n);
		if(n<=0 || n>50){printf("Pogresan unos\n");continue;}
		else break;
	}
	if(n==1){printf("***");return 0;}
	m=n+3*(n-1);
	for(i=0;i<n;i++){
	a=2*n-i-2;
	b=2*n+i-2;
	for(j=0;j<m;j++){
		if(i==j || j==m-i-1 || j==a || j==b) printf("*");
		else printf(" ");
	}printf("\n");}
	return 0;
}
