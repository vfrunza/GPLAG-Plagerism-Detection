#include <stdio.h>

int main()
{
	int i,j,k,sir,vis,m,n,isti=1;
	int mat[200][200];
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
		if(m<=0 || n<=0 || n>200 || m>200) printf("Brojevi nisu u trazenom opsegu.\n");
	} while(n<=0 || m<=0 || n>200 || m>200);
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf("%d",&mat[i][j]);
     
     for(i=0;i<m-1;i++)
     {
     	for(j=i+1;j<m;j++)
     	{
     		isti=1;
     		for(k=0;k<n;k++)
     		{
     			if(mat[i][k]!=mat[j][k]) { isti=0; break;}
     		}
     		if(isti==1)
     		{
     			for(vis=j;vis<m-1;vis++)
     			{
     				for(k=0;k<n;k++)
     				mat[vis][k]=mat[vis+1][k];
     			}
     			m--;
     			j--;
     		}
     		
     	}
     }
     for(i=0;i<n-1;i++)
     {
     	for(j=i+1;j<n;j++)
     	{
     		isti=1;
     		for(k=0;k<m;k++)
     		{
     			if(mat[k][i]!=mat[k][j]) {isti=0; break; }
     		}
     		if(isti==1)
     		{
     			for(sir=j;sir<n-1;sir++)
     			{
     			    for(k=0;k<m;k++)
     			    mat[k][sir]=mat[k][sir+1];
     			}
     			n--;
     			j--;
     		}
     	}
     }
     
     
     
     printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
     for(i=0;i<m;i++)
        {for(j=0;j<n;j++)
        	printf("%5d",mat[i][j]);
        	printf("\n");
        }
     
 


	return 0;
}
