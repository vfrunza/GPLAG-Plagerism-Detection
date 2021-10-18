#include <stdio.h>

int main() {
    int m=0,n=0,j=0,i=0,mat[200][200]={0},br_el=0,r=0,mm=0,k=0;
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	
		if(m<1 || m>200 || n<1 || n>200)
		printf("Brojevi nisu u trazenom opsegu.\n");
	}while(m<1 || m>200 || n<1 || n>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
		scanf("%d",&mat[i][j]);
	}
	
	// IZBACIVANJE REDOVA
	
	do{
	for(i=r+1;i<m;i++){
		for(j=0;j<n;j++){
			if(mat[r][j]==mat[i][j])
			br_el++;
			if(br_el==n){
				for(mm=i;mm<m;mm++){
					for(k=0;k<n;k++)
					mat[mm][k]=mat[mm+1][k];
				}
				m--;
				i--;
				br_el=0;
			}
		}
			br_el=0;
	}
	if(i==m)
	r++;
	}while(r<m-1);
	j=0;k=0;i=0;br_el=0;r=0;
	
	// IZBACIVANJE KOLONA
	
	do{
	for(i=r+1;i<n;i++){
		for(j=0;j<m;j++){
			if(mat[j][r]==mat[j][i])
			br_el++;
			if(br_el==m){
				for(mm=i;mm<n;mm++){
					for(k=0;k<m;k++)
					mat[k][mm]=mat[k][mm+1];
			}
			n--;
			i--;
			br_el=0;
		}
	}
	br_el=0;
	}
	if(i==n)
	r++;
	}while(r<n-1);
	
	// ISPIS
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(mat[i][j]<0 && mat[i][j]>-10)
			printf("   %d",mat[i][j]);
			if(mat[i][j]<0 && mat[i][j]<=-10)
			printf("  %d",mat[i][j]);
			if(mat[i][j]>0 && mat[i][j]<10)
			printf("    %d",mat[i][j]);
			if(mat[i][j]>0 && mat[i][j]>=10)
			printf("   %d",mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
