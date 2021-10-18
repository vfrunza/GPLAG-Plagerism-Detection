#include <stdio.h>
int main() {
	int i,j,N;
	do{ printf("Unesite broj N: \n");
		scanf("%d",&N);
		if(N<8)
		{printf("Neispravno N!");
			
		}
	}while( N<8 || N%4!=0);
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
	   {	if(i<=(N/2))
		{ 
			if (j<=(N/2))
			{
				if(i==j)
			printf("\\");
		    else if (i==((N/2)+1)-j)
			printf("/");
			else
			printf(" ");
			}
		else
		{	if(i==1 || i==(N/2))
			{
				if ((j==((N/2)+1)) || (j==N))
				printf("+");
				else 
				printf("-");
			}
			else if (j>(N/2))
			{
				if(j==((N/2)+1) || j==N)
				printf("|");
				else
				printf(" ");
			}
	 }
		}
		else
		{     if(j<=(N/2))
			{	if((i==(N/2)+1) || i==N)
			{
				if ((j==1) || (j==(N/2)))
			{	printf("+");}
				else 
				{printf("-");}
			}
			else
			{
				if(j==1 || j==(N/2))
				printf("|");
				else
				printf(" ");
			}
		} 
		else
		{
			if(((j==((N/2)+(N/4))) && ((i!=(N/2)+(N/4)) && (i!=(N/2)+(N/4)+1)))) 
	    	printf("|");
	    	if((j==((N/2)+(N/4)+1)) && ((i!=(N/2)+(N/4)+1) &&  (i!=(N/2)+(N/4))))
	    	printf("|");
	    	if(((i!=((N/2)+(N/4))) && (i!=((N/2)+(N/4)+1)))  && ((j!=((N/2)+(N/4))) && (j!=((N/2)+(N/4)+1))))
	    	printf(" ");
	    	if(((i==((N/2)+(N/4))) && ((j!=((N/2)+(N/4))) && (j!=((N/2)+(N/4)+1))))  || ((i==((N/2)+(N/4)+1)) && ((j!=((N/2)+(N/4))) && (j!=((N/2)+(N/4)+1))))) 
	    	printf("-");
	    	if ((i==(N/2)+(N/4)) && ((j==(N/2)+(N/4)) || (j==(N/2)+(N/4)+1)))
	    	printf("+");
          	if ((i==(N/2)+(N/4)+1) && ((j==(N/2)+(N/4)) || (j==(N/2)+(N/4)+1)))
	    	printf("+");
	    	}
	  }
	   	}
	   printf("\n");
	}
		return 0;}

