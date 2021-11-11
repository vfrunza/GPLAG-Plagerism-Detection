#include <stdio.h>

int daj_prost(){
	int j,prost;
	static int i=1;
	while(1){
		i++;
			prost=1;
		for(j=2;j<i;j++){
			if(i%j==0){
				prost=0;
				break;
			}
		}
		if(prost)
			break;
	}
	return i;
}

int main() {
	int A,B,suma=0,prost_broj=0;

	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d%d",&A,&B);
		if(A<=0){
			printf("A nije prirodan broj.\n");
		}
		else if(A>=B){
			printf("A nije manje od B.\n");
		}
		else if(B<=0){
			printf("B nije prirodan broj.\n");
		}
		else{
			break;
		}
	}while(1);
	do{
		prost_broj=daj_prost();
		if(prost_broj>A && prost_broj<B)
			suma+=prost_broj;
	}while(prost_broj<B);
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}