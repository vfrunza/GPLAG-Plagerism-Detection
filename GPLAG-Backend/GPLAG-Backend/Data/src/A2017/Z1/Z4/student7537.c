#include <stdio.h>

int main() {
	int a=0, b=0, c=0, i, j, i1, j1;
do{ printf("Unesite broj redova: ");
	scanf("%d", &c);
} while (c<1 || c>10);

do{ printf("Unesite broj kolona: ");
	scanf("%d", &a);
} while (a<1 || a>10);

do{ printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &b);
} while (b<1 || b>10);

do{
	for(i1=a; i1>0; i1--){
		printf("+");
		for(j1=b; j1>0; j1--){
		 printf("-");
		}}
		printf("+\n");
		for(i=a; i>0; i--){
			printf("|");
			for(j=b; j>0; j--){
				printf(" ");
			}}
			printf("|\n");
			c--;
} while(c>0);

for(i1=a; i1>0; i1--){
		printf("+");
		for(j1=b; j1>0; j1--){
		 printf("-");
		}}
		printf("+");
		return 0;
}
