#include <stdio.h>
int daj_prost(){
	int i,prost=1;
	static int broj=0;
	
	if(broj==0){
		broj=2;
		return 2;
	}else if (broj==2){broj =3; return 3;}
	do{
	broj+=2;
	if(broj<0){broj=0; return 0;}
	prost=1;
		for(i=2;i<broj;i++){
			if(broj%i==0){prost=0;}
		}
	
	}while(prost==0);
	return  broj;
}
int main() {
	
	
	int A,B,suma=0,prostbr=0,valid;
	do{
		printf("Unesite brojeve A i B: ");
		valid=scanf("%d %d",&A,&B);
		if (valid!=2){ printf("Greska pri unosu!\n");return 0;}
		else if(A<=0) printf("A nije prirodan broj.\n");
	/*	else if(B<=0) printf("B nije prirodan broj.\n");*/
		else if(B<=A) printf("A nije manje od B.\n");
		
	}while(B<=A || A<=0 || B<=0);
	
	while((prostbr=daj_prost()) < B){
		if (prostbr>A && prostbr<B) suma+=prostbr;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}
