#include <stdio.h>
int daj_prost(){
	static int i=1;
	int k,prost;
	while(1){
		prost=1;
		i++;
			for(k=2;k<i;k++){
				if(i%k==0){ 
					prost=0;
					break;
				}
			}
		if(prost)
			return i;		
	}
}

	int main() {
		int A,B,x,suma=0;
		 do{
			printf("Unesite brojeve A i B: ");
			scanf("%d%d",&A,&B);
			if(A<=0){
					printf("A nije prirodan broj.\n");
			}
			if(A>=B){
				printf("A nije manje od B.\n");
			}
		}while(A<=0 || A>=B);
	   
		do{
			x=daj_prost();
			if(x>A && x<B)
				suma+=x;
		}while(x<B);
		
		printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
		
	
		return 0;
	}
