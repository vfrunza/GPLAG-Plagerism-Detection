#include <stdio.h>

int main() {
	int i, j, n;
	do{
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<=0||n>50) printf("Pogresan unos\n");
	}
	while(n<=0||n>50);
	if(n==1){
	for(i=1;i<=1;i++){
		for(j=1;j<=3;j++){
		if(i==1&&j<=3) printf("*");
		else printf(" ");
		}
		printf(" ");
	}
	}
	else{
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j) printf("*");
			else printf(" ");
		}
			for(j=n+1;j<=2*n-1;j++){
		if(j==2*n-i) printf("*");
		else printf(" ");
		}
			for(j=2*n;j<=3*n-2;j++){
			if(j==i+2*n-2) printf("*");
			else printf(" ");
		}
			for(j=3*n-1;j<=4*n-3;j++){
		if(j==4*n-2-i) printf("*");
		else printf(" ");
		}
		printf("\n");
	}
	}
	return 0;
}
