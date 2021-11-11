#include <stdio.h>
int t[200][200]={{0}};
int main() {
	int i,j,m,n,tacno=1,l,k,o;
	/*Unosimo dimenziju matrice*/
	printf("Unesite brojeve M i N: ");
	do{
		scanf("%d %d", &m,&n);
	/*Provjeravamo da li unesene dimenzije odgovaraju opsegu koji je zadan u postavci*/
		if(m>200 || n>200 || n<=0 || m<=0){
			printf("Brojevi nisu u trazenom opsegu.");
			printf("\nUnesite brojeve M i N: ");
		}
	}while(m>200 || n>200 || n<=0 || m<=0);
	/*Unosimo elemente matrice i pridruzujemo im koordinate i i j*/
	printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &t[i][j]);
		}
	}
	/*Dvije petlje, uporedjujemo dva reda pocevsi od prvog reda, sa njim uporedjujemo ostale 
	iskljucujuci taj zato druga petlja ide od i+1*/
	for(i=0; i<m-1; i++){ /*prvi red s ostalima u prvom koraku pa se i poveca pa drugi s ostalim uporedi*/
		for(j=i+1; j<m; j++){
			tacno=1;
	/*Neka promjenljiva tacno od cije nam ispunjenosti ovisi ulazak u petlju za izbacivanje*/ 
			for(k=0; k<n; k++){
				if(t[i][k]!=t[j][k]) 
				tacno=0;
	/*ako tacno postane nula ispunjen uslov za drugu petlju*/
			}
	/*Tacno postalo nula ulazimo u petlju za izbacivanje*/
	if(tacno==1){
		for(l=j; l<m-1; l++){
			for(o=0; o<n; o++){
	/*Clan matrice ostaje s istim drugim koordinatama a prva se mijenja*/
			t[l][o]=t[l+1][o];
	    	}
		}
	/*Smanjimo broj redova jer je izbacen i max koordinate j je smanjen*/ 
    j--; m--; 
}	
	}
      }
     /**Analogno se izbaci kolona*/
 	for(i=0; i<n-1; i++){
 		for(j=i+1; j<n; j++){
 			tacno=1;
 			for(k=0; k<m; k++){
 				if(t[k][i]!=t[k][j])
 				tacno=0;
 			}
 	if(tacno==1){
 		for(l=j; l<n-1; l++){
 			for(o=0; o<m; o++){
 				t[o][l]=t[o][l+1];
 			}
 		}
 	j--; n--;
}
  }
 	}
	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	/*Ispis takve izmjenjene matrice*/
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%5d", t[i][j]);
		}
		printf("\n");
	}
	return 0;
}
