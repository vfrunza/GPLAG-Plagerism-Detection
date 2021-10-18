#include <stdio.h>

int main() {
	int N,i,j;
	printf("N=");
	scanf("%d",&N);
	do
	{
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				//prvi red
				if(i==0 && j==0)
				{	printf("\\");	}
				if(i==0 && (j>0 && j<(N/2)-1))
				{	printf(" ");	}
				if(i==0 && j==(N/2)-1)
				{	printf("/");	}
				if(i==0 && j==N-1 && j==N/2)
				{   printf("+");    }
				if(i==0 && j==N/2+1 && j==N-2)
				{   printf("-");    }	
				
				//drugi red
				
				
			}
			printf("\n");
		}
	}
	while(N>=8 && N%4==0);
	return 0;
}
