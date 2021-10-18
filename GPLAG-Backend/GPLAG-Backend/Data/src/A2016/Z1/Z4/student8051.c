#include <stdio.h>

int main() {
	int k=0, i=0,j;
	float n;
	printf("Unesite broj n: ");
	scanf("%f",&n);
	k=n;
	if(n>k||n<1||n>50)
	{
		while(1)
		{
			printf("Pogresan unos\n");
			printf("Unesite broj n: ");
			scanf("%f",&n);
			k=n;
			if(n==k&&n>0&&n<51)
				break;
		}
	}
	if(n==1)
	{
		printf("***\n");
		return 0;
	}
	int p=0,sl=(4*k-3)/2,sd=(4*k-3)/2,kr=4*k-3-1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<4*k-3;j++)
		{
			if(j==p||j==sl||j==sd||j==kr)
				printf("*");
			else
				printf(" ");
				
		}
		printf("\n");
		p++;
		sl--;
		sd++;
		kr--;
	}
	return 0;
	
}
