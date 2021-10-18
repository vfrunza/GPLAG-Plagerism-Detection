#include <stdio.h>

int daj_prost() {
		int i, prost;
		static int vrijednost=2;
		do{
			prost=2;
			for(i=1;i<vrijednost;i++){
				if(vrijednost%i==0){ 
					prost--;
				if(prost==0)
					break;
		        }
		    }
		if (prost) 
			return vrijednost++;
		else 
			vrijednost++;
		}while(1<2);
}

int main() {
	int a,b,suma=0, tmp;
	
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a ,&b);
		if (a>=b) 
			printf("A nije manje od B.\n");
		else if (a<=0) 
			printf("A nije prirodan broj.\n");
	}while(a>=b || a<=0 || b<=0);
	
	while(1) {
		tmp=daj_prost();
		if(tmp>=b) 
		break;
		else if (tmp>a)
		suma=suma+tmp;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	
	return 0;
}
