#include <stdio.h>

int main() {
	int m,n,nizA[100][100],nizB[100][100],nizC[100][100],i,j,k,l,broj,brojacA=0,brojacB=0,brojacC=0,istina=1;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
	}while(m>100 || n>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&nizA[i][j]);
	        }
	    }printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&nizB[i][j]);
		    }
	    }printf("Unesite clanove matrice C: ");
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
			scanf("%d",&nizC[i][j]);	
			}
		}for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				broj=nizA[i][j];
				for(k=0;k<m;k++){
					for(l=0;l<n;l++){
						if(nizA[k][l]==broj) brojacA++;
					}
				}for(k=0;k<m;k++){
					for(l=0;l<n;l++){
						if(nizB[k][l]==broj) brojacB++;
						if(nizC[k][l]==broj) brojacC++;
					}
				}if(brojacA!=brojacB || brojacA!=brojacC){
					istina=0;
					i=j=100;
					break;
				}else{
					brojacA=0;
					brojacB=0;
					brojacC=0;
				}
			}
		}if(istina) printf("DA\n");
		else printf("NE\n");
	return 0;
}
