#include <stdio.h>

void ispisi(int matrica[100][100], int visina, int sirina, int brojac){
	int i,j;
	if(sirina==0){
		printf("Nakon %d. prolaza matrica je prazna!\n",brojac);
	}
	if(sirina!=0){
	printf("Nakon %d. prolaza matrica glasi:\n",brojac);
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			printf("%5d",matrica[i][j]);
		}
		printf("\n");
	}
}
printf("\n");
}
int max(int matrica[100][100], int visina, int sirina){
	int broj,broj1;
	int i,j,k,z;
	int brojac=0,br=0;
	// petlja koja broji koliko se puta ponavlja prvi element matrice
	for(i=0;i<1;i++){
		for(j=0;j<1;j++){
			broj=matrica[i][j];
			for(k=0;k<visina;k++){
				for(z=0;z<sirina;z++){
					if(matrica[i][j]==matrica[k][z]){
						brojac+=1;
					}
				}
			}
		}
	}
	//broj ponavljanja prvog elementa poredimo sa brojem ponavljanja drugih elemenata
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			br=0;
			for(k=0;k<visina;k++){
				for(z=0;z<sirina;z++){
					if(matrica[i][j]==matrica[k][z]){
						br+=1;
					}
				}
			}
			broj1=matrica[i][j];
			//u slucaju da se sljedeci element ponavlja vise puta,trazeni broj je upravo taj
			if(br>brojac){
				brojac=br;
				broj=matrica[i][j];
			}else if(br==brojac && broj1 < broj ){
				broj=broj1;
			}
		}
	}
	return broj;
}
int izbaci_kolone(int matrica[100][100],int visina, int sirina, int n){
	int i,j,k,p,l,z,brojac=0,indikator=0;
	//trazimo poziciju elementa koji se najvise puta ponavlja
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			if(matrica[i][j]==n){
				p=j;
				break;
			}
		}
		break;
	}
	do{
		brojac+=1;
	for(k=0;k<sirina;k++){
		for(l=0;l<visina;l++){
			for(z=0;z<sirina;z++){
				if(matrica[l][z]==n){
					p=z;
					indikator+=1;
					break;
				}
			}
			break;
		}//ako je broj nadjen izbacujemo kolonu u kojoj se nalazi
		if(indikator !=0){
		for(j=0;j<sirina-1;j++){
			for(i=0;i<visina;i++){
				if(j>=p){
				matrica[i][j]=matrica[i][j+1];
				}
			}
		}
		sirina--;
		j--;
		k--;
		}
		indikator=0;
	}
	//ispisujemo matricu nakon izbacivanje kolona u kojoj se nalazi broj n
	ispisi(matrica,visina,sirina,brojac);
	n=max(matrica,visina,sirina);
	}while(sirina!=0);
	return sirina;
}
int main() {
	int mat[100][100];
	int i,j,visina,sirina;
	int n;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	
	for(i=0;i<visina;i++){
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<sirina;j++){
			scanf("%d",&mat[i][j]);
		}
	
	}
	printf("\n");
	n=max(mat,visina,sirina);
	izbaci_kolone(mat,visina,sirina,n);
	
	return 0;
}
