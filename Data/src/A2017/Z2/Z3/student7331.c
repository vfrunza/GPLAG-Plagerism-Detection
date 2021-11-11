#include <stdio.h>

int main() 
{
	int m,n,a,b,i,j,v,r;
	int matA[100][100];
	int matB[100][100];
	int matT[100][100];
	int matR[100][100];
	
	/*UNOS PRVE MATRICE*/
		printf("Unesite sirinu i visinu matrice A:");
		scanf("%d""%d",&m,&n);
	 	for(i=0; i<n; i++)
	 		{
    	 	for(j=0;j<m;j++) 
    	 		{	
         		printf("Unesite clanove matrice A:");
         		scanf("%d", &matA[i][j]);
         		}
   		
   			
   	/*UNOS DRUGE MATIRCE*/
   		printf("Unesite sirinu i visinu matrice B:");
		scanf("%d""%d",&b,&a);
		 for(i=0; i<a; i++)
	 		{
    		 	for(j=0;j<b;j++) 
    		 		{
        		 	printf("Unesite clanove matrice B:");
        		 	scanf("%d", &matB[i][j]);
        	 		}
   		
   			
	/*TRANSPONOVANJE MATRICE A */
		for(i=0;i<n;i++)
			{
			 for(j=0;j<m;j++)
			 	{
			 		matT[j][i]=matA[i][j];
			 	}
			}
			
	/* ROTIRANJE */
		for(i=0;i<m;i++)
			{
				for(r=n-1,v=0;r>=0;r--,v++)
				{
				matR[i][v]=matT[i][r];
				}
			}
			
	/* UPOREDJIVANJE*/
   		if (matT[i][r] != matB[i][j])
            {
                printf("NE\n");
                return 1;
            }
       
    printf("DA\n");
	 		}
	 		} 				
   			
return 0;
}