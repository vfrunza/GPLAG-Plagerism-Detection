#include <stdio.h>

int main() {
	
	int matrica[200][200],redovi,kolone,n,i,j,k,z,jednake=0;
	
	do{
		printf("Unesite brojeve M i N: ");                    //unos dimenzija matrice, najvise 200 redova i 200 kolona
		scanf("%d %d", &redovi, &kolone);
		if(redovi<=0 || kolone <=0 || redovi>200 || kolone>200) {
			printf("Brojevi nisu u trazenom opsegu.\n");
		}
	} while(redovi<=0 || kolone <=0 || redovi>200 || kolone>200);
	
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<redovi;i++) {
		for(j=0;j<kolone;j++) {
			
			scanf("%d", &matrica[i][j]);
			
		}
	}
	
	for(i=0;i<redovi;i++) {                   //petlja koja lista redove
		for(n=1;n<redovi-i;n++) {              //petlja koja lista n-ove, sto su cijeli brojevi koji se sabiraju sa indeksom redova kako bi se razmatrali naredni redovi u matrici
			for(j=0;j<kolone;j++) {            //petlja u kojoj se provjeravaju vrijednosti clanova u redu, pomjera indeks kolone
				
				
				if(matrica [i][j]==matrica[i+n][j]) {           //npr. n=1, i=0, uporedjujemo clanove prvog i drugog reda u matrici
					
					jednake=1;             //ako su jednaki, istinitosna vrijednost od promjenjive "jednake" je 1
					
				}
				else{
					
					jednake=0;    //ako ne, istinitosna vrijednost promjenjive "jednake" je 0, izlazimo iz razmatranja ovog reda, prelazi se na sljedeci kroz n petlju
					break;
					
				}
				
				
			}
			if (jednake==1) {     //ako je istinitosna vrijednost "jednake" ostala 1, svi clanovi dva razmatrana reda su jednaki, pristupamo izbacivanju tog reda
				
				z=n+i;
			
					
				if(z==redovi-1) {    //ako je red koji je isti kao neki red sa kojim se uporedjivao ujedno i zadnji red, samo smanjimo broj redova u matrici i izbacili smo taj red
				
				redovi--;
				
				}
				else {            //ako to nije zadnji red u matrici, prepisat cemo svaki red, od njega pa nadalje, na mjesto prethodnog reda
				
				for(z;z<redovi-1;z++){
				for(k=0;k<kolone;k++) {
					
					matrica[z][k]=matrica[z+1][k];
				}
		
			}
			redovi--;       //s obzirom da su sada zadnji i predzadnji red isti, smanjimo broj redova da bismo izbacili zadnji red
			n--;
				}
				}
		}
	}
	
	
	for(i=0;i<kolone;i++) {                   //petlja koja lista kolone
		for(n=1;n<kolone-i;n++) {            //petlja koja lista n-ove, sto su cijeli brojevi koji se sabiraju sa indeksom kolona kako bi se razmatrali naredne kolone u matrici
			for(j=0;j<redovi;j++) {           //petlja u kojoj se provjeravaju vrijednosti clanova u koloni, pomjera indeks reda
				
				
				if(matrica [j][i]==matrica[j][i+n]) {          //npr. n=1, i=0, uporedjujemo clanove prve i druge kolone u matrici
					
					jednake=1;              //ako su jednaki, istinitosna vrijednost od promjenjive "jednake" je 1
					
				}
				else{
					
					jednake=0;       //ako ne, istinitosna vrijednost promjenjive "jednake" je 0, izlazimo iz razmatranja ove kolone, prelazi se na sljedecu kroz n petlju
					break;
					
				}
				
				
			}
			if (jednake==1) {            //ako je istinitosna vrijednost "jednake" ostala 1, svi clanovi dvije razmatrane kolone su jednaki, pristupamo izbacivanju te kolone
				z=i+n;
				if(z==kolone-1){     //ako je kolona koja je ista kao neka kolona sa kojim se uporedjivala ujedno i zadnja kolona, samo smanjimo broj kolona u matrici i izbacili smo tu kolonu
					kolone--;
					
				}
				else {                         //ako to nije zadnja kolona u matrici, prepisat cemo svaku kolonu, od nje pa nadalje, na mjesto prethodne kolone
						for(z;z<kolone-1;z++){
				for(k=0;k<redovi;k++) {
					
					matrica[k][z]=matrica[k][z+1];
				}
				}
				kolone--;     //s obzirom da su sada zadnja i predzadnja kolona iste, smanjimo broj kolona da bismo izbacili zadnju kolonu
				n--;
				}
			
			}
		}
	}
	

	printf("Nakon izbacivanja redova/kolona matrica glasi: \n");
	
	for(i=0;i<redovi;i++) {
		
		for(j=0;j<kolone;j++) {
			
			
			
			if(matrica[i][j]>=10 || matrica[i][j]<0) {
				printf("   %d",matrica[i][j]);
			}
			
			else{
			
			printf("    %d",matrica[i][j]);
			
			}
			
			
			
			
		}
		printf("\n");
	}
	
	return 0;
}
