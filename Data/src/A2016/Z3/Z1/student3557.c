#include <stdio.h>

daj_prost() {
    
    static int n=1;
    int i=0;
    n++;
	for(i=2; i<n; i++) {
	    if(n%i==0) {
	        n++;
	        i=1;
	    }
	}
	
	if(i==n) return n;
}


int main() {
	
	int A, B, suma=0, i, t;

 do {
 	printf("Unesite brojeve A i B: ");
 	scanf("%d%d", &A, &B);
 	
 	if(A>=B) printf("A nije manje od B.\n");
 else	if(A<=0) printf("A nije prirodan broj.\n");
 else	if(B<=0) printf("B nije prirodan broj.\n");
 }
 while(A>=B || A<=0 || B<=0);
	
	
	for(i=A+1; i<B; i++) 
	{
		t=daj_prost();
			if(t==i) suma+=t;
	}
	
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	
	return 0;
}
