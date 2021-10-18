#include <stdio.h>

int main() {
	int n;
	LOOP:
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	if(n<=0 || n>50) { printf("Pogresan unos\n"); goto LOOP; }
	
	
	 
	if(n==1) { printf("***"); return 0; }
	int i, j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			 if(j==i) printf("*"); else printf(" ");
		}
		for(j=0;j<n-i;j++)
		{
			printf(" ");
		} 
		for(j=0;j<n-i-1;j++) 
		{
			printf(" ");
		} 
		for(j=i;j>=1;j--)
		{
			 if(j==n) j--;
			if(j==i) printf("*"); else printf(" ");
		}
		
		for(j=2;j<=i;j++)
		{	if(j==0) j++;
			if(j==i) printf("*"); else printf(" ");
		}
		for(j=0;j<n-i;j++)
		{
			printf(" ");
		} 
		for(j=0;j<n-i-1;j++)
		{
			printf(" ");
		} 
		for(j=i;j>=1;j--)
		{
			if(j==n) j--;
			if(j==i) printf("*"); else printf(" ");
		}
		
		
		printf("\n");
	}
	
	
	
	return 0;
}
