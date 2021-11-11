#include <stdio.h>

int main() {
int i,n,j;
greska:
printf("\nUnesite broj n: ");
scanf("%d",&n);
if(n==1) {printf("***"); return 0;}

if((n<=0) || (n>50)) {
	printf("Pogresan unos");
	goto greska;

	
}

for(i=0;i<n;i++) {
	
	for(j=0;j<4*n-3;j++){
		
if((j==i)||(j==2*n-i-2)||(j==i+2*n-2)||(j==4*n-i-4))
		printf("*");
		else{
			printf(" ");
			
		}
		
	}
	
printf("\n");

	
}
	return 0;
}
