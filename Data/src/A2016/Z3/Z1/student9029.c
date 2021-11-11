#include <stdio.h>



int daj_prost(){
	static long int i=2;
	int x;
	
		for(x=2;x<i;x++){
		if(i%x==0 && i!=2){
      	    i++;
      	    x=1;
		  }
		}
	i++;	
	return i-1;

}

int main() {
	
	int A, B, petlja=1, suma=0, prost,i;
	
	while(petlja==1){
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A , &B);
	
	if(A<=0) {printf("A nije prirodan broj.\n"); continue;}
	if(A>B || A==B) {printf("A nije manje od B.\n");continue;}
	if(B<=0) {printf("B nije prirodan broj.\n"); continue;}
	petlja=0;
	}
	
	for(i=1; i<B; i++){
		prost=daj_prost();

		if(prost>A && prost<B)
	    suma+=prost;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	
	return 0;
}
