#include <stdio.h>
#define Limit 50

int main() {
	int n, i, j, k, counter1 = 0, counter2 = 0;
	
	for (j = 0; j < 1; j++){
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	if (n <= 0 || n > Limit){
		printf("Pogresan unos\n");
		j--;
	} 
	else{
			for (i = 1; i <= n; i++)
			{
				for(k = 1; k <=  1 + (n-1)*4; k++)
				{
					if(n == 1)
					{
						printf("***");
						break;
					}
					if ((i == k))
					{
					printf("*");
					continue;
					}
					if (k == i + (n-1) * 2)
					{
					printf("*");
					continue;
					}
					if (k == i + (n-1) * 4)
					{
					printf("*");
					continue;
					}
					if (i > 1 && (i != n) && k == (n-1) * 2 - counter1)
					{
					printf("*");
					counter1++;
					continue;
					}
					if (i > 1 && (i != n) && k == (n-1) * 4 - counter2)
					{
					printf("*");
					counter2++;
					continue;
					}
					printf(" ");
				}
				printf("\n");
			}
		}
		
	}
	
	return 0;
}
