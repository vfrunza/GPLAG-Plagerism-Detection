#include <stdio.h>

int main() {
	int i,j,n;
	do
	{
	printf("Unesite broj N: ");
	scanf("%d",&n);
	if(n%4!=0||n<8)
	{
	printf("Neispravno N!");
	}
	printf("\n");
	}while(n%4!=0||n<8);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i<=(n/2))
			{
				if(i==1)
				{
				    if(j<=(n/2))
					{
						if(j==1)
						printf("\\");
						else if(j==(n/2))
						printf("/");
						else printf(" ");
					}
				    if(j>(n/2))
					{
						if(j==((n/2)+1)||j==n)
						printf("+");
						else printf("-");
					}
				}
				else if(i>1&&i<=(n/4))
				{
					if(j<=(n/4))
					{
						if(j==i)
						printf("\\");
						else printf(" ");
					}
					else if(j>(n/4)&&j<=(n/2))
					{
						if(i+j==((n/2)+1))
						printf("/");
						else printf(" ");
					}
					else if(j>(n/2))
					{
						if(j==((n/2)+1)||j==n)
						printf("|");
						else printf(" ");
					}
				}
				else if(i>(n/4)&&i<=((n/2)-1))
				{
					if(j<=(n/4))
					{
			            if(i+j==((n/2)+1))
						printf("/");
						else printf(" ");
					}
					else if(j>(n/4)&&j<=(n/2))
					{
						if(i==j)
						printf("\\");
						else printf(" ");
					}
					else if(j>(n/2)&&j<=n)
					{
						if(j==((n/2)+1)||j==n)
						printf("|");
						else printf(" ");
					}
				
				}
			    else if(i==(n/2))
					{
						if(j==1)
						printf("/");
						else if(j==(n/2))
						printf("\\");
						else if(j>(n/2))
						{
						if(j==((n/2)+1)||j==n)
						printf("+");
						else printf("-");
						}
						else printf(" ");
					}
			}
			else if(i>(n/2))
			{
			    if(i==((n/2)+1)||i==n)
				{
				   if(j<=(n/2))
			     	{
				    	if(j==1||j==(n/2))
				        printf("+");
				    	else if(j>1||j<(n/2))
				    	printf("-");
			     	}
			     	else if(j>(n/2))
			     	{
			        	if(j==(n/2)+(n/4)||j==(n/2)+(n/4)+1)
				    	printf("|");
				    	else printf(" ");	
			     	}
				}
				else if(i>(n/2)+1||i<n)
				{
					   if(j<=(n/2))
				       {
				    	if(j==1||j==(n/2))
				        printf("|");
				    	else if(j>1||j<(n/2))
				    	printf(" ");
				       }
				       if(j>(n/2))
				       {
					     if(i==((n/2)+(n/4))||i==((n/2)+(n/4)+1))
				         { 
                            if(j==((n/2)+(n/4))||(j==(n/2)+(n/4)+1))
					        printf("+");
					        else  printf("-");
				     	 }
				         else if(i<((n/2)+(n/4))||i>((n/2)+(n/4)+1))
				     	 {
				     	 	if(j==(n/2)+(n/4)||j==(n/2)+(n/4)+1)
					        printf("|");
				            else  printf(" ");
				     	 }
				       }
				   
				 }
			}   
		}
	printf("\n");
	}
	return 0;
}
