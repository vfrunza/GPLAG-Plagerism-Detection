#include <stdio.h>
#include <math.h>

int daj_prost() {
static int a=1;
a++;
int j,prost=1;
    for(j=2;j<a;j++) {
        if(a%j==0){ a++;  
        j=1; }
    }
    if(prost) return a;
}


int main() {
	int A,B,x,i,suma=0,BROJ=0;
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B);
	if(A<=0 || B<=0 || A<=B){
		do {
			if(A<=0){ 
			printf("A nije prirodan broj.\n"); 
			printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B); continue; }
	else if(A>=B) {
		printf("A nije manje od B.\n");
		printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B); continue; }
	else if(B<=0) {
		printf("B nije prirodan broj.\n");
		printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B); continue;
	} BROJ=1;
		} while(BROJ==0);
	}
       for(i=1;i<B;i++){
	    x=daj_prost();
		if(x>A && x<B) suma+=x; 
       }
		
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	
	return 0;
}
