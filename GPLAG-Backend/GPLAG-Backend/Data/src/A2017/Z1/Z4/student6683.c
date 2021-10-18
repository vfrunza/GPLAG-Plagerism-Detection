#include <stdio.h>

int main() {
	
	int a,b,c,i,j;
do{
	printf("Unesite broj redova: ");
	scanf("%d",&a);
} while(a>0 && a<=10);

do {
	printf("Unesite broj kolona: ");
	scanf("%d",&b);
} while(b>0 && a<=10);
do {
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&c);
}while(c>0 && c<=10);
	
	for(i=0;i<a;i++){
		for(j=0;j<b;j+=c){
			if((i==0 && j==0) || (i==0 && j==b-1) || (i==a-1 && j==0) || (i==a-1 && j==b-1))
			printf("+");
			else 
			printf("-");
		}
		printf("\n");
	}
		
	
	return 0;
}
