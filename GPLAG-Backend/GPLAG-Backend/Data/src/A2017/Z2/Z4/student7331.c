#include <stdio.h>

int main()

{
	int i,j,m,n,a,b,c,x,y,z;
	int tr=0;
	int matA[100][100],matB[100][100],matC[100][100];
	int brA=0, brB=0,brC=0;
/* unos  M & N */	
		do
			{
			printf("Unesite brojeve M i N: ");
			scanf("%d",&m);
			scanf("%d",&n);
			}
		while(m>100 || m<0 || n>100 || n<0);
		
/* matrica A*/
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++)
		{ 
			for(j=0;j<n;j++)
			{ 
				scanf("%d",&matA[i][j]);
			}
		}
		
/* matrica B*/
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++)
		{ for(j=0;j<n;j++)
			{ 
				scanf("%d",&matB[i][j]);
			}
		}
		
/* matrica C*/
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++)
		{ 
			for(j=0;j<n;j++)
			{ 
				scanf("%d",&matC[i][j]);
			}
		}

	for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				{
				for(x=0;x<m;x++)
					{
					/* za A*/					
					for(a=0;a<n;a++)
					 {
					 	if(matA[x][a]==matA[i][j])	brA++;
					 }
					}
				for(y=0;y<m;y++)
					{
				    /* za B*/					
					for(b=0;b<n;b++)
					 {
					 	if(matB[y][b]==matA[i][j]) brB++;
					 }
					}
				for(z=0;z<m;z++)
					{
				    /* za C*/					
					for(c=0;c<n;c++)
					 	{
					 	 if(matC[z][c]==matA[i][j]) brC++;
					 	}
					}

		if(brA!=brB || brA!=brC)
			{
				tr=tr+1;
				break;
			}
	    if(tr==1)
	    { 
	    	     break;
	    }
	    if(tr==1)
	    { 
			printf("NE\n");
			}
	    else 
			{
			printf("DA\n");
			}
		}
	}
return 0;	
}
