#include <stdio.h>

int main() {
	int n,i,j;
	char a='*';
	printf("Unesite broj n: ");
		scanf("%d",&n);
		while(n<=0 || n>50)
	{
		printf("Pogresan unos\n");
		printf("Unesite broj n: ");
		scanf("%d",&n);
		
		
	}
	if(n==1)
	{
		printf("***");
	}
	else
	{
	printf("%c",a);
	for(i=0;i<2*(n-2)+1;i++)
{
	printf(" ");
}
printf("%c",a);
	for(i=0;i<2*(n-2)+1;i++)
{
	printf(" ");
}
printf("%c\n",a);
for(i=0;i<n-2;i++)
{
	for(j=n-i-1;j<n;j++)
	{
		printf(" ");
	}
	printf("%c",a);
	for(j=1;j<=2*(n-2)-1-2*i;j++)
	{
	printf(" ");	
	}
	printf("%c",a);
	for(j=n-2*i-1;j<n;j++)
	{
	printf(" ");
	}
	printf("%c",a);
	for(j=1;j<=2*(n-2)-1-2*i;j++)
	{
	printf(" ");	
	}
	printf("%c\n",a);
	
}
for(i=0;i<n-1;i++)
{
	printf(" ");
}
printf("%c",a);
for(i=0;i<2*(n-2)+1;i++)
{
	printf(" ");
}
printf("%c",a);
		
	}
	return 0;
}
