#include <stdio.h>

int main() {
	int i,j,k,l,m,n,pr,prk,ima=0,mat[200][200];
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
		if(m<1 || m>200 || n<1 || n>200) printf("Brojevi nisu u trazenom opsegu.\n");
	}while(m<1 || m>200 || n<1 || n>200);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	do {
	ima=0;
	pr=0;
	for(j=0;j<m;j++) {											//provjera redova
		for(k=j+1;k<m;k++) {
			if( mat[j][0]==mat[k][0]) {
				for(l=0;l<n;l++) {
						
					if(mat[j][l]==mat[k][l]) pr++;
					if (pr==n) { ima=1; prk=k; }
						
					}
				}	
			}
		}
	
	if(ima) {
		for(i=prk;i<m-1;i++) {
			for(j=0;j<n;j++) {
				mat[i][j]=mat[i+1][j];
			}
		}
		m--;
		
	}
	}while(ima);
	
	do {
	ima=0;
	pr=0;
	for(j=0;j<n;j++) {										//provjera kolona
		for(k=j+1;k<n;k++) {
			if( mat[0][j]==mat[0][k]) {
				for(l=0;l<m;l++) {
						
					if(mat[l][j]==mat[l][k]) pr++;
					if (pr==m) { ima=1; prk=k; }
						
					}
				}	
			}
		}
	
	if(ima) {
		for(i=prk;i<n-1;i++) {
			for(j=0;j<m;j++) {
				mat[j][i]=mat[j][i+1];
			}
		}
		n--;
		
	}
	}while(ima);
	
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
	
	
	
	return 0;
}
