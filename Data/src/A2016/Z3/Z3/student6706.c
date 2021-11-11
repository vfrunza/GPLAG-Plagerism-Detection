#include <stdio.h>

int main() {
	int mat[200][200],m,n,i,j,k,jeste=1,xk=0,yk=0,z;
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d%d",&m,&n);
	if(m>200 || m<=0 || n>200 || n<=0) printf("Brojevi nisu u trazenom opsegu.\n");
	}while(m>200 || m<=0 || n>200 || n<=0);
	/*unos*/
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
		}
	}
		/*isti red*/
    for(i=0;i<m-1;i++){
		for(j=i+1;j<m;j++){
			jeste=1;
			for(k=0;k<n;k++){
		if(mat[i][k]!=mat[j][k]) {
			jeste=0; break;}
			}
			if(jeste) {
				yk=j;
	for(k=0;k<n;k++){
		for(z=yk;z<m-1;z++)
		mat[z][k]=mat[z+1][k];
	}
	m--; j--;
	}
		}
	}
	/*ista kolona*/
    for(i=0;i<n-1;i++){
	 	for(j=i+1;j<n;j++){
	 		jeste=1;
	 		for(k=0;k<m;k++){
			if( mat[k][i]!=mat[k][j]) {
				jeste=0; break;}
			}
			if(jeste){
				xk=j;
	for(k=0;k<m;k++){
		for(z=xk;z<n-1;z++)
		mat[k][z]=mat[k][z+1];
	}
	n--; j--;
	       }
		}
	}


	
	/*ispis nove matrice*/
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}
