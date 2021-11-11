#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int izbaci_cifre (int niz_jedan[], int velicina_prvog, int niz_cifara[], int velicina_drugog){
	
	int i, j, cifra, pomocna, broj, pomocni[1000], k, z,  suma, minus = 0;
	
	 //unosenje uslova za niz cifara, vracanje vrijednosi 0
	 
	for( i = 0; i < velicina_drugog; i++){
		if (niz_cifara[i] < 0 || niz_cifara[i] > 9) return 0;
		for(j = i + 1; j < velicina_drugog; j++){
			
			 if (niz_cifara[i] == niz_cifara[j])return 0;
		}
	}
	// svaki broj iz niza, pretvorimo u niz njegovih cifara
	for ( i = 0; i < velicina_prvog; i++){
		broj = (niz_jedan[i]);
		if(broj < 0) {
			minus = 1;
			broj =  - broj;
		}
		else minus = 0;
		pomocna = 0;
		j = 0;
		do{
			cifra = broj % 10;
		
			pomocni[j] = cifra;
			broj = broj / 10;
			
			pomocna ++;
			j++;
		}while (broj != 0);
	//	pomocna ++; 
	//	brojac = 0 ;
	//	for(k = 0 ; k < pomocna; k++){ 
		//	printf("%d", pomocni[k]);
	//	}
	// niz cifara broja, tj. pomocni niz, poredimo za nizom cifara, i izbacujemo iste vrijednosti
		for(k = 0 ; k < pomocna; k++){
			
			for( z = 0; z < velicina_drugog; z++){
				if (pomocni[k] == niz_cifara[z]){
					for( j = k  ; j < pomocna - 1; j ++){
						pomocni[j] = pomocni[j + 1];
					}
					k--;
				
					pomocna--;
				//	if( k == - 1) k = 0;
					k = 0;
			
				}
			}
		//	if (k < 0)k++;
		}
	//	for( k = 0; k < pomocna; k++){
		//	printf("%d", pomocni[k]);
	//	}
	suma = 0;
	// broj ponovno pretvaramo iz cifara u konacno rjesenje, nakon izbacivanja cifara
	for(k = pomocna - 1 ; k >= 0; k --){
	//	tmp = pomocna - k;
	
	   suma  += pow(10, k  ) * pomocni[k];
	   
	}
	 if (pomocna == 0) niz_jedan[i] = 0;
	else{
	niz_jedan[i] = suma;
	if (minus == 1) niz_jedan[i] = - niz_jedan[i];
	
	}
	}
	// vraca vrijednost 1 ako je izbacivanje cifara uapjelo
	return 1;
}



int main(){
	// kod iz autotesta broj 4
	int brojevi[] = {9869, -4481, 55422, -5353, 1235};
int cifre[] = {2, 3, 5, 7, 9};
int i;
izbaci_cifre(brojevi, 5, cifre, 5);
for (i=0; i<5; i++)
  printf("%d ", brojevi[i]);
  
	return 0;
	
}