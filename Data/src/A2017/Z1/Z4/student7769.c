#include <stdio.h>

int main() {
	int i,j,a,b,c;
	printf("Unesite broj redova: ");
	scanf("%d",&a);
	printf("Unesite broj kolona: ");
	scanf("%d",&b);
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&c);
	do {
		for(i=1;i<=a;i++){
			for(j=1;j<=b;j++){
				if (j=j+2)
				printf("+");
				
				
			}
			printf("\n");}
		
	}
	while((a>0 && a<=10) && (b>0 && b<=10) && (c>0 && c<=10));
	return 0;
}
