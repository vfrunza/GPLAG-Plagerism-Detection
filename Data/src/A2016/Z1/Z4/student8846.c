#include <stdio.h>

int main() 
{
	int n,i,a;
	int ispravnost=0;
	while(ispravnost!=1)
	{
	printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n<1 || n>50) 
	{
		printf("Pogresan unos\n");
		
	}
	else ispravnost=1;
	}
	if(n==1) printf("***");
	else if(n==2) printf("* * *\n * * ");
	else
	{
	 for(i=0;i<n;i++)
	  {
            if(i==0)
            {
                printf("*");
                for(a=0;a<2*n-3;a++)
                printf(" ");
                printf("*");
                for(a=0;a<2*n-3;a++)
                printf(" ");
                printf("*");
            }
            else if(i==n-1)
            {
                for(a=0;a<i;a++)
                printf(" ");
                printf("*");
                for(a=0;a<2*n-3;a++)
                printf(" ");
                printf("*");
                for(a=0;a<i;a++)
                printf(" ");
            }
            else
            {
                for(a=0;a<i;a++)
                printf(" ");
                printf("*");
                for(a=0;a<2*(n-i)-3;a++)
                printf(" ");
                printf("*");
                for(a=0;a<(4*n-3)-(2*i + 4* (n-i)-2);a++)
                printf(" ");
                printf("*");
                for(a=0;a<2*(n-i)-3;a++)
                printf(" ");
                printf("*");
                for(a=0;a<i;a++)
                printf(" ");
            }
          printf("\n");
	 }
	}
	return 0;
}
