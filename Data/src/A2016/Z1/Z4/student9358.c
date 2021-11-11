#include <stdio.h>

int main() {
	int n=-1,i,j;
	
    while(1)
    {   
    	printf("Unesite broj n: ");
    	scanf("%d",&n);
    	if(n<=0 || n>50) 
    	{
    		printf("Pogresan unos\n"); 
    		continue;
    	}
    	else break;
    }
    

	if(n==1) {printf("***"); return 0;}
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=4*n-3;j++)
	{
		if (i==j || i+j==2*n || j==2*n-1+i-1 || i+j==4*n-2) 
		printf("*"); 
		else printf(" ");
	}
	printf("\n");
	}
	return 0;
}
