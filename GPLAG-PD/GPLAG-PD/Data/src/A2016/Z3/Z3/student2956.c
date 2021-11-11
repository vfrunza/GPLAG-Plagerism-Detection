#include <stdio.h>

int broj(int niz[],int vel){
	int suma=0,i,k=1;
	for(i=0;i<vel;i++){
		suma+=niz[i]*k;
		k*=10;
	}
	return suma;
	
}

int main() {
	int m,n;
	int i,j,mat[200][200];
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	if(m<1 ||m>200 || n<1 ||n>200) printf("Brojevi nisu u trazenom opsegu.\n");
	} 
	while(m>200 || n>200 || n<1 || m<1);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	int k,l,o;
	
	for(i=0;i<m;i++){
		for(k=i+1;k<m;k++){
			if(broj(mat+i,n)==broj(mat+k,n)){
				for(l=k;l<m-1;l++){
					for(o=0;o<n;o++){
					mat[l][o]=mat[l+1][o];
				}
				
			}
			m--;
			k--;
		}
	}}
	int pomocna[200][200];
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			pomocna[j][i]=mat[i][j];
		}
	}

	
	
	int pom=m;
	m=n;
	n=pom;
	
	//transp
	
		
	
	for(i=0;i<m;i++){
		for(k=i+1;k<m;k++){
			if(broj(pomocna+i,n)==broj(pomocna+k,n)){
				for(l=k;l<m-1;l++){
					for(o=0;o<n;o++){
						pomocna[l][o]=pomocna[l+1][o];
					}
				}
				m--;
				k--;
			}
		}
	}
	
	pom=m;
	m=n;
	n=pom;
	
	for(i=0;i<m;i++){
	for(j=0;j<n;j++){
		mat[i][j]=pomocna[j][i];
	}
	}
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++) {
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}
