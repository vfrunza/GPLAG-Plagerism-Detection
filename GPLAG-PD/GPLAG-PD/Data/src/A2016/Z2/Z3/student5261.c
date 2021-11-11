#include <stdio.h>

int main()
{
	int i, j = 0, y[20], x[20], n, min = 0, temp = 0, k=0;
	
	do
	{
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n <= 0 || n > 10)
		{
			printf("Pogresan unos\n");
		}
	}
	while(n <= 0 || n > 10);
	for(i=0; i<n; i++)
	{
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &x[i], &y[i]);
		if(y[i] < 0 || y[i] > 19 || x[i] < 0 || x[i] > 19)
		{
			printf("Pogresan unos\n");
			i--;
		}
	}
	for(i=0; i<n; i++)
	{
		min = i;
		for(j=i+1; j<n; j++)
		{
			if(y[j] < y[min])
				min = j;
			else if(y[j] == y[min] && x[j] < x[min])
				min = j;
		}
		temp = y[i];
		y[i] = y[min];
		y[min] = temp;
		temp = x[i];
		x[i] = x[min];
		x[min] = temp;
	}
	
	k = 0;
	for(i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(x[i] == x[j] && y[i] == y[j])
			{
				for(k=i; k<n-1; k++)
				{
					x[k] = x[k+1];
					y[k] = y[k+1];
				}
				n--;
				i--;
				break;
			}
		}
	}
	k = 0;
	for(i=0; i<20; i++)
	{
		for(j=0; j<20; j++)
		{
			if(x[k] == j && y[k] == i)
			{
				printf("*");
				k++;
				if(k == n)
					k=0;
			}
			else
				printf(" ");
		}
		printf("\n");
	}
	
	
	return 0;
}



