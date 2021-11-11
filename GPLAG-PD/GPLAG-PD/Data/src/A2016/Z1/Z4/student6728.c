#include <stdio.h>

int main() {
	int n,i,j,br,br2,br3;
	
	for(;;)
	{
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if(n <= 0 || n > 50)
		printf("Pogresan unos \n");
		else break;
	}
	
	br = 2*n-2;
	br2 = 4*n-4;
	br3 = 2*n-2;
	
	if(n == 1)
	{
		printf("***");
		return 0;
	}
	
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < 4*n; j++)
		{
			if( i == j  || (i+br) == j || (i+br2) ==j || (i+br3) ==j )  printf("*");
			else printf(" ");
			
		}
		printf("\n");
		br2 -=2;
		br3 -=2;
	}
	return 0;
}