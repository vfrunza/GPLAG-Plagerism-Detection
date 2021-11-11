#include <stdio.h>
int main() {
    int mat[200][200],m,n,i,j, z=0, k, h;
    do{
        printf("Unesite brojeve M i N: ");/*Unos dimenzija matrice*/
        scanf("%d %d",&m,&n);
        if(n<=0||n>200||m<=0||m>200)
        {
            printf("Brojevi nisu u trazenom opsegu.\n");
        }
    }while(n<=0||n>200||m<=0||m>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	    for(j=0;j<n;j++)
	        scanf("%d",&mat[i][j]);/*unos elemenata*/
	for(i=1;i<m;i++)
	{
	    for(k=0;k<i;k++)
	   {
	        z=0;
	        for(j=0;j<n;j++)
	        {
	           if(mat[i][j]!=mat[k][j])/*Provjeravam jednakost elemenata dvije kolone*/
	           {
	               z=1;
	               break;
	           }
	        }
	        if(z==0){
	            for(h=i;h<m-1;h++)/*petlja izbacanja krajnje desne kolone u slucaju da postoje jednake 2 ili vise kolona*/
	            {
	                for(j=0;j<n;j++)
	                    mat[h][j]=mat[h+1][j];
	            }
	            m--;
	            i--;
	        }
	   }
	}
	
	for(j=1;j<n;j++)
	{
		for(k=0;k<j;k++)
		{
			z=0;
			for(i=0;i<m;i++)
			{
				if(mat[i][j]!=mat[i][k])/*Provjeravam jednakost elemenata dvije vrste*/
				{
					z=1;
					break;
				}
			}
			if(z==0)
			{
				for(h=j;h<n-1;h++)
				{
					for(i=0;i<m;i++)
						mat[i][h]=mat[i][h+1];/*izbacanje vrste ako postoje dvije iste*/
				}
				j--;
				n--;
			}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<m;i++){/*ispis transformirane matrice*/
	    for(j=0;j<n;j++)
	        {
	            printf("%5d",mat[i][j]);
	        }
	        printf("\n");
	}
	return 0;
}