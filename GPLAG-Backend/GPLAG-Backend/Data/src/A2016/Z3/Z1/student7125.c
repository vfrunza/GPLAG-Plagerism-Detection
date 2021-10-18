#include <stdio.h>
int daj_prost();

int main() {
	int br_A, br_B, prost_br=0, sum=0, k;
	//Unos
	do{
		printf("\nUnesite brojeve A i B: ");
		scanf("%d%d", &br_A,&br_B);
		
		if(br_A>=br_B)
			printf("A nije manje od B.");
			
		else if(br_A<=0)
			printf("A nije prirodan broj.");
			
		else if (br_B<=0)
			printf("B nije prirodan broj.");
			
	}while(br_A>=br_B || br_A<1 || br_B<1);
	
	do{
		prost_br = daj_prost();
		
	}while (prost_br < br_A);

	
	//Računanje
	for (k=br_A; k<br_B; k++){
		if(k!=br_A)
			prost_br=daj_prost();

		if(prost_br > br_A && prost_br < br_B){
			sum += prost_br;
			continue;
		}
	}
	
	//Ispis
	printf("Suma prostih brojeva izmedju %d i %d je %d.",br_A,br_B,sum);
	return 0;
}

int daj_prost(){
	
    static int prost=1;
	int j,brojac=1;
	
	prost++;
	
	lul:
		for(j=2; j<((prost/2)+1); j++){
			if(prost%j==0){
			brojac=0;
			j=prost;
			}
		}
	//Osigurava da se broj 2 uzima kao prost	
	if(prost==2)
	brojac=1;
	
	if(brojac)
		return prost;
		
	else {
		prost++;
		brojac=1;
		goto lul;
//goto potrebna da u slučaju kada broj nije prost funkcija odabere novi broj
	}
}
