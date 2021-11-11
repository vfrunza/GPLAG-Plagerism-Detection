#include <stdio.h>

int daj_prost(){
	static int i=1;
	int j,a;
	while(i<10000){
		i++;
		a=1;
		for(j=2;j<i;j++){
		if(i%j==0){
			a=0;
			break;
	    	}	
	    }
		if(a==1) 
		return i;
	}
}

int main() {
	int i;
	int suma=0, broj=0;
	int A, B;
	do{
	    printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A,&B);
		if(A<=0) printf("A nije prirodan broj.\n");
		if(A>=B) printf("A nije manje od B.\n");
	}while(A<=0 || A>=B );
	
	for(i=A+1;i<B;i++){
		broj=daj_prost();
		if(broj>A && broj<B)
		suma+=broj;
	}
	  printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma);
	
	return 0;
}
