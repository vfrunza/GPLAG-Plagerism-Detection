#include <stdio.h>

int main() {
	int i,j,n;

do {
	printf("\nUnesite broj n: ");
	scanf("%d", &n);
	if(n<=0 || n>50)
	printf("Pogresan unos");
    }
    while(n<=0 || n>50);
    if(n==1)
    printf("***");
    else{
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=4*n-3; j++)
       {    if(i==j)
            printf("*");
            else if(j==2*n-2+i)
            printf("*");
            else if(j==2*n-i)
            printf("*");
            else if(j==4*n-2-i)
            printf("*");
           else
           printf(" ");}
   
   printf("\n");
    }
    
}
    return 0;
	}

