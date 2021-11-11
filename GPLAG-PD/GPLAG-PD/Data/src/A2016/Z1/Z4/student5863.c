#include <stdio.h>

int main() {
	int n,i,j;
	
	do {
		printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n<=0 || n>50) printf("Pogresan unos\n");
	
	
	else {
for(i=0;i<n;i++)
{
	for(j=0;j<=((n-1)*4);j++)
	{
		if((i==0 && j==0) || (i==n-1 && j==n-1) || (i==0 && j==n*2-2) || (i==n-1 && j==n*3-3) || (i==0 && j==n*4-4)) printf("*");
		
		else if(i==j || i+j==(n-1)*2+i*2) printf("*");
		else if( i+j==n*2-2) printf("*");
		else if(i+j==n*4-4) printf("*");
		else printf(" ");
	}
	printf("\n");

	}

	}
	}
	while(n<=0 || n>50);
	
		
	return 0;
}
