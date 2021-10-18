#include <stdio.h>

int main() {
	int n, i,j;
	
	int dim;

	while(1==1)
	{	printf("Unesite broj n: ");
		scanf("%d",&n);
		if(n<1 || n>50)	printf("Pogresan unos\n");
		else break;
	}

	
	
	if(n==1)
	{ 
		dim =((2*n-2)+(2*n-1)+1);
	}
	else
	dim =((2*n-2)+(2*n-1)-1);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<=dim;j++)
		{	
			if((i==j) || (j-i)==dim/2 || i==((n-1-j)+dim/4) || i==dim-j || (i==0 && j==dim)  )
			printf("*");
			else printf(" ");
		}
		printf("\n");
	}

	return 0;
}
