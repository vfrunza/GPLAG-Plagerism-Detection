#include <stdio.h>

int daj_prost(){
	static int prost_broj=1;
	int brojac=0;
	int i,j;
	for(i=prost_broj+1;i<100000;i++){
		for(j=1;j<i;j++){
			if(i%j==0) brojac++;}
			if(brojac==1){prost_broj=i; return i;}
			brojac=0;
	}
	
}

int main() {
	int i;
	long int suma=0;
	int A,B;
	int prost;
	jodja:
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B);
	if(A>=B){printf("A nije manje od B.\n"); goto jodja;}
	else if(A<=0){printf("A nije prirodan broj.\n"); goto jodja;}
	else if(B<=0){printf("B nije prirodan broj.\n"); goto jodja;}
	for(;;){
		prost=daj_prost();
		if(prost>B) {break;}
		if(prost>A && prost<B){suma=suma+prost;}
		
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}
