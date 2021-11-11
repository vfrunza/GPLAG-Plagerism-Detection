#include <stdio.h>

	int daj_prost () {
		int i;
		int static prosti_broj=1;
			do {
				prosti_broj++;
				for(i=2; i<prosti_broj; i++){
					if(prosti_broj%i==0)
					break;
				}
			}
			while(prosti_broj!=i);
		return prosti_broj;
	}
int main() {
		int broj_a,broj_b,suma=0,prost_broj,i,j;
		    /*Unos brojeva A i B (prirodni brojevi takvi da je A strogo manje od B)*/
			do {
				printf("Unesite brojeve A i B: ");
				scanf("%d %d",&broj_a,&broj_b);
					if(broj_a<=0)
						printf("A nije prirodan broj.\n");
					if(broj_a>=broj_b)
						printf("A nije manje od B.\n");
			}
			while(((broj_a<=0)||(broj_b<=0))||(broj_a>=broj_b));
			
			for(i=2; i<broj_b; i++){
				prost_broj=daj_prost();
					if(prost_broj>=broj_b)
						break;
				for(j=broj_a+1; j<broj_b; j++)
					if(j==prost_broj){
						suma=suma+prost_broj;
						break;
					}
				}
			printf("Suma prostih brojeva izmedju %d i %d je %d.",broj_a,broj_b,suma);
		
	return 0;
}
