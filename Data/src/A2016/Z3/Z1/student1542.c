#include <stdio.h>

int daj_prost(){
	static int y=1;
	int i,j,brojac;
	y++;
	for(i=y; i<1000000; i++){
		brojac=0;
		for(j=1; j<=i; j++){
			if(i%j==0)
			brojac++;
		}
		if(brojac==2)
		break;
	}
		y=i;
		return y;
}

int main() {
	int A,B,s=0,d;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d", &A);
		scanf("%d", &B);
		if(A<1) printf("A nije prirodan broj.\n");
		else if(A>=B) printf("A nije manje od B.\n");
	}while(A>=B || A<1 || B<1);

	
	for(; ;){
		d=daj_prost();
		if(d>A && d<B)
		s+=d;
		if(d>=B)break;
	}
		printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,s);
		
	return 0;
}
