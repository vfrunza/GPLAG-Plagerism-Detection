#include <stdio.h>


	int daj_prost(void){
		static int i=2;
		int br_el=100000;
		int j, prost=0;
	
			for(; i<br_el; i++){
				if(i==2) {i++; return i-1;}
				else{
					for(j=2; j<i; j++){
						if(i%j!=0) {prost=1;}
						else {prost=0; j=2; i++;}
					}
				} if(prost==1){i++; return i-1;}
			}
			return 0;
	}
	
	

	int main() {
		int A, B, ponovi=0, i, suma=0,y;
	
			do{
				ponovi=0; 
				printf("Unesite brojeve A i B: ");
				(void)scanf("%d %d", &A, &B);
	 			if(A==B || B<A) {
	 				printf("A nije manje od B.\n"); ponovi=1;
	 			}
				else if(A<1 || B<1) {
					printf("A nije prirodan broj.\n"); ponovi=1; 
				}
			} while(ponovi!=0);
	
			for(i=2; i<B; i++){
				y=daj_prost(); /*pozivaj f-ju, ALI sabiraj samo one br koje se nalaze u trazenom intervalu*/
					if(y>A && y<B) suma+=y;
			}
	
			printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	
		return 0;
	}
		
		
		
		
		
		
		
