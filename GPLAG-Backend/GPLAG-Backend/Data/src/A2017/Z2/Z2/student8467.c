#include <stdio.h>
#include <math.h>

int duzina(int x){
	int counter = 0;
	if(x == 0){
		return 1;
	}
	while (x != 0) {
		x /= 10;
		counter++;
	}
	return counter;
}
int stepen(int x){
	int i,sten = 1;
	for(i = 0; i < x; i++){
		sten *=10;
	}
	return sten;
}

int main() {
	int uneseniNiz[101];
	int izlazniNiz[1001];
	int velicina,i,j,counter2 = 0;
	printf("Unesite velicinu niza: ");
	scanf("%d",&velicina);
	printf("Unesite clanove niza: ");
	/*Unos niza*/
	for(i = 0; i < velicina; i++){
		int unos;
		scanf("%d",&unos);
		if(unos >= 0){
			uneseniNiz[i] = unos;
		}else{
			i--;
		}
	}
	/*ČUPANJE ČLANOVA NIZA*/
	for(i = 0; i < velicina; i++){
		int cifra, dijeli;
		dijeli =  stepen(duzina(uneseniNiz[i]));
		
		for(j = 0; j < duzina(uneseniNiz[i]); j++){
			if(uneseniNiz[i] != 0){
				cifra = (uneseniNiz[i] % dijeli)/(dijeli/10);
				izlazniNiz[counter2] = cifra;
				//printf("%d,",cifra);
				dijeli /= 10;
				counter2++;
			}else{
				izlazniNiz[counter2] = 0;
				//printf("%d,",cifra);
				counter2++;
				
			}
		}
	}
	
	izlazniNiz[counter2] = -1;
	/*STAVLJENO JE RADI UPOREĐIVANJA SA VRIJEDNOSTI NIZA, PRAVILO MI JE PROBLEM SA NULOM*/
	/*OVA VRIJEDNOST NIKAD NEĆE BITI*/
	/*LOGIKA SA NIZOVIMA*/
	printf("Finalni niz glasi:\n");
	int counter1 = 0;
	for(i = 1; i <= counter2; i++){
		if(counter1 == 0){
			printf("%d",izlazniNiz[i-1]);
		}
		if(izlazniNiz[i-1] == izlazniNiz[i]){
			counter1++;
		}else if((izlazniNiz[i-1] != izlazniNiz[i]) && (counter1 > 0)){
			printf(" %d ", counter1+1);
			counter1 = 0;
		}else{
			if(i == counter2){
				printf(" 1");
			}else{
				printf(" 1 ");
			}
		}
	}
	return 0;
}
