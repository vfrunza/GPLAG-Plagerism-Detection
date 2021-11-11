#include <stdio.h>


int daj_prost() {
	int prost=1,i;
	static int n=2;
	
	while(1) {
		prost=1;
		for(i=2; i<=n/2; i++) {
			if(n%i==0) { prost=0; break; }
		}
			
		if(prost)  return n++;
		n++;
		
	}
}

int main() {
	
	int A,B,suma=0,broj;
	
	do { 
		  printf("Unesite brojeve A i B: ");
		  scanf("%d", &A);
		  scanf("%d", &B);
		  if(A<=0) printf("A nije prirodan broj.\n");
		  if(A>=B) printf("A nije manje od B.\n");
		  
		  }while((A>=B) || (A<=0) || (B<=0));
		  
		  while(1) {
		  	broj=daj_prost();
		  if(broj>B) break;
		  if((broj>A) && (broj<B))
		  suma+=broj;
		  }
		  
		  printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma);
	
	return 0;
}
