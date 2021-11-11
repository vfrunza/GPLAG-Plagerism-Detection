#include <stdio.h>
int daj_prost(){
	int i,Prost=1;
	static int Brojac=1;
	
	while(Prost==1){
		Brojac++;
			for(i=2;i<Brojac;i++){
				if(Brojac%i==0){
					Prost=0;
					break;
				}
			}
			if(Prost==1) 
			return Brojac;
			else Prost=1;
		
	}
}

int main() {
	int j,x,A,B,Suma=0;
	
	/*Unos brojeva*/
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B);
	if(A<=0)
		printf("A nije prirodan broj.");
	if(A>=B)
		printf("A nije manje od B.");
	if(A<=0 || B<=A)
	    printf("\n");
	  }	  while(B<=A || A<=0);
	
	/*Suma unesenog intervala*/ 
	for(j=2;j<B;j++){
	    x=daj_prost();
	    if(x>A&&x<B)
	    Suma+=x;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,Suma);
	return 0;
}
