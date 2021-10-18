#include <stdio.h>

int razmak(char pok){
	//pok++;
	if(pok == ' ') return 1;
	return 0;
}

int duzina_broja(int broj){
	if(broj == 0) return 0;
	int duz;
	duz = 0;
	if(broj < 0){
		duz ++;
		broj *= -1;
	}
	while(broj){
		broj /= 10;
		duz++;
	}
	return duz;
}

void ubaci_na_mjesto(char** pok, int broj){
	if(broj == 0){
		*(*(pok)) = '0';
		*(pok) += 1;
		return;
	}
	
	int duzina;
	duzina = 0;
	
	if(broj < 0){
		*(*(pok)) = '-';
		*(pok) += 1;
		broj *= -1;
	}
	
	duzina = duzina_broja(broj);
	char trenutni_znak;
	
	int duzina_copy;
	duzina_copy = duzina;
	
	while(broj){
		trenutni_znak = (broj % 10) + '0';
		broj /= 10;
		//printf("%d %d %p\n", duzina, broj, *pok);
		*(*(pok) + duzina - 1) = trenutni_znak;
		duzina--;
	}
	*(pok) += duzina_copy;
}



void poguraj_za(char* pocetak, int koliko){
	if(koliko <= 0) return;
	char* pok;
	pok = pocetak;
	while(*pok != '\0') pok += 1;
	do{
		*(pok + koliko) = *pok;
		pok -= 1;
	}while(pok != pocetak);
	*(pok + koliko) = *pok;
}

char* ubaci_broj (char* tekst, int broj){
	
	char* pok;
	char* kraj;
	int diff;
	char* iter;
	
	pok = tekst;
	kraj = NULL;
	
	while(*pok != '\0'){
		if((pok == tekst || razmak(*(pok-1))==1) && razmak(*pok) == 0){ // pocetak rijeci
			if(kraj != NULL){ // koja nije prva
				diff = (int)pok - (int)kraj;
				if(diff - 1 == 1){
					poguraj_za(pok, duzina_broja(broj) + 1);
					pok += (duzina_broja(broj) + 1);
					for(iter=kraj+1; iter < pok; iter++) *iter = ' ';
					kraj += 2;
					ubaci_na_mjesto(&kraj,broj);
				}else{
					poguraj_za(pok, duzina_broja(broj));
					pok += duzina_broja(broj);
					for(iter=kraj+1; iter < pok; iter ++) *iter = ' ';
					kraj += 2;
					ubaci_na_mjesto(&kraj, broj);
				}
			}
		}
		else{
			
			if(pok != tekst && razmak(*pok) == 1 && razmak(*(pok-1)) == 0){ //kraj rijeci
				kraj = (char*)pok;
				kraj -= 1;
			}
			
		}
		pok += 1;
	}
	
	
	return tekst;
}

int main() {
	//            01234567890123456789012345
	char a[500] = "aaa bbb   ccc-ccc     d d  rddd   ";
	int i;
	ubaci_broj(a, -10000);
	for(i=0; i<sizeof(a);i++)printf("%c",a[i]);
	printf("\n");
	return 0;
}
