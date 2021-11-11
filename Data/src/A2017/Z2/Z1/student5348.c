#include <stdio.h>

int main() {
	
	int n;
	int i,j,k,g;
	int x=0;
	

	do
	{
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if(n%4!=0 || n<8)printf("Neispravno N!");
		printf("\n");
	}
	while(n%4!=0 || n<8);
	
	
	for(i=0;i<n/2;i++)
	{
		
		for(j=0;j<n/2;j++)
		{		if(j==x) printf("\\");	else if(j==(n/2)-x-1)printf("/");	else printf(" ");	}x++;
		
		
		if(i==0 || i==n/2-1)
		{
			printf("+");
			for(g=0;g<(n/2)-2;g++)
			printf("-");
			printf("+");
		}
		else
		{
			printf("|");
			for(g=0;g<(n/2)-2;g++)
			printf(" ");
			printf("|");
		}
		printf("\n");
	
	}
/////////////////////////////////////////////////////////////////////////
	for(i=0;i<n/2;i++)
	{
		x=n/4;
		x-=1;
		
			if(i==0 || i==n/2-1)
		{
			printf("+");
			for(g=0;g<(n/2)-2;g++)
			printf("-");
			printf("+");
		}
		else
		{
			printf("|");
			for(g=0;g<(n/2)-2;g++)
			printf(" ");
			printf("|");
		}
		
		if(i==x || i==x+1)
		{
			for(g=0;g<n/2;g++)
			{
				if(g==x || g==x+1)printf("+");else printf("-");
			}
		}
		else
		{
			for(g=0;g<n/2;g++)
			{
				if(g==x || g==x+1)printf("|");else printf(" ");
			}
		}
		
		
		printf("\n");
		
	}
	
	
	
	return 0;
	
	
}
