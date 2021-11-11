#include <stdio.h>

int daj_prost()
{
	static int i=2;
	int j, prost;
	int broj=0, br=0;
	
	/*Ispitivanje da li je broj prost*/
	
	do{
		br=0;
		for(j=2; j<i; j++)
		{
			if(i%j==0) {
				br++;
			}
			
		}
		
	if(br<1) prost=1;
	else prost=0;
	
	if(prost==1) /*Ukoliko je broj prost funkcija vraca vrijednost*/
		break;
	
	else i=i+1; /*Ukoliko broj nije prost petlja se opet izvrsava do sljedeceg prostog broja*/

	}while(prost==0);
	
	broj=i;
	i=i+1;
	
	

	return broj;
	

}


int main() {
	
	int A, B, i=0;
	int suma=0;
	int prost_broj=0;
	
	do{
		
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	
	if(A>=B) printf("A nije manje od B.\n");
	else if(A<1) printf("A nije prirodan broj.\n");
	else if(B<1) printf("B nije prirodan broj.\n");
	
	
	}while(A>=B || A<1 || B<1);
	

	
	for(i=2; i<B; i++)
	{
		prost_broj=daj_prost();  /*pozivanje funkcije daj_prost */
		
		if(prost_broj>A && prost_broj<B)
	{
			suma=suma+ prost_broj; 
	}
	
	
	}

	
	
	
	printf("Suma prostih brojeva izmedju %d i %d je %d. ", A, B, suma);
	
	
	
	return 0;
}
