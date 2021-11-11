#include <stdio.h>
int daj_prost () {
	static int i=1;
	int j, prost;
        do{i++;
        prost=1;
         for(j=2; j<i; j++) {
        	if(i%j==0) prost=0;
        } }while(prost==0); 
        
}
int main() {
		int i, A, B, suma=0;
		do{printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
	    if(A<1) printf("A nije prirodan broj.\n");
		if(A>=B) printf("A nije manje od B.\n");	
		} while(A<1 || A>=B);
	for(i=A+1; i<B; i++) {
	i=daj_prost();
	if(i>A && i<B) suma=suma+i;}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}