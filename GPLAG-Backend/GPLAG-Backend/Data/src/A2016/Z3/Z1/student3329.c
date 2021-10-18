#include <stdio.h>

int daj_prost(){
	int i, k, prost=0;
	static int n=1;
	do{
		if (n==2){prost=1; k=n;}
		for (i=2; i<n; i++){
			if (n%i!=0){
				prost=1;
				k=n;
			}else{
				prost=0; break;
			}
		}
		n++;
	}while(prost==0);
	if (prost==1){
		return k;
	}else{return 0;}
}

int main() {
	int a, b, prostVal ,suma=0;
	do{
		printf("Unesite brojeve A i B: "); scanf("%d %d", &a, &b);
		if (a>=b){
			printf("A nije manje od B.\n");
		}else if (a<1){
			printf("A nije prirodan broj.\n");
		}else if (b<1){
			printf("B nije prirodan broj.\n");
		}
	}while(a<1 || a>=b || b<1);
	
	do{
		prostVal=daj_prost();
		if((prostVal>a && prostVal<b)||prostVal==0){
			suma+=prostVal;
		}
	}while(prostVal<b);
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}