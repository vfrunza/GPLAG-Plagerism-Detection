#include <stdio.h>


int main() {
int i=0,j=0,k=0,n=0,m=0,mapa2[210]={0},mapa3[210]={0},A[100][100]={{0}},B[100][100]={{0}},C[100][100]={{0}},mapa1[210]={0};


do{
printf("Unesite brojeve M i N: ");
scanf("%d %d",&m,&n);
}while(m>100||n>100||m<0||n<0);
	
printf("Unesite clanove matrice A: ");
for(i=0;i<m;++i){
	for(j=0;j<n;++j){
		scanf("%d",&A[i][j]);
	}
}
	printf("Unesite clanove matrice B: ");
for(i=0;i<m;++i){
	for(j=0;j<n;++j){
		scanf("%d",&B[i][j]);
	}
}
	printf("Unesite clanove matrice C: ");
for(i=0;i<m;++i){
	for(j=0;j<n;++j){
		scanf("%d",&C[i][j]);
	}
}
for(i=0;i<m;++i){
	for(j=0;j<n;++j){
		for(k=0;k<200;++k){
			if(k==A[i][j])
				mapa1[k]++;
			if(k==B[i][j])
				mapa2[k]++;
			if(k==C[i][j])
				mapa3[k]++;
		}		
	}
	
}
for(k=0;k<200;++k){
	if((mapa1[k]!=mapa2[k])||(mapa2[k]!=mapa3[k])){
		printf("NE\n");
		return 0;
	}
}

	printf("DA\n");
	return 0;
}
