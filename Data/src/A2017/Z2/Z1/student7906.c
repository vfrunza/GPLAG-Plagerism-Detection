#include <stdio.h>

int main() {
	int i, j, n;
 
	/* unos n */
	
	do
	{
		printf("Unesite broj N: ");
		scanf("%d", &n);
		if(n%4!=0 || n<8) 
		printf("Neispravno N!");
		printf("\n");
	}
	while(n%4!=0 || n<8);
	

	 
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			
			/* iksić */
			
			if(i<=n/2 && j<=n/2) {
				if(i==j)
				printf("\\");
				if(j==((n/2)+1-i))
				printf("/");
				if(i!=j && j!=((n/2)+1-i))
				printf(" ");
			}
			
			/* prvi kvadratić */
			
			if(i>n/2 && j<=n/2) {
				if(i==(n/2)+1 || i==n) {
					if(j==1 || j==n/2)
					printf("+");
					else
					printf("-");
				}
				else
				{
					if(j==1 || j==n/2)
					printf("|");
					else
					printf(" ");
				}
				}
				
				/* drugi kvadratić */
				
				if(i<=n/2 && j>n/2) {
					if(i==1 || i==n/2) {
						if(j==n/2+1 || j==n)
						printf("+");
						else 
						printf("-");
					}
					else {
						if(j==(n/2)+1 || j==n)
						printf("|");
						else
						printf(" ");
					}
					}
					
					/* nešto na kraju (oblik za kojeg nemam ime, pa samim time ni deminutiv) */
					
					if(i>n/2 && j>n/2) {
						if(i==(n/4)*3 || i==(n/4)*3+1) {
							if(j==(n/4)*3 || j==(n/4)*3+1)
							printf("+");
							else
							printf("-");
						}
						else
						{
							if(j==(n/4)*3 || j==(n/4)*3+1)
							printf("|");
							else
							printf(" ");
						}
					}
				}
					printf("\n");
	}
	return 0;
}
