#include <stdio.h>
#define SIRINA 200
#define DUZINA 40000

int isti(int* prvi,int* drugi,int vel) {
	int i;
	for(i=0;i<vel;i++) 
		if(prvi[i]!=drugi[i]) return 0;
	
	return 1;
}

int main () {
	int m,n,i,j,o,l,k,p,isti_red,vel,mat[SIRINA][SIRINA],niz[DUZINA];
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
		if(m<1 || m>200 || n<1 || n>200) printf("Brojevi nisu u trazenom opsegu.\n");
	}while(m<1 || m>200 || n<1 || n>200);
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++) {
	for(j=0;j<n;j++) {
	scanf("%d",&mat[i][j]);
	}
	}

	vel=m*n;
	
	i=0;
	while(i<m) {
		for(j=i+1;j<m;j++) {
			isti_red=0 ;
			for(k=0;k<n;k++) {
				if(mat[i][k]!=mat[j][k]) isti_red++;
			}
			
			if(isti_red==0) {
				for(l=j;l<m-1;l++) {
					for(o=0;o<n;o++) {
						mat[l][o]=mat[l+1][o];
					}
				}
				vel=vel-n;
				m--;
				j--;
			}
		}
		i++;
	}
	
	k=0;
	
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			niz[k]=mat[j][i];
			k++;
		}
	}
	
	for(i=0;i<vel;i+=m) {
		for(j=i+m;j<vel;j+=m) {
			if(isti(niz+i,niz+j,m)==1) {
				
				for(p=j;p<vel-m;p++) {
					niz[p]=niz[p+m];
				}
				vel-=m;
				n--;
				j-=m;
			}
		}
	}
	
	
k=0;
for(i=0;i<n;i++) {
	for(j=0;j<m;j++) {
		mat[j][i]=niz[k];
		k++;
	}
}
				
				

printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%5d",mat[i][j]);
		}
	printf("\n");
	}

	return 0;
}

