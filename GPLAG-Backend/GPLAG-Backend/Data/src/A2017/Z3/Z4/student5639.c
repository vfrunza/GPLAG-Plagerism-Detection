#include <stdio.h>
int max(int matrica[100][100], int visina, int sirina){
	int i,j,k,l,x,trazeni_broj,broj_kolone;
	int brojac=0,max=0;
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			x=matrica[i][j];
			for(k=i+1;k<visina;k++){
				for(l=j+1;l<sirina;l++){
					if(x==matrica[k][l])
					brojac++;
					if(brojac>max){
		        	max=brojac;
			        trazeni_broj=x;
			        broj_kolone=l;    /*jos jedan uslov-kad je broj max ponavljanja isti*/
			        }
				}
			}
		}
	}
	return trazeni_broj;
}

void izbaci_kolone (int matrica[100][100], int visina, int sirina, int N){
	int i,j,broj_kolone;
	for(i=0;i<visina;i++){
	for(j=0;j<sirina;j++){
		if(matrica[i][j]==N){
			broj_kolone=j;
		}
	}
	}
	for(i=0;i<visina;i++){
		matrica[i][broj_kolone]=matrica[i][sirina-1];
		sirina--;
	}
	
}

int main() {
	
	return 0;
}
