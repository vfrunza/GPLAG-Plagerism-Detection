#include <stdio.h>
int daj_prost() {
	int i, prost=1;
	static int brojac=1;
	brojac++;
	while(1){
		prost=1;
		for(i=2;i<brojac;i++){
				if(brojac%i==0){
					prost=0;
					break;
				}
		}
		if(prost==1) 
		return brojac;
		brojac++;	
	}

}
int main() {
int x=0, z, A, B;
int s=0;
do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	if (A<1) printf("A nije prirodan broj.\n");
	else if (A>=B) printf("A nije manje od B.\n");
	else if(B<1) printf("B nije prirodan broj.\n");
}while(A>=B || A<1 || B<1);
/*Racunanje sume*/
	for(z=3;z<B;z++){
		x=daj_prost(); /*Poziv funkcije*/
		if(x>A && x<B){
		s+=x;
		}
	}
		printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, s);
return 0;
}
