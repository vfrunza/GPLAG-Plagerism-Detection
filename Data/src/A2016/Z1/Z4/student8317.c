#include <stdio.h>

int main() {
	int n=0,i,j,d;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	while(n>50 || n<=0)
	{
		printf("Pogresan unos\n");
	    printf("Unesite broj n: ");
	    scanf("%d", &n);
	}
	
	if(n==1)
	{
		printf("***");
	}
	else
	{
d=4*n-3;
	for(i=0;i<n;i++)
	{
		for(j=0;j<d;j++)
		{
			if (j==i ||(j==2*n-2-i) || (j==2*n-2+i) || (j==4*n-4-i))
			printf("*");
		
else
	printf(" ");
}  
		printf("\n");
	} } 
	
	
	
	return 0;
}
