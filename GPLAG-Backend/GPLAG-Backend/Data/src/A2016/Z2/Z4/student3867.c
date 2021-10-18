#include <stdio.h>
#include <math.h>
#include <string.h>

int main() 
	{
		int m,n,i,j,k,dik=0,jed=0,doge=0,pif=0,skok=0;
		float mat[100][100],pom[100][100],gof=0;
		char cir[30]="Matrica je cirkularna",tep[30]="Matrica je Teplicova",nct[50]="Matrica nije ni cirkularna ni Teplicova";
		do
		{
			printf("Unesite M i N: ");
			scanf("%d %d",&m,&n);
			if((m<1 || m>100)||(n<1 || n>100))
				printf("Pogresan unos!\n");
		}while((m<1 || m>100)||(n<1 || n>100));
		printf("Unesite elemente matrice: ");
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				scanf("%f",&mat[i][j]);
		}
/*pre-conclusion*/
		dik=m*n;
		if(m==1)
		{
			printf("%s",cir);
			return 0;
		}
		if(n==1)
		{
			printf("%s",tep);
			return 0;
		}
/*pre-elimination*/
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(fabs(mat[0][0]-mat[i][j])<0.000001)
					skok++;
			}
		}
		if(skok==dik)
		{
			printf("%s",nct);
			return 0;
		}
/*2nd circular matrix*/
		for(k=0;k<n;k++)
			pom[0][k]=mat[0][k];
		for(i=1;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				pom[i][j]=pom[i-1][j];
			}
			for(k=n-1;k>0;k--)
			{
				gof=pom[i][k];
				pom[i][k]=pom[i][k-1];
				pom[i][k-1]=gof;
			}
		}
/*circular*/		
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(fabs(pom[i][j]-mat[i][j])<0.000001)
					jed++;
			}
		}
		if(jed==dik)
		{
			printf("%s",cir);
			return 0;
		}
/*toeplitz*/		
		for(i=0;i<m-1;i++)
		{
			for(j=0;j<n-1;j++)
			{
				if(fabs(mat[i][j]-mat[i+1][j+1])<0.000001)
					pif++;
				else 
				{
					printf("%s",nct);
					return 0;
				}
			}
		}
		doge=(m-1)*(n-1);
		if(pif==doge)
		{
			printf("%s",tep);
			return 0;
		}
		return 0;
	}