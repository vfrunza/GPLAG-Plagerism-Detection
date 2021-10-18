#include <stdio.h>

int prost (int x){
	int i;
	if(x==1) {
		return 0;
	}
	for (i=2;i<x;i++) {
		if(x%i==0) {
			return 0;
		}
	}
	return 1;
}

int daj_prost() {
	static int A,B;
	static int i=1;
	
	i++;
	for(i;;i++) {
       if(prost(i)==1) {
       return i;
     } else continue;
}
}	
int main () {
	int A,B,i,suma=0,x;
	
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		if (A<=0) {
			printf("A nije prirodan broj.\n");
		}
		else if (A>=B) {
			printf("A nije manje od B.\n");
		}
		else if (B<=0) {
			printf("B nije prirodan broj.\n");
		}
	} while (A<=0 || A>=B || B<=0);
	
while (A>=0 || A<=B || B<=0) {
	x=daj_prost();
	if (x<A)
	    suma=suma+0;
	else if (x>A && x<B)
	    suma=suma+x;
	else if (x>B)
	     break;
}

printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
return 0;
} 