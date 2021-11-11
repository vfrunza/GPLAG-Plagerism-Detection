#include <stdio.h>

int main() {
	int i,j,n,a,b,c,d,e,k;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	while(n<=0 || n>50)
	{
	printf("Pogresan unos\n");
	printf("Unesite broj n: ");
	scanf("%d",&n);
	}
	if(n==1)
	printf("***");
	else{
	printf("*");
	for(b=0;b<2*(n-1)-1;b++)
	printf(" ");
	printf("*");
	for(c=0;c<2*(n-1)-1;c++)
	printf(" ");
	printf("*\n");
	
	for(i=1;i<n-1;i++)
	{
		
 for ( j =0; j <i ; j ++)
 printf (" ") ;
 printf ("*") ;
 for(j=0;j<2*(n-i-2)+1;j++)
 printf(" ");
 printf("*");
 for ( e =0; e <i*2-1 ;e++)
 printf (" ");
 printf("*");
 for(j=0;j<2*(n-i-2)+1;j++)
 printf(" ");
 printf("*\n");
 
	}
	
	for(b=0;b<n-1;b++)
	printf(" ");
	printf("*");
	for(c=0;c<2*i-1;c++)
	printf(" ");
	printf("*\n");
	}
	return 0;
}
