#include <stdio.h>

int daj_prost () {
	static int br=2;
	int i;
	 while(1) {
	 	int prost=1;
	 	for (i=2;i<br;i++) {
	 		if(br%i==0){
	 			prost=0;
	 		}
	 	}
	 if (prost==0){
	 	br++;
	 }
	 else break;
	 }
	  br++;
	  return br-1;
}

int main() {
	int A,B,suma=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		if (A<=0) printf ("A nije prirodan broj.\n");
		else if (A>=B) printf ("A nije manje od B.\n");
		else break;
	} while (1);
	
	while(1){
		int C;
		  C=daj_prost();
		if (C>A && C<B) 
		  suma=suma+C;
	    if (C>=B) break;
	}
printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}
