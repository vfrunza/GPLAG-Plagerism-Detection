#include <stdio.h>
#define duzina 200
int main() {
/*	printf("Zadaća 3, Zadatak 3");*/
int i,j,k,l,o;
int M,N;
int matrica[duzina][duzina];
int kolona=0,red=0;
int broj_uspjesno_unesenih;
do{
	printf("Unesite brojeve M i N: ");
	broj_uspjesno_unesenih=scanf("%d %d", &M,&N);
	if(broj_uspjesno_unesenih!=2){ printf("GRESKA!");return 0;}
	else {
	if(M<=0 || N<=0 || M>200 || N>200)printf("Brojevi nisu u trazenom opsegu.\n");
	}
}
while(M<=0 || N<=0  || M>200 || N>200);
printf("Unesite elemente matrice: ");
for(i=0;i<M;i++){
	for(j=0;j<N;j++){
		scanf("%d", &matrica[i][j]);
	}
}
for(i=0;i<M;i++){
	for(j=i+1;j<M;j++){
		red=1;
		for(k=0;k<N;k++){
		   if(matrica[i][k]!=matrica[j][k]){
		   	red=0;
		   	break;
		   }
		}
		if(red==1){
			for(o=j;o<M-1;o++){
				for(l=0;l<N;l++){
					matrica[o][l]=matrica[o+1][l];
				}
			}
			M--;
			j--;
		}
	}
}

for(i=0;i<N;i++){
	for(j=i+1;j<N;j++){
		kolona=1;
		for(k=0;k<M;k++){
		   if(matrica[k][i]!=matrica[k][j]){
		   	kolona=0;
		   	break;
		   }
		}
		if(kolona==1){
			for(o=j;o<N-1;o++){
				for(l=0;l<M;l++){
					matrica[l][o]=matrica[l][o+1];
				}
			}
			N--;
			j--;
		}
	}
}
printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
for(i=0;i<M;i++){
	for(j=0;j<N;j++){
		printf("%5d", matrica[i][j]);
	}
	printf("\n");
}

return 0;
}
