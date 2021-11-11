#include <stdio.h>

int daj_prost () {
	int p=0, i; 
	static int q=0; 
	
	while (1){
		q++;
		if(q==2){
			return q;
		}
		else if(q==3){
			return q;
		}
		else {
		for(i=2; i<q; i++){
			if(q%i==0){
				p=0;
				break;
			}
		}
		if (p){
			return q;
		}
		else{
			p=1;
		}
	}
}
}
int main() {
	int A,B, sum=0, q=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf ("%d", &A);
		scanf ("%d", &B);
		if(A<1){
			printf("A nije prirodan broj.\n");
		}
		else if(A>=B){
			printf("A nije manje od B.\n");
		}
		
	}while(A<1 || A>=B || B<=0);
	while(q<B){
		q=daj_prost();
		if(q>A && q<B){
			sum+=q;
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, sum);
	return 0;
}