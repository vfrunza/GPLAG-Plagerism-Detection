#include <stdio.h>

int daj_prost(){
	static int dajprost=1;
	int i,j,brojac=0;
	for(i=dajprost+1;;i++){
		for(j=1;j<=i;j++){
			if(i%j==0) brojac++;
		}
		if(brojac==2){
			dajprost=i; break;
		}
		brojac=0;
	}
	return dajprost;
}

int da_li_je_prost(int broj){
	int i,brojac=0;
	for(i=1;i<=broj;i++){
		if(broj%i==0) brojac++;
	}
	if(brojac==2) return 1;
	return 0;
	
}
int main() {
	/*printf("Zadaća 3, Zadatak 1");*/
	int A,B,suma=0,zastava=0,i;
	while(zastava==0){
		printf("Unesite brojeve A i B: ");
		scanf("%d%d",&A,&B);
		
		if(A<1){
			printf("A nije prirodan broj.\n");
			continue;
		}
		if(A==B || A>B){
			printf("A nije manje od B.\n");
			continue;
		}
		zastava=1;
		for(i=2;i<=A;i++){
			if(da_li_je_prost(i)==1) daj_prost();
		}
		for(i=A+1;i<B;i++){
			if(da_li_je_prost(i)==1 && i>=A){
				suma+=daj_prost();
			}
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}
