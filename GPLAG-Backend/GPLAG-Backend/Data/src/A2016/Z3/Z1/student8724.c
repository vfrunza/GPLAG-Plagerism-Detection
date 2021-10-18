#include <stdio.h>

int daj_prost(){
	static int x=1;
	x++;
	while(1){
		int pr=1;
		int i=2;
		while(i<x){
			if(x%i==0)pr=0;
			i++;
			
		}
		if(pr==1)
		return x;
		else x++;
	}
}

int main() {
		int A, B;
		int suma=0;
		int a;
		do{
			printf("Unesite brojeve A i B: ");
			scanf("%d %d", &A, &B);
			if(B<=A)printf("A nije manje od B. \n");
			else if(B<=0 && A<=0) printf("A nije prirodan broj.\n");
			else if(A<=0)printf("A nije prirodan broj.\n");
		}while(B<=A || B<=0 || A<=0);
			
			while(1){
			a=daj_prost();
			if(a<=A)continue;
			if(a>=B)break;
			suma+=a;
			}
		printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	
	
	return 0;
}
