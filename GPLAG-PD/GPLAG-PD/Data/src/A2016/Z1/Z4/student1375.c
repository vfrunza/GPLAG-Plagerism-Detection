#include <stdio.h>

int main() {
	int n,i,j,t;
	do{
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n<=0 || n>50) printf("Pogresan unos\n");
	}while (n<=0 || n>50);
	t=n*4-3;
	if (n==1) printf("***");
	else {
		for (i=0; i<n; i++)
		{
			for (j=0; j<t; j++)
			{
				if((i==j) || (i+j==(t/2)) || ((i+(n-1)*2)==j) || (((n-1)*4-i)==j)) printf("*");
				else printf(" ");
			}
		printf("\n");	
		}
	}
	
	
	
	return 0;
}
