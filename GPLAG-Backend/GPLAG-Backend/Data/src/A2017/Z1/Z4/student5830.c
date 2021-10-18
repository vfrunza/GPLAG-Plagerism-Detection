#include <stdio.h>

int main() {
	int i,j,x,y,z;
	
	do {
		printf("Unesite broj redova: ");
		scanf("%d",&x);
	}while (x<=0 || x>10);
	
		do {
		printf("Unesite broj kolona: ");
		scanf("%d",&y);
	}while (y<=0 || y>10);
	
		do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&z);
	}while (z<=0 || z>10);
	
	for (i=0; i<((2*x)+1); i++) {
		for(j=0; j<(y*(z+1)+1);j++){
			
			if (i%2==0 && j%(z+1)==0)
			printf("+");
			
			else if (i%2==1 && j%(z+1)==0)
			printf("|");
			
			else if (i%2==0)
			printf("-");
			
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}


