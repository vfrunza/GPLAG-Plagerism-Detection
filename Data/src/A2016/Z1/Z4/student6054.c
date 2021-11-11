#include <stdio.h>

int main() {
	int red,n,kolona;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	while (n<=0||n>50){
		printf("Pogresan unos\n");
		printf("Unesite broj n: ");
		scanf("%d", &n);
	}
	if(n==1) {
		printf("***");
		
	}
	else {
	
	for(red=0; red<=n-1 ;red++){
		for(kolona=0; kolona<4*n ;kolona++){
		if(red==kolona||kolona==2*(n-1)-red||kolona==2*n-2+red||kolona==4*(n-1)-red){
			printf("*");}
		else { printf(" "); }
		}
		printf("\n");
	}
		
		
	}
	
	return 0;
}
	