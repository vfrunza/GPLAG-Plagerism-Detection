#include <stdio.h>


int max (int matrica[100][100],int visina,int sirina){
	int i , j ;
	int niz[100*100]; 
	int brojac = 0 ;
	int brojac_el = 0 ;
	
	for(i = 0 ; i < visina; i++){
		for(j = 0 ; j < sirina ; j++){
			for(k = 0 ; k < 100*100; k++){
				if(matrica[i][j] == matrica[i+1][j+1] || matrica[i][j] == matrica[i+1][j] || matrica[i][j] == matrica[i][j+1])
				brojac++;
			}
			niz[k] = matrica[i][j];
			brojac_el++;
		}
	}
}
int main() {
	printf("Zadaća 3, Zadatak 4");
	return 0;
}
