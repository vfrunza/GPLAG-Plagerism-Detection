#include <stdio.h>

int daj_prost(){
	static int PROST=2;
	int i, br;
	for(;;PROST++){
	br=1; //ispitivanje da li su brojevi prosti ili slozeni
	for(i=2; i<PROST; i++){
		if(PROST%i==0){
			br=0;
		}
	}
	if(br==1) return PROST++;
	}

	
}

int main() {
	int A, B, poz_f=0, suma=0, i=0;
	do{
	printf("Unesite brojeve A i B: "); scanf("%d %d", &A, &B);
	
		if(A<=0){
			printf("A nije prirodan broj.\n");
		}
		
		if(A>B || B<A || A==B){
			printf("A nije manje od B.\n");
		}
	}while(A<=0 || B<=0 || A>B || B<A || A==B);
	

	// prilikom poziva funkcije daj_prost, f-ja se izvrsava od 2 do nekog nedoglednog broja; zbog toga je nuzno da naredna petlja pocinje od nule do broja B, kako bismo na izvjestan nacin ''zapoceli'' petlju istovjetno s funkcijom; uzimajuci u obzir da funkcija ne moze primiti parametar kako bi znala da je nama pogodnije zapoceti ispitivanje prostih brojeva od A+1 '
	for(i=0; i<B; i++){
		poz_f=daj_prost(); 
		if(poz_f>A && poz_f<B){//ogranicavamo poz_f u okviru naznacenih intervala ne ukljucujuci iste
		suma=suma+poz_f;
		}
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}
