#include <stdio.h>

int main() {
	int n,i,j; 
	do
	{   printf(" \nUnesite broj n: ");
		scanf ("%d",&n);
	
		if (n<=0 || n>50)
		printf("Pogresan unos");
		
	}while (n<=0 || n>50);
	if (n!=1)
    for (i=0; i<n; i++ )
{
	for (j=0; j<4*n-3; j++)
{ 
	if (i==j || i==n-1-j+n-1 || i==-2*n+2*1+j || i==n-1-j+3*n-3*1)
printf("*");

else  printf (" ");
	
	
}
printf("\n");
}
  else 
{printf ("***");
}
	return 0;
}
