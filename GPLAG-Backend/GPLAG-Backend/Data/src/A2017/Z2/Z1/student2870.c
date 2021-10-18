#include <stdio.h>

int main() {
	int n,i,j;
	do{
		printf("Unesite broj N: ");
		scanf("%d", &n);
		
		if ((n%4!=0) || (n<8)) printf("Neispravno N!\n");
		
	}while ((n%4!=0) || (n<8));
	
	printf("\n");
	
	for (i = 0; i < n; i++) {
		
		if (i<(n/2))
		{
			for (j = 0; j < n; j++)
			{
				
				if (i==0) 
				{
					if (j==0) printf("\\");
					else if (j==((n/2)-1)) printf("/");
					else if (((j>0)&&(j<(n/2))) || (j<((n/2)-1))) printf(" ");
					else if ((j==(n/2))||(j==(n-1))) printf ("+");
					else printf("-");
				} 
				
				
				else if (((i>0)&&i<((n/2)-1)))
				{
					if (j==i) printf("\\");
					else if (j==((n/2)-1-i)) printf("/");
					else if ((j==(n/2))||(j==(n-1))) printf ("|");
					else printf(" ");
				} 
				
				else if (i==((n/2)-1))
				{
					if (j==0) printf("/");
					else if (j==((n/2)-1)) printf("\\");
					else if (((j>0)&&(j<(n/2))) || (j<((n/2)-1))) printf(" "); 
					else if ((j==(n/2))||(j==(n-1))) printf ("+");
					else printf("-");
				} //do pola
			
			}
				printf("\n");
		}
		
		else //od pola
		{
			for (j = 0; j < n; j++)
			{
				
				if ((i==(n/2)) || (i==(n-1))) 
				{
					if (j>=0 && j<(n/2))
					{
						if ((j==0)||(j==((n/2)-1))) printf ("+");
						else printf("-");
					}
					else
					{
						if (j>=(n/2) && j<n)
						{
							if ((j==((n*3)/4)) || (j==((n*3)/4)-1)) printf ("|");
							else printf(" ");
						}
					}
				} 
				
				else
				{
					if (j>=0 && j<(n/2))
					{
							if ((j==0) || (j==((n/2)-1))) printf ("|");
							else printf(" ");
					} 
					
					else 
					{
							if ((i!=((n*3)/4)) && (i!=((n*3)/4)-1))
							{
								if ((j==((n*3)/4)) || (j==((n*3)/4)-1)) printf ("|");
								else printf(" ");
							}
							else 
							{
								if ((j==((n*3)/4)) || (j==((n*3)/4)-1)) printf ("+");
								else printf("-");
							}
					}
					
				}
				
			}
			printf("\n");
		}
		
	}

	
	return 0;
}
