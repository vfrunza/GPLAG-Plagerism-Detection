#include <stdio.h>

int main() {
	
	int a, b, c, i, j, h, d;          
		
		
		do {
		printf("Unesite broj redova: ");
		scanf("%d", &a);
		
		}while (a<=0 || a>10);
		
		do{
			printf("Unesite broj kolona: ");
		scanf("%d", &b);
		}while (b<=0 || b>10);
		
		do{
				printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &c);
		}while (c<=0 || c>10);

		d=(b*c)+b+1;
		h=2*a+1;
		
		for (i=0; i<h; i++) {
			for(j=0; j<d; j++) {
				
			    if((i==0 && j==0) || (i==0 && j==d-1) || (j==0 && i==h-1) || (j==d-1 && i==h-1)) printf("+");
				else if((i==0 && j%(c+1)==0) || (i==h-1 && j%(c+1)==0) || (i%2==0 && j%(c+1)==0)) printf("+");
				else if((i==0 && j%(c+1)!=0) || (i%2==0 && j%(c+1)!=0) || (i==h-1 && j%(c+1)!=0))printf("-");
				else if((j==0 && i%2!=0) || (j%(c+1)==0 && i%2!=0) || (j==d-1 && i%2!=0))printf("|");
				else printf(" ");
			}
			printf("\n");
		}
        return 0;
}
  

	

