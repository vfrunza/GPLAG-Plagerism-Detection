#include <stdio.h>
int main() {
	int n, i, j;
	t : printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<1 || n>50) 
	{ printf("Pogresan unos \n");
	goto t ;
	}
	else if(n==1) 
	printf("***");
	else {
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=4*n-3;j++)
			{
				if(j==i || j==2*n+i-2 || j+i==2*n ||j+i==4*n-2)
				printf("*");
				else printf(" ");
			}
			printf("\n");
		}

	printf("\n");
	
	}

	return 0;
}
