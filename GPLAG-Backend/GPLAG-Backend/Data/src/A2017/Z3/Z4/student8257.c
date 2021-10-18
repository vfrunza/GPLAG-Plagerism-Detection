#include <stdio.h>
#include <stdlib.h>

// Funkcija "max" vraca broj koji se najvise puta ponavlja u matrici

int max(int matrica[100][100],int visina, int sirina) { 
	int i,j,pozHist[2001]= {0},negHist[2001] = {0};
	// Prolazi kroz matricu i povecava odgovarajuce elemente histograma
	for(i=0;i<visina;i++) {
		for(j=0;j<sirina;j++) {
			if(matrica[i][j]>=0)
				pozHist[matrica[i][j]]++;
			else 
				negHist[abs(matrica[i][j])]++;
		}
	}
	/*Prolazi kroz negativni i pozitivni histogram i vraca broj koji se ponavlja najvise puta
	a ako se vise brojeva ponavlja isto puta onda vraca broj ponavljanja najmanjeg od njih*/
	int negMax=1;
	for(i=1;i<2001;i++) {
		if(negHist[i]>=negHist[negMax])
			negMax=i;
	}
	int pozMax=0;
	for(i=1;i<2001;i++) {
		if(pozHist[i]>pozHist[pozMax] )
			pozMax=i;
	}
	
	if(negHist[negMax] >= pozHist[pozMax])
		return negMax*(-1); 
	
	return pozMax;
	
}
int izbaci_kolone(int matrica[100][100],int visina,int sirina,int N) {
	
	// Algoritam za izbacivanje kolona uz ocuvanje rasporeda kolona
	int i,j,k,red;
	for(i=0;i<visina;i++) {
		for(j=0;j<sirina;j++) {
			red=0;
			if(matrica[i][j]==N) {
				while(red<visina) {
					for(k=j;k<sirina-1;k++) {
						matrica[red][k]=matrica[red][k+1];
					}
					red++;
				}
				j--;
				sirina--;
			}
		}
	}
	return sirina;
}

int main() {
	int matrica[100][100],i,j;
	int vis,sir;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sir,&vis);
	for(i=0;i<vis;i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<sir;j++) {
			scanf("%d",&matrica[i][j]);
		}
	}
	int MAX = max(matrica,vis,sir);
	int sirina=izbaci_kolone(matrica,vis,sir,MAX);
	int prolaz=1;
	while(sirina) {
		printf("\nNakon %d. prolaza matrica glasi:\n",prolaz);
		for(i=0;i<vis;i++) {
			for(j=0;j<sirina;j++) {
				printf("%5d",matrica[i][j]);
			}
			printf("\n");
		}
		prolaz++;
		MAX = max(matrica,vis,sirina);
		sirina=izbaci_kolone(matrica,vis,sirina,MAX);
	}
	printf("\nNakon %d. prolaza matrica je prazna!",prolaz);
	return 0;
}
