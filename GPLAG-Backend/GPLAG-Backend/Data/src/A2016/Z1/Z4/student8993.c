#include <stdio.h>

int main() {
int i=0,j=0,n=0;
int x=0;
printf("Unesite broj n: ");
scanf("%d",&n);
while(n<=0 || n>50) {
	printf("Pogresan unos");
	printf("\nUnesite broj n: ");
	scanf("%d",&n);
}
if(n==1) {
printf("***");
return 0;}
for(i=1; i<=n;i++) {
	for(j=1;j<=n*4-3;j++) {
		if(i==j || (i+j)==2*n || (i+j)==n*2+x || (i+j)==n*4-3+1)
		printf("*");
		else printf(" ");
	
	}
	printf("\n");
x=x+2;
}
	return 0;
}
