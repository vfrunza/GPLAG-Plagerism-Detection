#include <stdio.h>

int main() {
	int n,i,j;
	printf("Unesite broj n: ");
	scanf("%d",&n);

    while (n<=0 || n>50)
    {
     	printf("Pogresan unos");
        printf("\nUnesite broj n: ");
     	scanf("%d",&n);
	}
	if(n==1)
    {
       	printf("***");
       	return 0;
    }

	for(i=0;i<=n-1;i++)
    {
    	for(j=0;j<=4*n-4;j++){
    	if(i==j || j+i==2*n-2 || j-i==2*n-2 || j+i==4*n-4)
     	printf("*");
    	else
    	printf(" ");
    }
    	printf("\n");
	
}
	
	
	return 0;
}
