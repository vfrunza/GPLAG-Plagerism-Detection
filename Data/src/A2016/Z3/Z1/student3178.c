#include <stdio.h>

int daj_prost(){
	static int broj=1;
	int i;
	broj++;

	do{
			for(i=2; i<broj; i++){
		if(broj%i == 0){
		broj++;
		break;

        	}
			}
			}
	while( i != broj);
			
	return broj;

}

int main() {
	
	int A, B;
	int suma=0, x=0;
	
	do{
        printf("Unesite brojeve A i B: ");
        scanf("%d %d", &A, &B);
	    if(A<=0)
    	printf("A nije prirodan broj.\n");
    	if(A>=B)
    	printf("A nije manje od B.\n");
    	
	}
	while( A<=0 || B<=0 || A>=B);
		

	for(;;){
		x=daj_prost();
      if (x>=B)
      break;
      if(x > A && x < B)
		suma= suma + x;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma);
	return 0;
}
