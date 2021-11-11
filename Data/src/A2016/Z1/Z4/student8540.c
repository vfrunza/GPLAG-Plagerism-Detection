#include <stdio.h>

int main() {
	int n=0;
	
	do{
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n<=0 || n>50){printf("Pogresan unos\n");}
		
	}	while(n<=0 || n>50);
	
	int i=0, j=0;
	for(i=1; i<=n; i++) {
		for(j=1; j<i; j++ )	{printf(" ");}
		printf("*");
		for(j=0;j<2*n-(2*i + 1); j++) {printf(" ");	}
		if(i!=n || n==1) {		printf("*");}
		for(j=0;j<2*i-3;j++){printf(" ");}
		if(i!=1){printf("*");}
		for(j=0;j<2*n-(2*i + 1); j++) {	printf(" ");	}
		if(i!=n || n==1){printf("*");}
		
		
		printf("\n");
	}
	
	return 0;
}
