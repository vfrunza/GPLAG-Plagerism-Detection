#include <stdio.h>

int daj_prost(){
	//Funkcija koja putem static int odrzava u memoriji nadjeni prosti broj
	static int prost=1;
	int i,k=0;
	for(;;){
		prost++;
		k=0;
		for(i=prost+1; i>1; i--){
			if(prost%i==0){
				k++;
			}
		}
		if(k==1){
			break;
		}
	
		
	}
	return prost;
}

int main() {
	//printf("Zadaća 3, Zadatak 1");
  	int A,B,suma=0,i;
  	//Unos brojeva sa ogranicenjem
  	do{
  		printf("Unesite brojeve A i B: ");
  		scanf ("%d %d", &A, &B);
  		if(A<=0){
  			printf("A nije prirodan broj.\n");
  			
  		}  else if (A>=B){
  			printf("A nije manje od B.\n");
  			
  		}
  	} while (A<=0 || B<=0 || A>=B);
  	//Petlja trazi sumu prostih brojeva izmeju unesenih A i B
  	for(;;){
  		i=daj_prost();
  		if(i>=B){
  			break;
  		}
  		if(i>A){
  			suma+=i;
  		}
  		
  		
  	}
  	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma);
  	
  	
	
	return 0;
}
