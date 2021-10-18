#include <stdio.h>

//funkcija za proste brojeve
	int daj_prost(){
		int prost;
		int i;
		static int broj=1;
		do{
			broj++;
			prost=1;
			//ispitivanje da li je broj prost
			for(i=2;i<broj;i++){
				if(broj%i==0){
					prost=0;
					break;
				}
			}
		}
		while(prost!=1);
		return broj;
	}
	
	int main(){
		int a,b;
		//unos brojeva
		do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a<1){
			printf("A nije prirodan broj.\n");
		}
		if(a>=b){
			printf("A nije manje od B.\n");
		}
		}
		while(a>=b || a<1);
		int suma;
		suma=0;
		int broj;
		//suma svih prostih u datom intervalu
		do{
			broj=daj_prost();
			if(broj>a && broj<b){
				suma+=broj;
			}
		}
		while(broj<b);
		// ispis
		printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
		return 0;
	}
