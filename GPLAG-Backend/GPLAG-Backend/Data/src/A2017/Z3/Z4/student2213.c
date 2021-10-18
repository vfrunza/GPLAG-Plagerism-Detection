#include <stdio.h>
#include <stdbool.h>

int max(int matrica[100][100],int visina, int sirina){
	int brojaci[2000];
	int i;
	int j;
	int k;
	int vel_brojac=0;
	int cifra;
	int pozicija;
	int max;
	int max_ponovljenih;
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			cifra=matrica[i][j];
			pozicija=-1;			
			for(k=0;k<vel_brojac;k+=2){
				if(cifra==brojaci[k]){
					pozicija=k;
				}
			}
			
			if(pozicija==-1){
				brojaci[vel_brojac]=cifra;
				vel_brojac++;
				brojaci[vel_brojac]=1;
				vel_brojac++;
			}
			else {
				pozicija++;
				brojaci[pozicija]++;
			}
		}
	}
	max=brojaci[0];
	max_ponovljenih=brojaci[1];
	for(i=1;i<vel_brojac;i+=2){
		if(max_ponovljenih<brojaci[i]){
			max_ponovljenih=brojaci[i];
			max=brojaci[i-1];
		}
		if(max_ponovljenih==brojaci[i]){
			if(brojaci[i-1]<max){
				max=brojaci[i-1];
			}
		}
	}	
	return max;
}
int izbaci_kolone(int matrica [100][100],int visina,int sirina,int n){
	
	int i;
	int j;
	int k;
	int niz_kolona[100];
	int vel_niza_k=-1;
	bool vec_upisan;
	int prazna_kolona=0;
	bool da_li_je_u_nizu;
	
		for(i=0;i<sirina;i++){
			vec_upisan =false;
			for(j=0;j<visina;j++){
				if(matrica[j][i]==n && !vec_upisan){
					vel_niza_k++;
					niz_kolona[vel_niza_k]=i;
					vec_upisan = true;
				}
			}
		}
		for(i=0;i<sirina;i++){
			da_li_je_u_nizu=false;
			for(k=0;k<=vel_niza_k;k++){
				if(niz_kolona[k]==i){
					da_li_je_u_nizu=true;
				}
			}
			if(da_li_je_u_nizu){
				continue;
			}
			else{
				if(i==prazna_kolona){
					prazna_kolona++;
				}
				else{
					for(j=0;j<visina;j++){
						matrica[j][prazna_kolona]=matrica[j][i];
					}
					prazna_kolona++;
				}
			}
		}
		sirina= sirina-(vel_niza_k+1);

	return sirina;
}
int main() {
	int sirina, visina;
	int i;
	int j;
	int n;
	int prolaz;
	int matrica[100][100];
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	for(i=0;i<visina;i++){
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<sirina;j++){
			scanf("%d", &matrica[i][j]);
		}
	}
	printf("\n");

	prolaz=0;
	while (sirina!=0) {
		prolaz++;
		n = max(matrica,visina,sirina);
		sirina = izbaci_kolone(matrica,visina,sirina,n);
		if(sirina == 0){
			printf("Nakon %d. prolaza matrica je prazna!", prolaz);
			return 0;
		}
		printf("Nakon %d. prolaza matrica glasi:\n", prolaz);
		for(i=0;i<visina;i++){
			for(j=0;j<sirina;j++){
				printf("%5d",matrica[i][j]);
			}
			printf("\n");
		}	
	}
	return 0;
}
