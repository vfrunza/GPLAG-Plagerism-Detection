#include <stdio.h>

int main() 
	{
		int n,i=0,j=0,k=0;
		do
		{
			printf("Unesite broj n: ");
			scanf("%d",&n);
			if(n<=0 || n>50)
				printf("Pogresan unos\n");
		}while(n<=0 || n>50);
		printf("*");
		for(i=0;i<2;i++)
		{
			for(j=0;j<(2*n)-3;j++)
				printf(" ");
			printf("*");
		}
		printf("\n");
		for(i=0;i<n-2;i++)
		{
			for(j=0;j<i+1;j++)
				printf(" ");
			printf("*");
			for(j=0;j<(2*n)-(i*2)-5;j++)
				printf(" ");
			printf("*");
			for(k=0;k<(i*2)+1;k++)
				printf(" ");
			printf("*");
			for(j=0;j<(2*n)-(i*2)-5;j++)
				printf(" ");
			printf("*\n");
		}
		if(n>1)
		{
			for(i=0;i<n-1;i++)
				printf(" ");
			printf("*");
			for(i=(2*n)-3;i>0;i--)
				printf(" ");
			printf("*");
		}
		return 0;
	}