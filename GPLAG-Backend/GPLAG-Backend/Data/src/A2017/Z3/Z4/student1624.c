#include <stdio.h>

/*
int max(int matrica[100][100], int visina, int sirina)
Funkcija prima matricu cijelih brojeva koja je deklarisane veličine 100x100, ali njene stvarne dimenzije date su promjenljivim visina i sirina. Funkcija vraća član matrice koji se najviše puta ponavlja. Ako se više članova ponavljaju jednak (najveći) broj puta, funkcija treba vratiti najmanji od tih članova.

Zatim napisati funkciju izbaci_kolone koja prima matricu (kao iznad) i jedan broj N, a zatim iz matrice izbacuje sve kolone u kojima se javlja član N. Funkcija vraća broj kolona nakon izbacivanja.

Ove dvije funkcije iskoristite u programu u kojem se najprije traži od korisnika da unese matricu, a zatim se u petlji poziva prva pa druga funkcija (iz matrice se izbacuju sve kolone u kojima se nalazi element koji se najviše puta javlja u matrici), i tako sve dok matrica ne ostane prazna. Prilikom svakog prolaza treba na ekran ispisati matricu:
 */

/*int max(int matrica[100][100], int visina, int sirina){
	int i,j,m,n, k,l,brojac1=0,brojac2=0,max=-10000;
	
	int najveci=0;
	
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			n=matrica[i][j];
			m=matrica[i+1][j+1];
			for(k=0;k<visina;k++){
				for(l=0;l<sirina;l++){
					if(matrica[k][l]==n) brojac1++;
					if(matrica[k][l]==m) brojac2++;}
			}
					if(brojac1>najveci || brojac2>najveci){
					if(brojac1>brojac2) {max=n; najveci=brojac1;}
					else if(brojac2>brojac1) {max=m; najveci=brojac2;}
					else if(brojac2==brojac1){
						if (m<n) max=m;
						else if(n<m) max=n;
					}
				
					}
		}
	}
	return max;
}




int izbaci_kolone (int matrica[100][100], int visina, int sirina, int N){
	
	int i, j,n,k,l;
    
    for(i=0;i<visina;i++){
    	for(j=0;j<sirina;j++){
    		if (matrica[i][j]==N){
    		    n=j;/*
    			for(k=n;k<sirina-1;k++){
    	for(l=0;l<visina;l++){
    	matrica[k][l]=matrica[k][l+1];
    		
    	}}*/
    	
    	for(l=0;l<visina;l++){
    		for(k=0;k<sirina-1;k++){
    			matrica[k][n]=matrica[k][l+1];
    		}
    	}
    			
    			j--;
    			sirina--;
    		}
    		
    	}
    }
    
    return sirina;
}

int main(){
    int i, j, mat[100][100], sirina, visina, n;
    
    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d%d",&sirina, &visina);
    
    
    
    for(i=0;i<visina;i++){
        printf("Unesite elemente %d. reda: ",i+1);
        for(j=0;j<sirina;j++){
           /* printf("Unesite clan %d%d: ",i,j);*/
            scanf("%d",&mat[i][j]);
        }
    }
    printf("Unesi br");
    scanf("%d",&n);
    int br;
    br=izbaci_kolone(mat,sirina,visina,n);
    printf("%d",br);
    return 0;
    
    
}

*/

#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina) {
	int i=0, j=0, k=0, l=0, red=0, kolona=0, element=0, brojacprethodni=0, brojactrenutni=0;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) { brojactrenutni=0;
			for(k=0; k<visina; k++) {
				for(l=0; l<sirina; l++) if(matrica[i][j]==matrica[k][l]) brojactrenutni++;
			}
		if(brojactrenutni>brojacprethodni || (brojacprethodni==brojactrenutni && matrica[i][j]<element)) {
			red=i; kolona=j;
			element=matrica[i][j]; brojacprethodni=brojactrenutni;
		}
		}
	} return matrica[red][kolona];
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int n) {
	int i=0, j=0,k=0, l=0, brojac=0;
	if(sirina==1) return 0;
	for(i=0; i<visina; i++) {
		brojac=0;
		for(j=0; j<sirina; j++) {
			if(matrica[i][j]==n) {brojac++; break;}
		} 
		if(brojac>0) {
			for(k=0; k<visina; k++) {
				for(l=j; l<sirina-1; l++) {
					matrica[k][l]=matrica[k][l+1];
	
				}
			}i--; sirina--;
		} 
	} 
	return sirina;
}

int main() {
int matrica[100][100], sirina=0, visina=0, i=0, j=0, rezultat=0, koji_put=0;
printf("Unesite sirinu i visinu matrice: ");
scanf("%d %d", &sirina, &visina);
for(i=0; i<visina; i++) { 	printf("Unesite elemente %d. reda: ", i+1);
	for(j=0; j<sirina; j++) {
		scanf("%d", &matrica[i][j]);
	}
} 
rezultat=izbaci_kolone(matrica, visina, sirina, max(matrica,visina,sirina));
while (rezultat!=0) {
	koji_put++;
	printf("\nNakon %d. prolaza matrica glasi: \n", koji_put);
	for(i=0; i<visina; i++) {
		for(j=0; j<rezultat; j++) {
			printf("%5d", matrica[i][j]);
		} printf("\n");
		
	}
	
	rezultat=izbaci_kolone(matrica,visina, rezultat,max(matrica,visina,rezultat) );

} 
koji_put++;
printf("\nNakon %d. prolaza matrica je prazna!", koji_put);

	return 0;
}




