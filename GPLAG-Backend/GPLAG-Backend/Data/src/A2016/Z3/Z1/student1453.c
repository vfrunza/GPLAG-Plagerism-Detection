#include <stdio.h>

int daj_prost(){
	static int x=1;
	int i, prost=0, max, brojac;
	x++;
	max=x;
	do{
		brojac=0;
		for(i=2;i<max;i++){
			if(max%i==0)
				brojac++;
			
		}
		if(brojac==0){
			prost=1;
			break;
		}
		
		max++;
		x++;
	}while(prost==0);
	
	return x;
}

int main() {
	int A, B, i,y, rezultat=0;
	
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d%d", &A,&B);
		if(A<=0){
			printf("A nije prirodan broj.\n");
			continue;
		}
		if(B<=A)
			printf("A nije manje od B.\n");
		else
			break;
		
	}while(1);
	

	y=daj_prost();
	do{
		if(y<=A)
			y=daj_prost();
		else
			break;
		
	}while(1);
	
	for(i=0;i<B;i++){
		if(i==y){
			rezultat+=y;
			y=daj_prost();
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, rezultat);
	
	
	return 0;
}
