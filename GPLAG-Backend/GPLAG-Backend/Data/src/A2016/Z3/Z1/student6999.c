#include <stdio.h>

int daj_prost(){
	static int broj=1;
	int i,prost=1,k=1;

while(k){
		broj++;
		//hard code za 2.
		if(broj==2)return broj;
		//za ostale...
		else{
			for(i=2;i<broj;i++){
				//ako je slozen
					if(broj%i==0){
						prost=0;
						break;
					}
			}
		//provjeravanje prost 
			if(prost) return broj;
			else{
				// ako nije...
				prost=1; //zbog sljedece iteracije.
			}
		}
	}
}

int main() {
	int br=daj_prost(),A,B,suma=0,i;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
			if(A<=0){
				printf("A nije prirodan broj.\n");
				continue;
			}
		else	if(A>=B){
				printf("A nije manje od B.\n");
				continue;
			}
	}while(A<=0 || B<=0 || A>=B);
	
		while(br<=B){
			br=daj_prost();
				if(br>A && br<B){
					suma+=br;
				}
		}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);		
	return 0;
}
