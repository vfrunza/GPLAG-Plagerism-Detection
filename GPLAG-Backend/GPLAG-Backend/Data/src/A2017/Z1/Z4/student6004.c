#include <stdio.h>

int main()
{

	int i,j,a,b,c;

	do {

		printf ("Unesite broj redova: ");
		scanf ("%d", &a);
		
	} while(a<=0 || a>10);

	do {
		
		printf("Unesite broj kolona: ");
		scanf("%d", &b);
	
		
	} while(b<=0  || b>10);

	do {
		printf ("Unesite sirinu jedne kolone: ");
		scanf ("%d", &c);
	
		
	} while(c<=0 || c>10);


	for(i=0; i<a+a+1; i++) {
		
		for(j=0; j<c*b+b+1; j++) {
		
			if(i%2==0) {
		
				if(j%(c+1)==0) printf("+");
		
				else printf("-");
		
			} else {
		
				if(j%(c+1)==0) printf("|");
	
				else printf(" ");
			}

		}
		printf("\n");
	}

	return 0;
}
