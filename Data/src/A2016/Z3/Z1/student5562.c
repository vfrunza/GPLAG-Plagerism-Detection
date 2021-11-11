#include <stdio.h>

int daj_prost(){
	
	static int broj = 2;
	int prost, i;
	
	/*Listaj brojeve vece od 2 sve dok ne naidjes na prost*/
	do{
		
		prost = 1;
		
		/*Provjeri da li je trenutni broj prost*/
		for (i = 2; i <= broj; i++){
			
			if (broj % i == 0 && i != broj){
				prost = 0;
				break;
			}
			
		}
		
		/*Predji na novi broj*/
		broj++;
		
	} while (!prost);
	
	return broj - 1;

}

int main() {
	
	int A, B, x, suma = 0;
	
	/*Zahtjevaj unos sve dok se ne unesu valjane vrijednosti*/
	do{
		
		/*Unos A i B*/
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		
		/*Javiti ako A i B nisu valjani*/
		if (A > B || A == B)
			printf("A nije manje od B.\n");
		if (A < 1)
			printf("A nije prirodan broj.\n");
	
	} while (A > B || A < 1 || A == B);
	
	
	/*Vadi proste brojeve koji su manji od B*/
	do{
		
		x = daj_prost();
		
		if (x > A && x < B)
			suma += x;
		
	}while(x < B);
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	
	return 0;
}
