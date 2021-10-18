#include <stdio.h>
int daj_prost(){
	int prost=1;
	int i;
	static int n=1;
	while(1){
		n++;
		if(n==2)
		return n;
		else {
			for(i=2;i<n;i++){
					if(n%i==0){
						prost=0;
						break;
					}
					
			}
		}
		if(prost) return n;	
		else 
		prost =1;
	}
}
int main(){
	int A,B,suma=0,n=0;
	do{
		printf("\nUnesite brojeve A i B: ");
		scanf("%d %d", &A,&B);
		if(A>=B) printf("A nije manje od B.");
		if(A<1) printf("A nije prirodan broj.");
	}
	while(A>=B || A<=0);
	while(n<B){
		n=daj_prost();
		if(n>A && n<B){
			suma+=n;
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma);
	return 0;
}