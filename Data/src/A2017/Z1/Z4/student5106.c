#include <stdio.h>
int main() {
	int n,m,s,i,j,br;
	do
	{
	printf("Unesite broj redova: ");
	scanf("%d",&m);
	}
	while(m<=0 || m>10);
	do
	{
	printf("Unesite broj kolona: ");
	scanf("%d",&n);
	}
	while(n<=0 || n>10);
	do
	{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&s);
	}
	while(s<=0 || s>10);
	m=m*2;
	n=n+(n*s);
for(i=0;i<=m;i++)
{
	
for(j=0;j<=n;j++)
{
	
	if(i%2==0)
	{
		if(j==0)
		{
			printf("+");
		}
		if(j==n)
		{
			
			break;
		}
		br=0;
		while(br<s)
		{
			printf("-");
			br=br+1;
			j=j+1;
		}
		printf("+");
	}
	else
	{
		if(j==0)
		{
			printf("|");
		}
		if(j==n)
		{
			break;
		}
		br=0;
		while(br<s)
		{
			printf(" ");
			br=br+1;
			j=j+1;
		}
		printf("|");
	}
}
printf("\n");
		
}
	return 0;
}
