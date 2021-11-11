#include <stdio.h>

int main() {
	int i,j,n;
	printf("Unesite broj N:");
	scanf("%d",&n);
	while(n<8||n%4!=0)
	{printf(" Neispravno N!\nUnesite broj N:");
	scanf("%d",&n);
	}
	printf("\n");
	n=n/2;
	i=0;
while(i<n)
{
	
	for(j=0;j<n;j++)
	{
		if(i==j)printf("\\");
		else if(j==n-1-i)printf("/");
		else printf(" ");
	}
	j=0;
	while(j<n)
	{
		if((i==0||i==n-1)&&(j==0||j==n-1))
		printf("+");
		else if(i==0||i==n-1)printf("-");
		else if(j==0||j==n-1)printf("|");
		else printf(" ");
		j++;
	}
	
	
	printf("\n");
	i++;
}

for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{if((i==0||i==n-1)&&(j==0||j==n-1))
		printf("+");
		else if(i==0||i==n-1)printf("-");
		
		else if(j==0||j==n-1)printf("|");
		else printf(" ");
	}
	for(j=0;j<n;j++)
	{
		if((i==n/2||i==n/2-1)&&(j==n/2||j==n/2-1))
		printf("+");
		else if(i==n/2||i==n/2-1)printf("-");
		else if(j==n/2||j==n/2-1)printf("|");
		else printf(" ");
		
	}
	printf("\n");
}
	return 0;
}
