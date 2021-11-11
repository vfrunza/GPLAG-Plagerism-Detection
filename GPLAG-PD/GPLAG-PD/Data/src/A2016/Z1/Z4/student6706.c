#include <stdio.h>

int main() {
	int i,j,n=0,brojac=0;
	while(n<=0 || n>50){
    printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n>0 && n<=50) break;
	else printf("Pogresan unos\n");
	brojac++;
	}
	if(n==1)printf("**");
	for(i=0;i<n;i++){
		for(j=0;j<=(n-1)*4;j++){
			if(i==j)printf("*");
			else if(i==((n-1)*4)/2-j)printf("*");
			else if(i==(n-1)*4-j)printf("*");
			else if(i==j-2*n+2)printf("*");
			else printf(" ");
		    
		}
		printf("\n");
	}
	return 0;
}
