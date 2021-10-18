#include <stdio.h>

int main() {
	int i,j;
int n;
ok:
	printf("Unesite broj n: ");
scanf("%d",&n);
if (n<=0||n>50) {
	printf("Pogresan unos\n");
goto ok;	
}


if(n==1){

printf("***");
return 0;}
	for(i=0;i<n;i++){
		for(j=0;j<n*4-3;j++){
			if(i==j||i==2*n-2-j||j==2*n+i-2||j==4*n-i-4){
			printf("*");
			}
			else printf(" ");
		}
		printf("\n");
		
	}
	return 0;
}
