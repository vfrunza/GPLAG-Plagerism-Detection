#include <stdio.h>

/*Funkcija vraca proste brojeve redom*/
int daj_prost(){
	int i,prost;
	static int n=1; 
	do{
		prost=1;
		n++;
		/*znamo je da je prvi prost broj 2*/
		if(n==2)continue;
		/*provjeravamo da li je broj prost*/
		for(i=2;i<n;i++){
			if(n%i==0){ 
			prost=0 ;
		
		} 
		
	}
	}while(prost==0);
	return n;
}

int main() {
	int A,B,suma=0,temp;
	/*Unosimo brojeve A i B za koje provjeravamo da li su prirodni i da li je A<B.
	U zavisnosti koji se uslov ne ispuni,ispisuje se poruka da broj nije prirodan ili da A nije manje od B i korisnik ponovo unosi brojeve, dok ne unese tacne.*/
	
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A,&B );
	
	if(A<=0) printf("A nije prirodan broj.\n");
	else if(A>=B) printf("A nije manje od B.\n");
	
	}
	while(A<=0 || B<=0 || A>=B);
	/*Pozivamo proste brojeve do A*/
	do{
		temp=daj_prost();
		if(temp>A)
		break;
		
	}
	while(temp<=A);
	/*Sumiramo proste brojeve izmedju A i B pozivanjem funkcije daj_prost*/
	while(temp<B){
		suma+=temp;
		temp=daj_prost();
		if(temp>=B)
		break;
	}

	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	
	
	
	return 0;
}


