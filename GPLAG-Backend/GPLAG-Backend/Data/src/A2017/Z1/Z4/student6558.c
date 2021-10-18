#include <stdio.h>

int main() {
	int i,j,k,a,b,c;
	do{
	printf("Unesite broj redova: ");
	scanf("%d",&a);
	}while(a>10 || a<=0);
	do{
	printf("Unesite broj kolona: ");
	scanf("%d",&b);
	}while(b>10 || b<=0);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&c);
	}while(c>10 || c<=0);
	for(i=1;i<2*a+2;i++){
		if(i%2==1){
			printf("+");
			for(j=0; j<b; j++){
				for(k=0; k<c; k++){
					printf("-");
				}
				printf("+");
			}
			printf("\n");
		}
		else if(i%2==0){
			printf("|");
			for(j=0; j<b; j++){
				for(k=0;k<c; k++){
					printf(" ");
				}
				printf("|");
			}
			printf("\n");
		}
	}
	return 0;
}
