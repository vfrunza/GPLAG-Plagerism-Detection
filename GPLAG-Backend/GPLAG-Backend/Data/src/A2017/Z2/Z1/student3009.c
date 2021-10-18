#include <stdio.h>

int main()
{
	int i,j,n,c;
	do {
		printf("Unesite broj N: ");
		scanf("%d",&n); 
		if (n>=8 && n%2==0) continue;
		printf("Neispravno N!\n");
	} while (n<8 || n%2!=0);
	printf("\n");
	c=n/2;
	for(i=0; i<c; i++) {
		for (j=0; j<n; j++) {

			if (j<c) {

				if (i==j) printf("\\");
				else if((i+j)==(c-1)) printf("/");
				else printf(" ");
			} 
			else 
			{
			if ((i==0) || (i==(c-1)))
			{
				if(j==c || j==(n-1)) printf("+");
				else printf("-");
			}
			else
			{
				if (j==c || j==(n-1)) printf("|"); 
				else printf(" ");
			}
			}

		}
		printf("\n");
	}
	for(i=0; i<c; i++) {
		for (j=0; j<n; j++) {

			if (j<c) {

				if (i==0 || i==(c-1))
				{
					if (j==0 || j==(c-1)) printf("+");
					else printf("-");
				}
				else
				{
					if (j==0 || j==(c-1)) printf("|");
					else printf(" ");
				}		
			} 
			else 
			{
			if (i==(c/2) || i==(c/2-1)) 
			{
				if (j==(n-c+c/2) || j==(n-c+c/2-1)) printf("+");
				else printf("-");
			}
			else
			{
			if(j==(n-c+c/2) || j==(n-c+c/2-1)) printf("|");
			else printf(" ");
			}
			}

		}
		printf("\n");
	}
	return 0;
}
