#include <stdio.h>

int main(){
	
	int sirinaA, visinaA, sirinaB, visinaB, i,j, matricaA[100][100], matricaB[100][100], tmp, pomocna, ista = 1;
	
	//unosenje matrice A
	
	printf("\nUnesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirinaA, &visinaA);
	
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < visinaA; i++){
		for(j = 0; j < sirinaA; j++){
			
		scanf("%d", &matricaA[i][j]);
		}
	}
	// unosenje matrice B
	
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &sirinaB, &visinaB);
	
	printf ("Unesite clanove matrice B: ");
	for (i = 0; i < visinaB; i++){
		for(j = 0; j < sirinaB; j++){
			scanf("%d", &matricaB[i][j]);
		}
	}
	

		// prvo cemo da transponujemo matricu A, tj. mijenja se uloga kolona i redova kod amtrice A
		
		for(i = 0; i < visinaA; i++){
			for(j = i + 1 ; j < sirinaA; j++){
				tmp = matricaA[i][j];
				matricaA[i][j] = matricaA[j][i];
				matricaA[j][i] = tmp;
			}
		}
		// zamjena kolona matirce A, sirina ide do pola jer u suprotnom ne bi se izvrisla odgovarajuca izmjena
		
		for(i = 0; i < visinaA; i++){
			for(j = 0; j < sirinaA / 2; j++){
				pomocna = matricaA[i][j];
				matricaA[i][j] = matricaA[i][sirinaA - 1 - j];
				matricaA[i][sirinaA - 1 - j] = pomocna;
			}
		}
		// provjera da li su matrice A i B jednake, cim naidje na razliku, petlja se prekida 
		
if(sirinaA == visinaB && visinaA == sirinaB){
			
		for(i = 0; i < visinaA; i++){
			for (j =  0; j < sirinaA; j++){
			if (matricaA[i][j] != matricaB[i][j]){
			ista = 0; 
			break;
		
			}
		}
	}	
	//ispisivanje nakon provjere
	
	if(ista == 1) printf("DA");
	else  printf("NE");
	

}
else printf("NE");
	
	
	return 0;
}