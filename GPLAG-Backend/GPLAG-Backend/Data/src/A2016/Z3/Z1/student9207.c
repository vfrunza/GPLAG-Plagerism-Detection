#include <stdio.h>
int daj_prost(){
	static int x=2,prost=0,i;
	
	while(1) {
		prost=1;
		for( i=2;i<x;i++){
			if(x%i==0){
				prost=0;
				break;
			  }
			  
			}
			x++;
		
			if(prost)
			break;
		}
		return x-1;
}



int main () {
	
	
	
	int A,B,suma=0,x;
	greska:
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B);
	
	if(A<=0) { 
		printf("A nije prirodan broj.\n");
		goto greska;
	}
	
	else if(A>=B) {
		
	
	printf("A nije manje od B.\n");
		
	goto greska;
	}

	
	else{
		x=daj_prost();
		while(x<=A) {
			x=daj_prost();
		}
		
		while(x<B){
			suma+=x;
			x=daj_prost();
			
		}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	}
	
	
return 0;

	
}
