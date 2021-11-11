#include <stdio.h>
int daj_prost(){
	int i;
	static int c=1;
	haha:
	c++;
	for(i=2;i<c;i++){
	  if(c%i==0){
		goto haha;
			
		}
	}
	return c;
	
}
int main() {
	int A,B,suma=0,x;
	do{
	printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A,&B);
		if(A<=0){
			printf("A nije prirodan broj.\n");
		}else if(B<=0 && A>=0){
			printf("A nije manje od B.\n");
		}else if(A>=B){
			printf("A nije manje od B.\n");
		}
	}while(A<=0 || A==B || B<0);
	do{
		x=daj_prost();
		if(x>A && x<B){
			suma+=x;
		}
	}while(x<B);
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma);
	
	return 0;
}
