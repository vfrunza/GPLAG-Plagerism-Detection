#include <stdio.h>
#include <limits.h>

int prost (int x){
	int i;
	if(x==1) return 0;
	for(i=2; i<x; i++){
		if(x%i==0) return 0;
	}
	return 1;
}

int daj_prost(){
	static int Prost=1, PROST=2;
	int i;
	if(Prost==1) {
		Prost=0;
		return PROST;
	}
	
	for(i=PROST; i<INT_MAX; i++){
		if((prost(i)==1) && i>PROST){
			PROST=i;
			break;
		}
	}
	return PROST;
}

int main() {
int A, B, suma=0, C;
do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	if(A<=0) printf("A nije prirodan broj.\n");
	else if(A>=B) printf("A nije manje od B.\n");
	else if(B<=0) printf("B nije prirodan broj.\n");
	
} while(A<=0 || B<=0 || A>=B);
for(;;){
	C=daj_prost();
	if(C>A)break;
}
if(C<B) suma+=C;

for(;;){
	C=daj_prost();
	if(C>=B) break;
	suma+=C;
}	

printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
return 0;
}
