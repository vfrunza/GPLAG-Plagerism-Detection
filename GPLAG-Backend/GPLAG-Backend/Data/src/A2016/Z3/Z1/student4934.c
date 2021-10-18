#include <stdio.h>
/*postavljamo staticku promjenjivu jer je potreban sljedeci prosti broj svaki iduci put*/
int daj_prost () {
	int i;
	static int prost_broj=1;
	prost_broj++;
	/*racunamo prost broj*/
	for(i=2;i<prost_broj;i++){
		if(prost_broj%i==0){
			prost_broj++;
			i=2;
		}
	}
	return prost_broj;
}
int main () {
	int A,B,i,zbir=0,j,broj_slozenih=0,broj_prostih=0,prvi_broj;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		/*provjeravamo da li brojevi A i B zadovoljavaju sve uslove zadatka*/
		if(B<=A){
			printf ("A nije manje od B.\n");
		}
		if(A<1){
			printf ("A nije prirodan broj.\n");
		}
	}
	while ((A<1)||(B<1)||(B<=A));
	/*ispitujemo broj slozenih */
	for(j=A+1;j<B;j++){
		for(i=2;i<j;i++){
			if(j%i==0){
				broj_slozenih++;
				break;
			}
		}
	}
	/*racunamo broj prostih da bismo mogli toliko puta pozvati funkciju daj_prost*/
	broj_prostih=B-A-broj_slozenih-1;
	if(broj_prostih==0){
		printf ("Suma prostih brojeva izmedju %d i %d je 0.",A,B);
	}
	else {
		/*trazimo prvi broj koji je prost, a veci je od A*/
		prvi_broj=A;
		do {prvi_broj=daj_prost();
	}
	while(prvi_broj<=A);
	zbir=prvi_broj;
	/*for petlja nam ide od 1 jer znamo prvi broj zbira pa ga preskacemo*/
	for(i=1;i<broj_prostih;i++) {
		zbir=zbir+daj_prost();
	}
	printf ("Suma prostih brojeva izmedju %d i %d je %d.",A,B,zbir);
	
	}
	return 0;
}















