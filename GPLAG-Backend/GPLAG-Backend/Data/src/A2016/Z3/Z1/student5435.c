#include <stdio.h>

	int daj_prost() {
		
		int i;
		static	int brojac=0;
		static 	int prosli=2;
		
		if (brojac==0) {
			brojac++;
			return prosli; 
		}
		
		else if(brojac!=0) {
			prosli++;
			for(i=2; i<prosli;i++) {
				if(prosli%i==0) {prosli++;i=2;}

			}
			
		}
		
		brojac++;
		return prosli;
		
	}

		
int main() {

	int A,B,i,suma=0,broj;
	
	for(;;) {
		 printf("Unesite brojeve A i B: ");
		 scanf("%d %d",&A,&B);
		 
		if(A==0 || A<0) { printf("A nije prirodan broj.\n"); }
		else if(A>=B) { printf("A nije manje od B.\n"); }
		else break;
	}
		   
	for(i=0; i<B; i++) {
		broj=daj_prost();
		
		if(broj>A && broj<B) {
		suma=suma+broj;
		}
		
	}
	if(A==B+1){	printf("Suma prostih brojeva izmedju %d i %d je 0.");	}
else	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);	
	return 0;
}
