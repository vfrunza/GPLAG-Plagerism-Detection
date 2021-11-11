#include <stdio.h>
/*funkcija daj prost*/
 int daj_prost(){
	long int i,tacno=0;
	/*staticna varijabla postavljena na long da slucajno ne bi probila opseg*/
	long int static start=2;
	/*dijeljenje prvog starta u ovom slucaju s i postavljeno na 2 do vrijednosti na kojoj nam je start,
	jer je svaki broj dijeljiv s 1*/
		for(i=2; i<start; i++){
	/*ako je start dijeljiv sa i tacno ce postati 1*/
	 	  if(start%i==0){
	    	tacno=1;
                }
    /*ako je ispunjen uslov da je tacno 1, taj broj nije prost, trazimo povecanje starta i vracanje i 
    na pocetnu vrijednost*/
          if(tacno==1){
        	start++;
        	tacno=0;
        	i=2;
               }
      }
     /*nakon zavrsetka uvecamo start za sljedece pozivanje funkcije*/
    start++;
    /*ali ga i smanjimo onda u returnu jer nam treba vrijednost starta iz petlje*/
    return (start-1);	
   }
int main() {
	long int a,b,suma=0,prost;
	/*unos brojeva i provjeravanje opsega*/
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%ld %ld", &a,&b);
		if(a<1){
			printf("A nije prirodan broj.\n");
		}
		if(a>=b){
			printf("A nije manje od B.\n");
		}
		
	}while(a<1 || a>=b);
	/*pozivanje funkcije uz uslov da je dati prosti broj veci od a i manji od b*/
	do{
		prost=daj_prost();
		if(prost>a && prost<b){
	/*nadodavanje na sumu*/
		suma=suma+prost;
		}
		}while(prost<b);
	/*ispis dobijene sume*/
	printf("Suma prostih brojeva izmedju %ld i %ld je %ld.", a,b,suma);
	return 0;
}
