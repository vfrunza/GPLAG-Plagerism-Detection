#include <stdio.h>

int main() {
	float nf=1;
	int n,i, j, k, l, m, x;
	
	
	do
	{
		printf("Unesite broj n: ");
		scanf("%f", &nf);
		n = nf;
		if(n<1 || n> 50 || (nf - n)!= 0 )
			printf("Pogresan unos\n");
	}while(nf < 1 || nf>50 || (nf - n) != 0);
		
	
	if ( nf > 1 && nf <= 50 && (nf-n) == 0){
	for(i = 1; i <= n; i++)
	{
		for(j=1; j<=i; j++)
		{
			if(j == i) printf("*");
			else printf(" ");
		}
		
		for(k=2*n-1; k>=(2*i); k--)
			{
				if(k==(2*i) && (i != n)) printf("*");
				else printf(" ");
			}
			
	for(x = 1; x <= i-2; x++)
		printf(" ");
	
		
	for(l=1; l<=i; l++)
		{
			if(l == i && i != 1) printf("*");
			else if (i != 1)printf(" ");
		}
	for(m=2*n-1; m>=(2*i); m--)
		{
			if(m==(2*i) && (i != n)) printf("*");
				else printf(" ");
		}
		printf("\n");
	}
	}
	else if(n == 1 && (nf - n) == 0)
		printf("***");

	
	return 0;
}
