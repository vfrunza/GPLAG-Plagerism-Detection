#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina){
	int brojevi[10000];
	int ponavlja[10000] = {0};
	int vel = 0,i,j,k,ima,max_el,max_ind;
	for(i = 0; i < visina; i++){
		for(j = 0; j < sirina; j++){
			ima = 0;
			for(k = 0; k < vel; k++){
				if(matrica[i][j] == brojevi[k]) ima = 1;
			}
			if(!ima){
				brojevi[vel++] = matrica[i][j];
			}
		}
	}
	for(i = 0; i < visina; i++){
		for(j = 0; j < sirina; j++){
			for(k = 0; k < vel; k++){
				if(matrica[i][j] == brojevi[k]) ponavlja[k]++;
			}
		}
	}
	max_el = ponavlja[0];
	max_ind = 0;
	for(k = 0; k < vel; k++){
		if(ponavlja[k] > max_el){
			max_el = ponavlja[k];
			max_ind = k;
		}
		else if(ponavlja[k] == max_el){
			if(brojevi[k] < brojevi[max_ind]){
				max_el = ponavlja[k];
				max_ind = k;
			}
		}
	}
	return brojevi[max_ind];
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N){
	int i,j,k,x;
	for(i = 0; i < visina; i++){
		for(j = 0; j < sirina; j++){
			if(matrica[i][j] == N){
				if(j != (sirina - 1)){
					for(k = j; k < sirina; k++){
						for(x = 0; x < visina; x++){
							matrica[x][k] = matrica[x][k + 1];
						}
					}
					sirina--;
					j--;
				}
				else {
					sirina--;
					j--;
				}
			}
		}
	}
	return sirina;
}

int main() {
	int matrica[100][100];
	int m,n,i,j,N,br = 0;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&m,&n);
	for(i = 0; i < n; i++){
		printf("Unesite elemente %d. reda: ",i+1);
		for(j = 0; j < m; j++) scanf("%d",&matrica[i][j]);
	}
	for(;;){
		N = max(matrica,n,m);
		m = izbaci_kolone(matrica,n,m,N);
		if(m <= 0) break;
		printf("\nNakon %d. prolaza matrica glasi:\n",++br);
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++) printf("%5d",matrica[i][j]);
			printf("\n");
		}
	}
	printf("\nNakon %d. prolaza matrica je prazna!",++br);
	return 0;
}
