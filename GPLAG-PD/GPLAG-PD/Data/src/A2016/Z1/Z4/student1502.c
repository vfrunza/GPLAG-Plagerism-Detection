#include <stdio.h>

int main() {
	
	int n;
	while(1){
	printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n<1 || n>50){
		printf("Pogresan unos");
	}else{
		break;
	}
	printf("\n");
	}
	if(n==1){
		printf("***");
		return 0;
	}
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<((n*4)-3);j++){
			if(j==i || j==(2*n-2-i) || j==(2*n-2+i) || j==(4*n-4-i)){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
