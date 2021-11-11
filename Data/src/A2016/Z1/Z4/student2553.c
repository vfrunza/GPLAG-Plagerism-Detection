#include <stdio.h>

int main() {
	int n=0,i=0,j=0;
	do {
	printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n<=0 || n>50){printf("Pogresan unos\n");}
	}while(n<=0 || n>50);
	
	i=0;
	j=0;
	for (i=1;i<=n;i++){
		
		for(j=0; j<i-1;j++){ printf(" ");} //prvi prostor
	
		printf("*");
		
		for(j=1;j<=2*n-(i*2+1);j++){printf(" ");} //medjuprostor
		
		if(n!=1 && i!=n){printf("*");}else if (n==1){printf("*");}

		
		for(j=0; j<2*i-3;j++){ printf(" ");} //zvjezdani prostor
		
		if(i!=1 && i!=n) {printf("*");}
		
		for(j=1;j<=2*n-(i*2+1);j++){printf(" ");} //medjuprostor
		
		printf("*");
		
		printf("\n");
	}
	return 0;
}
