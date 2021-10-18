#include <stdio.h>

int main() {
	int i,j,n;
	 while (1<2){
		printf("Unesite broj n: ");
		scanf("%d",&n);
		if(n<=0 || n>50) printf("Pogresan unos\n");
		else break;
	 }
	for (i=1;i<=n;i++){
		for(j=1;j<=4*n-1;j++){
			if((n==1 && i==j) || (n==1 && i==j-1) || (n==1 && i==j-2)) printf("*");
		else if(i==j)printf("*");
		else if(i+j==2*n) printf("*");
		else if(i+j==4*n-2) printf("*");
		else if(j-i==2*n-2) printf("*");
		else printf(" ");
	} printf("\n");
}
	return 0;
}
