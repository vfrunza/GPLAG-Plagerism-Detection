#include <stdio.h>
#include <math.h>
int daj_prost(){
	int i;
	static int n=1;
	n++;
	if(n==2) return n;
	
	/*printf("usao i n je %d",n);*/
	for(;;){
		int nasao=1;
		if(n==2) return n;
		for(i=2;i<=sqrt(n);i++){
			if(n%i==0) {
				nasao=0;
				break;
			}
		}
		if(nasao==1) return n;
		else n++;
	}
}
int main() {
	int A,B,i,suma=0;
	for(;;){
		printf("Unesite brojeve A i B: ");
		scanf("%d%d",&A,&B);
		if(A>=B) 
			printf("A nije manje od B.\n");
		else if(A<=0)
			printf("A nije prirodan broj.\n");
		else if(A>0 && B>A) break;
	
		
	}
	
	for(i=0;i<B-1;i++){
		
		if(i>A){
			int n=daj_prost();
			if(n>=B) break;
			suma=suma+n;
			i=n;
		
		}
		else{ 
			int n=daj_prost();
			i=n;
			if(n>A && n<B) suma=suma+n;
			
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	
	return 0;
}
