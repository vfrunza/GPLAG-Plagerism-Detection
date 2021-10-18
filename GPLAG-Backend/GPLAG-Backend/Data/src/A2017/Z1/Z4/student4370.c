#include <stdio.h>

int main() {
	int i,j,a,b,n;
	do{
	printf("Unesite broj redova: ");
	scanf("%d",&a);
	}
	while(a <= 0 || a > 10);
	do{
	printf("Unesite broj kolona: ");
	scanf("%d",&b);
	}
	while(b <= 0 || b > 10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&n);
	}
	while(n <= 0 || n > 10);
	for(i = 0; i < (2*a+1); i++){
		for(j = 0; j < (b*n+b+1); j++){
			if(j%(n+1)==0){
				if(i%2==0) printf("+");
				else printf("|");
			}
			else{
				if(i%2==0) printf("-");
				else printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
