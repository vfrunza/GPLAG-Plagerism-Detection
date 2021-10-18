#include <stdio.h>

int main() {
	printf("Unesite sirinu i visinu matrice A: ");
	int m,n;
	int p,q;
	scanf("%i %i",&m,&n);
	printf("Unesite clanove matrice A: ");
	int i,j,matA[101][101],matB[101][101],mbbb[299][299];
	for (i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf("%i",&matA[i][j]);
		
	
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%i %i",&p,&q);
	printf("Unesite clanove matrice B: ");
	for (i=0; i<p; i++)
		for(j=0; j<q; j++)
			scanf("%i",&matB[i][j]);
		
	
	
	int x,y,temp,da;
/*	for (i = 0; i < m; i++)
    {
        for ( j = i + 1; j < n; j++)
        {
            temp = matA[i][j];
            matA[i][j] = matA[j][i];
            matA[j][i] = temp;
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n / 2; j++)
        {
            temp = matA[i][j];
            matA[i][j] = matA[i][n - 1 - j];
            matA[i][n - 1 - j] = temp;
        }
    }
*/
for(i=0;i<m;i++){
for(j=0;j<n;j++){
mbbb[j][m-1-i]=matA[i][j];
}
	
}



 


if((p==n) && (m==p)){
    for(i=0; i<p; i++){
		for(j=0;j<q; j++){
			if(mbbb[i][j] != matB[i][j]){
			da = 0;	
				break;
		
				
			}
			//da = 0;
			else da = 1;
			
		}
	}
	
	if (da == 1)
	printf("DA\n");
	else
	printf("NE\n");
}else
	printf("NE\n");
	
	
	
	
	
	
	
	return 0;
}
