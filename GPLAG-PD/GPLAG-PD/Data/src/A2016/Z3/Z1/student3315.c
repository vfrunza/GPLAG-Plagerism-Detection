#include <stdio.h>

int daj_prost() {
	int prost=1,i;
	static int p=1;
	while(2) {
		p++;
		for(i=2;i<p;i++) {
			if(p%i==0) {
				prost=0;
				break;
			}
			else{
				prost=1;
			}
		}
		if(prost==1) {
			return p;
		}
	}
}
	
	
	

	


			
	
	int main() {
	int A,B,i,x,suma=0;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		
		
		if((A==B) || (A>B)) {
			printf("A nije manje od B.\n");
			continue;
		}
		
		
		if(A==0 || (A<0 && B<0))
		printf("A nije prirodan broj.\n");
		else
		break;
		
		
		
	}
	while(2);
	
	for(i=0;i<B;i++) {
		x=daj_prost();
		if(x>A && x<B) {
			suma+=x;
		}
	}
	

	
	
	printf("Suma prostih brojeva izmedju %d i %d je %d. ",A,B,suma);
		
	
return 0;
}