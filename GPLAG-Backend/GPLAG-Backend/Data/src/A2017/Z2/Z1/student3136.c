#include <stdio.h>

int main() 
{
	int n, i, j, x_off, y_off, b1, b2;
	do {
		printf("Unesite broj N: ");
		scanf("%d", &n);
		if (n < 8 || n % 4)
		    printf("Neispravno N!\n");
		else break;
	} while(1);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if (j >= n / 2 && i < n / 2 || j < n / 2 && i >= n / 2)
			{
				x_off = j >= n / 2 ? n / 2 : 0;
				y_off = i >= n / 2 ? n / 2 : 0;
				if ((i == y_off || i == y_off + n / 2 - 1) && (j == x_off || j == x_off + n / 2 - 1))
				    printf("+");
				else if(i == y_off || i == y_off + n / 2 - 1)
					printf("-");
			    else if (j == x_off || j == x_off + n / 2 - 1)
			        printf("|");
			    else printf(" ");
			}
			else if (j < n / 2)
			{
				if (i == j)
				    printf("\\");
				else if (j == n / 2 - i - 1)
				    printf("/");
				else printf(" ");
			}
			else
			{
				b1 = i == 3 * n / 4 - 1 || i == 3 * n / 4;
				b2 = j == 3 * n / 4 - 1 || j ==  3 * n / 4;
				if (b1 && b2)
				    printf("+");
			    else if (b1)
			        printf("-");
			    else if (b2)
			        printf("|");
			    else printf(" ");
			    
			}
		}
		printf("\n");
	}
	return 0;
}