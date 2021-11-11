#include <stdio.h>

int daj_prost(){
	
	int i;
	static int x=1;
	x++;
	for(i=2; i<x; i++){
		if(x%i==0) {
			i=2; 
			x++;
		}
	}
	
	return x;
}
int main() {
	int A,B,s=0,l;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A,&B);
		
		if(A<=0) printf("A nije prirodan broj.\n"); 
		
		if(A>=B) printf("A nije manje od B.\n");
		
	}while(A<=0 || A>=B);
	
	
	do{
		l=daj_prost();
		if(l<=A) continue;
		if(l>=B) break;
		s=s+l;
		
	}while(l<B);
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,s);
	
	return 0;
}
