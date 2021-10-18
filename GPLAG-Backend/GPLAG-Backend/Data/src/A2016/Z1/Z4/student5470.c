#include <stdio.h>

int main() {
	int n,i,j;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	
while((n>50) || (n<1))
{   printf("Pogresan unos\n");
	printf("Unesite broj n: ");
	scanf("%d",&n);}
					if (n==1) printf("***");
else 
		for (i=0; i<4*n; i++)
		{for (j=0; j<(4*n)-3; j++)
		
		{
			if (((i==j) && (i<n))|| (j==((4*n)-4-i) && (i<n))||((j==(2*n)-2-i)&&(i<n))||((j==(2*n)-2+i) && (i<n)))
			printf("*");
			else printf(" ");
		}
			printf("\n");
		}
	return 0;
}
