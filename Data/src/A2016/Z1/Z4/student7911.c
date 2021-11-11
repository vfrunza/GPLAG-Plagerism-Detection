#include <stdio.h>
int main()
{
	int n,i,j,k;
	greska:
	printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n<=0 || n>50) {
		printf("Pogresan unos\n");
		goto greska;
		
	}
	else if(n==1){
		printf("***");
	}
		else{
		
	for(i=0;i<n;i++){
		for(j=0;j<=4*(n-1);j++){
			if(i==j || i+j==2*(n-1) || i+j==4*(n-1) || j==2*(n-1)+i)
			printf("*");
			else
			printf(" ");
		}
		printf("\n");
		}
	
	
		}
	return 0;
}