#include <stdio.h>
#define N 200 


int main() {
	int  m , n,i,j,k,l,kolone,redovi,tacno=1;
	int mat[N][N];
	
	/*ispitivanje uslova iz zadatka (duzina i sirina matrice ne smije biti 0 ili manja od 0 i takodje ne smije biti veca od 200)*/

	do{
		printf("Unesite brojeve M i N: ");
	scanf("%d%d", &m,&n);
		
	if(m<=0 || m>200 ||n<=0 || n>200) printf("Brojevi nisu u trazenom opsegu.\n"); 	
	
	} while(m<=0 || m>200 ||n<=0 || n>200);
	
	/*unos matrice*/
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{scanf("%d", &mat[i][j]);
	
		}
	}
	/*izbacivanje iste kolone*/
	kolone=1;
	for(i=1;i<n; i++)
		{
			for(k=i-1; k>=0; k--)
			{
				tacno=1;
				
				for(j=0;j<m; j++)
				{
					/*kolone koje nisu jednake*/
					if(mat[j][i]!=mat[j][k]) 
					{
						tacno=0;
					break;
						
					}
				}
				if(tacno) break;
			}
				if(!tacno)
				{
					for(l=0; l<m; l++)	
					{
						mat[l][kolone]=mat[l][i];
					}
					kolone++;
					} 
				
		}
		n=kolone;
		
		/*izbacivanje istih redova*/
		redovi=1;
		for(i=1; i<m; i++)
		{
			for(k=i-1; k>=0; k--)
			{
				tacno=1;
				for(j=0; j<n; j++) 
				{
					if(mat[i][j]!=mat[k][j])
					{
						/*redovi koji nisu jednaki*/
						tacno=0; 
						break;
						
					}
				}
				if(tacno) break;
			}
			
				if(!tacno)
				{
					for(l=0; l<n; l++) mat[redovi][l]=mat[i][l];
					redovi++;
					
				} 
		}
		m=redovi;
		
		/*ispis matrice*/

		
		printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
		for(i=0; i<m; i++)
		{for(j=0; j<n; j++)
			{printf("%5d", mat[i][j]);}
		printf("\n");
		}
		
	
	
	
	return 0;
}
