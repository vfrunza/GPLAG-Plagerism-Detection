#include <stdio.h>


int provjeri_prost(int x){
	int i, prost=1;
			for(i=2; i<= x/2; ++i){
			
				if(x%i == 0){
					prost=0;
					break;
				}
			
			}
		
		return prost;
}

int daj_prost(){
	int i;
	static int brojac=1;
		for(i=2; i<1000000; i++){
			brojac++;
			i=brojac;
			if(provjeri_prost(i) == 1){
				break;
			}
			else {
				continue;
			}
		}
		return i;
}


int main() {
	int A, B, i, suma=0, niz[500];
	
		for(i=0; ; i++){
			printf("\nUnesite brojeve A i B: ");
			scanf("%d %d", &A, &B);
			if(A>=B){
				printf("A nije manje od B.");
			}
			else if(A<=0){
				printf("A nije prirodan broj.");
			}
			else{
				break;
			}
		}
	
	for(i=0; i<500; i++){
		niz[i]=daj_prost();
		if(niz[i]>A && niz[i]<B){
			
			suma+=niz[i];
		}
		
	}
	
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}
