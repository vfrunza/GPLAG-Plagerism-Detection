#include <stdio.h>

int daj_prost() {
	static int x=1;
	int i,brojac=0,j;
	x++;
	if(x==2)
		return x;
	for(j=2;j<x;j++){
		brojac=0;
		for(i=2;i<x;i++){
			if(x%i==0)
				brojac++;
		}
		if(brojac==0)
			return x;
			else 
				x++;
	}
	return x;
}

int main() {
	int A,B,suma=0,i,x;
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B);
	if(A<=0)
		printf("A nije prirodan broj.\n");
			else if(B<=A)
				printf("A nije manje od B.\n");
	}while(A<=0||B<=0||B<=A);
	for(i=0;i<B;i++){
		x=daj_prost();
		if(x>A&&x<B)
			suma+=x;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.\n",A,B,suma);
	return 0;
}
