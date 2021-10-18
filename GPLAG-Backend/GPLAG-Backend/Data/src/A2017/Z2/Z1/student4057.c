#include <stdio.h>

int main() {
	int n,i,j;
	
	do
	{
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if(n<8||n%4!=0)
		printf("Neispravno N!");
		printf("\n");
	}
	while(n<8||n%4!=0);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i<n/2&&j<n/2)
			{
				if(i==j)
				printf("\\");
				else if(i+j==n/2-1)
				printf("/");
				else
				printf(" ");
			}
			else if(j>=n/2&&i<n/2)
			{
				if(((j%(n/2)==0||j==n-1)&&i==0)||(i%(n/2-1)==0&&(j%(n/2)==0||j==n-1)))
				printf("+");
				else if((j>n/2 && j<n &&i==0)||(i==n/2-1&&j>n/2&&j<n))
				printf("-");
				else if((j==n/2||j==n-1)&&(i>0||i<n-1))
				printf("|");
				else
				printf(" ");
			}
			else if(i>=n/2&&j<n/2)
			{
				//if((i==n/2||i==n)&&(j==0||j==n/2-1))
				if(((i%(n/2)==0||i==n-1)&&j==0)||(j%(n/2-1)==0&&(i%(n/2)==0||i==n-1)))
				printf("+");
				//else if((i==n/2||i==n)&&(j>0&&j<n/2-1))
				else if((j<n/2-1 && j>0 &&i==n/2)||(i==n-1&&j<n/2-1&&j>0))
				printf("-");
				else if((i>n/2&&i<n)&&(j==0||j==n/2-1))
				printf("|");
				else
				printf(" ");
			}
			else
			{
				if((j==i&&(i>=(n/2)+n/4-1)&&i<n-(n/4-1))||((i==j-1||j==i-1)&&(j>=n/2+n/4-1)&&(j<n-n/4+1)&&(i>=n/2+n/4-1)&&(i<n-n/4+1)))
				printf("+");
				else if(j==n/2+n/4||j==n/2+n/4-1)
				printf("|");
				else if((i==n/2+n/4||i==n/2+n/4-1))
				printf("-");
				else
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
