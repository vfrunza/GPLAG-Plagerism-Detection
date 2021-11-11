#include <stdio.h>

int main() {
	int n, i=0,j=0;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	if (n<1 || n>50)
	{ 
	while (1){
		printf("Pogresan unos\n"); 
		printf("Unesite broj n: ");
	scanf("%d",&n);
	if (n>1 && n<50) break;
	}
	}
	if (n==1) 	printf("***");
	else 
	{ 
	for (i=1; i<=n;i++)
		{
	for(j=1; j<=4*n-3; j++)
			{
		if (j==i || j+i==2*n  ||  i+j==4*n-2 || j-i==2*n-2) 	
				printf("*");
			else
				printf(" ");
			}
		printf("\n"); 
		}
	}

	return 0;
}
