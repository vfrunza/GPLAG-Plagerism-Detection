#include <stdio.h>
#include <stdlib.h>
int main() {
	
	int mat1[100][100];
	int mat2[100][100];
	int mat3[100][100];
	
	int niz1[1000]={0};
	int niz1_neg[1000]={0};
	int niz2[1000]={0};
	int niz2_neg[1000]={0};
	int niz3[1000]={0};
	int niz3_neg[1000]={0};
	
	int m,n,i=0,j=0;
	
	do{
	    printf("Unesite brojeve M i N: ");
	    scanf("%d %d", &m,&n);
	    if((m<0||m<=100)&&(n<0||n<=100)){
	        break;
	    }
	}while(1);
	
	printf("Unesite clanove matrice A: ");
	for (i=0;i<m;i++){
	    for(j=0;j<n;j++){
	        scanf("%d",&mat1[i][j]);
	    }
	}
	
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<m; i++){
		for (j=0; j<n; j++){
			scanf("%d",&mat2[i][j]);
		}
	}
	
	printf ("Unesite clanove matrice C: ");
	for (i=0; i<m; i++){
		for (j=0; j<n; j++){
			scanf ("%d", &mat3[i][j]);
		}
	}
	
	for (i=0; i<m; i++){
		for (j=0; j<n; j++){
			
			  if (mat1[i][j] >= 0)
			  niz1[mat1[i][j]]++;
			  else 
			  niz1_neg[abs(mat1[i][j])]++;
			
			  if (mat2[i][j] >= 0)
			  niz2[mat2[i][j]]++;
			  else 
			  niz2_neg[abs(mat2[i][j])]++;
			
			  if (mat3[i][j] >= 0)
			  niz3[mat3[i][j]]++;
			  else
			  niz3_neg[abs(mat3[i][j])]++;
		}
	}
	
	for (i=0; i<m; i++){
		for (j=0; j<n; j++){
			if (mat1[i][j] >= 0){
				if (niz1[mat1[i][j]]!=niz2[mat1[i][j]] || niz1[mat1[i][j]] != niz3[mat1[i][j]]){
				printf ("NE\n");
				return 0;
				}
			}
		
		else{
			 if(niz1_neg[abs(mat1[i][j])]!= niz2_neg[abs(mat1[i][j])] || niz1_neg[abs(mat1[i][j])] != niz3_neg[abs(mat1[i][j])]){
		     printf ("NE\n");
			 return 0;
			 }
		   }
	    }
    }
    printf ("DA\n");
	return 0;
}