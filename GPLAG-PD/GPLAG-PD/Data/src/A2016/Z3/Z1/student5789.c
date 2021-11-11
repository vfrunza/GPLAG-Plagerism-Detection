#include <stdio.h>

int daj_prost() {
	int i,k,prost=1;
	static int b=2;
		do{
			for(i=2; i<b; i++){
				if(b%i==0){
					prost=0;
					break;
					
				}
			}
				if(i==b)
					prost=1;
				if(prost==0)
					b++;
				}
		while(prost==0);
		k=b++;
		return k;
}


int main() {
	int A,B,k=2,suma=0;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A,&B);
		if(A<1)
			printf("A nije prirodan broj.\n");
		if(A>=B)
			printf("A nije manje od B.\n");
	}
	while(A<1 || A>=B);
	
	while(k<B){
		if(k>A && k<B)
			suma=suma+k;
			k=daj_prost();
		if(k>=B) break;
		}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma);
	return 0;
}
