#include <stdio.h>

int daj_prost(){
	int j;
	static int a=1;
	a++;
	for(j=2;j<a;j++){
		if(a%j==0){
			a++;
			j=2;
		}
	}
	return a;
}

int main() {
	
	int A, B, i, suma=0, a;
	
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A<=0){
			printf("A nije prirodan broj.\n");
		}
		else if(A>=B){
			printf("A nije manje od B.\n");
		}
	}while(A>=B || A<=0 || B<=0);
	
	for(i=0;i<B;i++){
		a=daj_prost();
		if(a>A && a<B){
			suma=suma+a;
		}
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	
	return 0;
}
