#include <stdio.h>

int main() 
{
	
	int n,i,j;
	
	
	
	do{
		printf("\nUnesite broj N: ");
		scanf("%d",&n);
		if(n<8 || n%4!=0)
		printf("Neispravno N!");
	}while(n<8 || n%4!=0);
	
	printf("\n");
	
	//dvije for petlje
	for(i=0;i<n/2;i++)
	{
		for(j=0;j<n;j++)
		{					   
			
			
			
			if(j==i)
			{
				printf("\\");
			}
			else if(j==(((n/2)-1)-i))
			{
				printf("/");
			}
			
			else if((i == 0 || i == (n/2) - 1) && (j == (n/2)  || j == (n - 1))) 
			{
				printf("+");
			} 
			else if((i == 0 || i == (n/2) - 1) && (j>(n/2) && j< (n - 1))) 
			{
				printf("-");
			} 
			else if((i>0 && i<(n/2) - 1) && (j == (n/2) || j == (n - 1))) 
			{
				printf("|");
			} 
			else if((i>0 && i<((n/2)-1)) && (j>(n/2) && j<(n-1)))
			{
				printf(" ");
			}
			else 
			{
				printf(" ");
			}
		
					
		
	
	}
	printf("\n");
}
	
	for(i=0;i<n/2;i++)
	{
		for(j=0;j<n;j++)
		{
			if((i == 0 || i == (n/2) - 1) && (j == 0  || j == (n/2) - 1)) 
			{
				printf("+");
			} 
			else if((i == 0 || i == (n/2) - 1) && (j>0 && j< (n/2) - 1)) 
			{
				printf("-");
			} 
			else if((i>0 && i<(n/2) - 1) && (j == 0 || j == (n/2) - 1)) 
			{
				printf("|");
			} 
			else if ((i>0 && i<((n/2)-1)) && (j>0 && j<(n/2)- 1))
			{
				printf(" ");
			}
			
			//zadnja slika
				else if((((i==0 || i<(n/2)-(n/4)- 1)) && ((j==(((n/4)- 1) + (n/2)) || j==((n/4)+(n/2))))))
			{
				printf("|");
			}
			else if((i==((n/2)-(n/4)- 1) || i==((n/2)-(n/4))) && ((j==(((n/4)- 1) + (n/2)) || j==((n/4)+(n/2)))))
			{
				printf("+");
			}
			else if((i>(n/2)-(n/4) || i<(n/2)) && (j==(((n/4)- 1) + (n/2)) || j==((n/4)+(n/2))))
			{
				printf("|");
			}
 	        else if ((j>(n/2) || j<(n-(n/2)+ 4)) && ((i==(n/2)-(n/4)- 1) || i==((n/2)-(n/4))))
			{
				printf("-");
			}
			else if (((j>(n-(n/2)+ 5) || j==n)) && ((i==((n/2)-(n/4)- 1) || i==((n/2)-(n/4)))))
			{
				printf("-");
			}
			else
			{
				printf(" ");
			}
			
			
			
			
		}
		
		printf("\n");
	}
	
	
	return 0;

}