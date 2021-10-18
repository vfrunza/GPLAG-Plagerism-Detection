#include <stdio.h>

int main() {
	int matA[100][100],matB[100][100],matC[100][100];
	int i,j,p,k,isti_element,m,n;
	int brojac=0,brojac1=0;
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&m,&n);
	do{
		if(m>100 || n>100 ){
			printf("Unesite brojeve M i N: ");
			scanf("%d %d",&m,&n);
		}
	}while(m>100 || n>100 );
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matA[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matB[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matC[i][j]);
		}
	}
	isti_element=1;
	for(i=0;i<m;i++){
		for(p=0;p<n;p++){
    	    for(j=0;j<m;j++){
			    for(k=0;k<n;k++){
				    if(matA[i][p]==matB[j][k]){
					brojac++;
				    }
				    if(matA[i][p]==matC[j][k]){
				    	brojac1++;
				    }
				}
			}
			if(brojac != brojac1 || brojac==0 || brojac1==0){
				isti_element=0;
			}
		}
	}
	if(isti_element){
		printf("DA\n");
	}else{
		printf("NE\n");
	}
	
	return 0;
}
