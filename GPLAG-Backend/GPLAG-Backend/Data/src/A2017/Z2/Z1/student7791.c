#include <stdio.h>

int main() {
	int n,i,j;
	int temp=0;
	do{
		printf("Unesite broj N: ");
		scanf("%d",&temp);
		if(temp % 4 != 0 || temp < 8) printf("Neispravno N!\n");
	}while( temp % 4 != 0 || temp < 8);
	n=temp;
	printf("\n");
		for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			/*X znak*/
			if(j < n/2 && i < n/2)
			{
				if(i == j) printf("\\");
				else if(j ==(n/2 - i - 1)) printf("/");
				else printf(" ");
			}
			/*Kvadrat*/
			else if((j >= n/2 && i < n/2) || (i >= n/2 && j < n/2))
			{
				if((i == 0 && j == n/2) || (i == 0 && j == n-1) || (i == n/2-1 && j == n-1) || (i == n/2-1 && j == n/2))printf("+");
				else if((i == n/2 && j == 0) || (i == n/2 && j == n/2-1) || (i == n-1 && j == 0) || (i == n-1 && j== n/2-1))printf("+");
				else if((i == 0 && j > n/2 && j < n-1) || (i == n/2-1 && j > n/2 && j < n-1)) printf("-");
				else if((i == n/2 && j > 0 && j < n/2) || (i == n-1 && j > 0 && j < n/2))printf("-");
				else if((i > 0 && i < n/2 && j == n/2) || (i > 0 && i < n/2 && j == n-1))printf("|");
				else if((i > n/2 && i < n-1 && j == 0) || (i > n/2 && i < n-1 && j == n/2-1)) printf("|");
				else printf(" ");
			}
			/*Krst*/
			else if(i >= n/2 && j >= n/2)
			{
				if(i == j || (j - n/2) == (n-i-1))
				{
					if((i == ((3*n)/4-1)) || (j == ((3*n)/4-1)) || (i ==((3*n)/4)) || (j ==((3*n)/4))) printf("+");
					else printf(" ");
				}
				else if(((j == ((3*n)/4-1)) || (j == (3*n)/4)) && ((i != (3*n)/4) && (i != (3*n)/4-1))) printf("|");
				else if(((j != (3*n)/4-1) && (j != (3*n)/4)) && ((i == (3*n)/4) || (i == (3*n)/4-1))) printf("-");
				else printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}
