#include <stdio.h>

int main() {
	int n,i,a,x,y,mat[10][2];
	int pronadjen=0;
	while(1)
	{
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		if(n<=0 || n>10)
			{
			printf("Pogresan unos\n"); continue;
			}
		else break;
	}
	
		
		
		for(i=0;i<n;i++)
		{   
			printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d",&mat[i][0],&mat[i][1]);
			if(mat[i][0]<0 || mat[i][0]>19 || mat[i][1]<0 || mat[i][1]>19)
				{	 
				printf("Pogresan unos\n");
				i--;
				}
		}
		
		for (y=0;y<20;y++)
		{   
			for(x=0;x<20;x++)
			{   
				pronadjen=0;
				for(a=0;a<n;a++)
				{
					if (x==mat[a][0] && y==mat[a][1]) 
					{   
						pronadjen=1;
						printf("*");
                        break;
					}
				}
			if(pronadjen==0) printf(" ");
			}
			printf("\n");
		}
		
		
				
		
		
		
		
	

return 0;
}
