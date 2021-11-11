#include <stdio.h>
#include <math.h>


							/* Funkcija za proste brojeve koja će kad bude pozvana svaki naredni put dati sljedeći prost broj u nizu */
	 int  daj_prost(){
	
		
		int i=2;
		static int  a=1;
	ponovo:
					a++;
			for(i=2;i<=sqrt(a);i++)	{
				if(a%i==0){
					
							/* Goto naredba (harmful)... Korištena izričito zbog jednostavnosti funkcije */
				goto ponovo;	
				}
			}
		return a;
	}
int main() {
	int i;
	int A,B,suma=0;
	int x;
	do		
		{
			
							/* Unos intervala brojeva ograničenog sa A i B */
				printf("\nUnesite brojeve A i B:");
					scanf("%d %d", &A,&B);
							/* Uslovi za pogrešan unos */
			if(A>B)	{
				printf(" A nije manje od B.");
				continue;
			}	
			
			if(A<=0) {
				printf(" A nije prirodan broj.");
				continue;
			}
			
			if(A==B) {
				printf(" A nije manje od B.");
				continue;
			}
			
		}while(A>B || A<=0 || A==B);
							/* Računanje sume, te pojava funkcije daj_prost koja svaki naredni put daje novu vrijednost */ 
	for(i=0; i<B; i++)	{
		
				x= daj_prost();
			if(x<A+1) {
				continue;
				
			}
			
			if(x>=A+1 && x<B){
				suma+=x;
			}
		
		
	}
			printf(" Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);

	
	
	
	return 0;
}
