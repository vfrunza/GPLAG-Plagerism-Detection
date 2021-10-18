#include <stdio.h>

int main() {
	
	int n;
	int i,j;
	char c1 = 92;
	char c2 = '/';
	int cetvrtina;
	int brojac = 0;
	int uslov_1 = 0;
	int uslov_2 = 0;
	int uslov = 0;
	
	do
	{
		if (brojac!=0)
			printf("Neispravno N!\n");
		printf("Unesite broj N: ");
		scanf("%d", &n);
		brojac++;
		
		uslov_1 = 0;
		uslov_2 = 0;
		uslov = 1;
		if (n>=8)
			uslov_1 = 1;
		if (n%4 == 0)
			uslov_2 = 1;
			
		if (uslov_1 == 1 && uslov_2 == 1)
			uslov = 0;
	} while (uslov == 1);
	
	cetvrtina = n/4;
	printf("\n");
	
	for (i = 0; i < n; i++)
	{
		if (i<n/2)
			{
				for (j = 0; j<n;j++)
					{
						if (j<n/2)
							{
							if (i == j)
								printf("%c", c1);
							else if (j == n/2-i-1)
								printf("%c", c2);
							else
								printf(" ");
							}
						else
							{
								if ((i == 0 && j == n/2) || (i == 0 && j == n-1) || (i == n/2-1 && j == n/2) || (i == n/2-1 && j == n-1))
									printf("+");
								else if ((i == 0 || i == n/2-1 ) && j>n/2 && j<n-1)
									printf("-");
								else if (i > 0 && i < n/2-1 && (j == n/2 || j == n-1))
									printf("|");
								else
									printf(" ");
							}
					}
					
				
				
				
			}
		else
			{
				for (j = 0; j < n; j++)
					{
						if (j<n/2)
							{
								if ((i == n/2 && j == 0) || (i == n/2 && j == n/2-1) || (i == n-1 && j == 0) || (i == n-1 && j == n/2-1))
									printf("+");
								else if ((i == n/2 || i == n-1) && j > 0 && j < n/2-1)
									printf("-");
								else if (i > n/2 && i < n-1 && (j == 0 || j == n/2-1))
									printf("|");
								else
									printf(" ");
							}
						else
							{
								if ((i == n/2+cetvrtina-1 || i == n/2+cetvrtina) && (j == n/2+cetvrtina-1 || j == n/2+cetvrtina))
									printf("+");
								else if ((i == n/2+cetvrtina-1 || i == n/2+cetvrtina) && (j < n/2+cetvrtina-1 || j > n/2+cetvrtina))
									printf("-");
								else if ((i < n/2+cetvrtina-1 || i > n/2+cetvrtina) && (j == n/2+cetvrtina-1 || j == n/2+cetvrtina))
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
