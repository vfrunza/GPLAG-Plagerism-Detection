#include <stdio.h>

int daj_prost() {
	static int i=2,prost=0;
	int p,j,t;
	for (i;;i++){
		if (i==2){
			i++;
			t=i-1;
			return t;
		}
		for (j=2;j<i;j++){
			if (i%j==0){
				prost=0;
				break;
			}
			else 
				prost=1;
		}
		if (prost==1){
			i++;	
			p=i-1;
			return p;
		}
	}
}

int main() {
	/*printf("Zadaća 3, Zadatak 1");*/
	int A,B,i,suma=0,pom;
	do{
	printf ("Unesite brojeve A i B: ");
	scanf ("%d %d", &A, &B);
	if (A<=0){
		printf ("A nije prirodan broj.\n");
	}
	else if (A>=B){
		printf ("A nije manje od B.\n");
	}
	else if (B<=0){
		printf ("B nije prirodan broj.\n");
	}
	} while (A<=0 || A>=B || B<=0);
	while (1){
		pom=daj_prost();
		if (pom<A)
			suma=suma+0;
		else if (pom>A && pom<B)
			suma=suma+pom;
		else if (pom>B)
			break;
	}
	printf ("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}