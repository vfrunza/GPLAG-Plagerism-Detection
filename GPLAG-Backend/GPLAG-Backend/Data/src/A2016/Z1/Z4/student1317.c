#include <stdio.h>

int main()
{
	int i, j;
	int n, brpraz1, brpraz2;
	
start: printf("Unesite broj n: ");
	   scanf("%d", &n);
	if(n > 0 && n <= 50)
	{
		if(n == 1) printf("***\n");
		else if(n == 2) 
		{
			printf("* * *\n");
			printf(" * *\n");
		}
		else
		{
			brpraz1 = 2 * n - 3;
			
			/* Ispis prvog reda */
			printf("*");
			for(j = 0; j < brpraz1; j++) printf(" ");
			printf("*");
			for(j = 0; j < brpraz1; j++) printf(" ");
			printf("*\n");
			
			brpraz1 -= 2;
			brpraz2 = 1;
			
			for(i = 0; i < n - 2; i++)
			{
				for(j = 0; j <= i; j++) printf(" ");
				printf("*");
				for(j = 0; j < brpraz1; j++) printf(" ");
				printf("*");
				for(j = 0; j < brpraz2; j++) printf(" ");
				printf("*");
				for(j = 0; j < brpraz1; j++) printf(" ");
				printf("*\n");
				
				brpraz1 -= 2;
				brpraz2 += 2;
			}
			/* Ispis posljednjeg reda */
			for(j = 0; j < n - 1; j++) printf(" ");
			printf("*");
			for(j = 0; j < brpraz2; j++) printf(" ");
			printf("*\n");
		}
	}
	else 
	{
		printf("Pogresan unos\n");
		goto start;
	}
	return 0;
}
