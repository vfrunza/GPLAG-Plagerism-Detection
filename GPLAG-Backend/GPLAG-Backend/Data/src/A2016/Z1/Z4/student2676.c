#include <stdio.h>

int main() {
	int n=0;
	while(n<=0 || n>50) 
	{
		printf("Unesite broj n: ");
		scanf("%d", &n);
		if (n<=0 || n>50) printf("Pogresan unos\n");
	}
	
	int i,p,p2,p3,p4;
	
	for(i=1;i<=n;i++)
	{
		for(p=1;p<i;p++)
		{
			printf(" ");
		}
		printf("*");
		for(p2=1;p2<=2*n-1-2*i;p2++)
		{
			printf(" ");
		}
		if(i<n) printf("*");
		for(p3=1;p3<=2*i-3;p3++)
		{
			printf(" ");
		}
		if(i>1) printf("*");
		for(p4=1;p4<=2*n-1-2*i;p4++)
		{
			printf(" ");
		}
		if(i<n) printf("*");
		if(n==1) printf("**");
		printf("\n");
	}
	
	return 0;
}
