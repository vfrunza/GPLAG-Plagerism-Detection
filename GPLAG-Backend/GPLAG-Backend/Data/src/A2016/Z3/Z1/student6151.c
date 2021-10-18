#include <stdio.h>

int daj_prost (){
	/*staticka varijabla i nam pomaze da funkcija svaki put vraca naredni prosti broj
umjesto da se funkcija izvrsava iznova*/
static int i=1;
i++;

int p=1,j;
/*if uslovom provjeravamo da je taj broj djeljiv sa bilo kojim prirodnim brojem, osim jedinice i tog istog broja.
Ako jeste znaci da je taj broj slozen, p postaje 0 i izlazimo iz for petlje
jer nema potrebe da dalje provjeravamo djeljivost. Ako je vrijesnost p ostala na 1 to znaci da je taj broj prost. 
U tom slucaju funkcija vraca vrijednost i, koji je nas prost broj*/

while(p==1){
	for(j=2;j<i;j++){

		if (i%j==0) {p=0; break;}
	}
		if (p==1) return i;
		else {p=1; i++;}
	}
	 return 0;	
}
 
int main() {
	/*unos brojeva izmedju koji se racuna suma, uz provjeravanje uslova koji ti brojevi treba da zadovoljavaju*/
	int i,a,b;
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &a,&b);
	
	if(a>=b) {printf("A nije manje od B.\n"); continue;}
	if(a<1 || b<1) printf("A nije prirodan broj.\n"); 
	if(a<b && a>0 && b>0) break;
	}while(a>0 || b>0 || a<b);
	
	/*racunanje sume prostih brojeva izmedju 2 unesena broja, uz pozivanje funkcije daj_prost*/
	int suma=0;
	for(i=2;i<b;i++){
		int x=daj_prost();
		if(x<b && x>a)
		suma=suma+x;
	}
	/* ispis sume*/
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	
	return 0;
}
