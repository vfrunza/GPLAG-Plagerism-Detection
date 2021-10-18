#include <stdio.h>

int main() {
	int nizA[100][100],nizB[100][100],nizC[100][100],m,n,i,j,k,l,brB=0,brC=0,nizB2[100][100],nizC2[100][100],nizAb[100][100],nizAc[100][100];
	do
	{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
	}while(m>100||n>100||m<0||n<0);
	 for(i=0;i<m;i++)
	 for(j=0;j<n;j++)
	  nizB2[i][j]=0;
	 for(i=0;i<m;i++)
	 for(j=0;j<n;j++)
	  nizC2[i][j]=0;
	 for(i=0;i<m;i++)
	 for(j=0;j<n;j++)
	  nizAb[i][j]=0;
	 for(i=0;i<m;i++)
	 for(j=0;j<n;j++)
	  nizAc[i][j]=0;
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++)
	 for(j=0;j<n;j++)
	  scanf("%d",&nizA[i][j]);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++)
	 for(j=0;j<n;j++)
	  scanf("%d",&nizB[i][j]);
   printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++)
	 for(j=0;j<n;j++)
	  scanf("%d",&nizC[i][j]);
 for(i=0;i<m;i++)
  for(j=0;j<n;j++)
   {
    	for(k=0;k<m;k++)
         for(l=0;l<n;l++)
         {
           if(nizA[i][j]==nizB[k][l]&&nizB2[k][l]==0&&nizAb[i][j]==0)
           {
    	    brB++;
    	    nizB2[k][l]=1;
    	    nizAb[i][j]=1;
           }
    	    if(nizA[i][j]==nizC[k][l]&&nizC2[k][l]==0&&nizAc[i][j]==0)
    	   {
    	    brC++;
    	    nizC2[k][l]=1;
    	    nizAc[i][j]=1;
    	   }
         }
    }
     if(brB==m*n&&brC==m*n)
    	printf("DA");
     else printf("NE");
	return 0;
}
