#include <stdio.h>

int main() {
	int n=1,i,j,d=2;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	while(n>50 || n<1){
		printf("Pogresan unos\nUnesite broj n: ");
		scanf("%d", &n);
	}
	if(n>1)
	d=(n-1)*4;
	for(i=0;i<n;i++){
	for(j=0;j<=d;j++){
		if((d-i==j)||(i==j)||(d/2-i==j)||(d/2+i==j))
	printf("*");
	else
	printf(" ");
	}
	printf("\n");
	}
	return 0;
}
