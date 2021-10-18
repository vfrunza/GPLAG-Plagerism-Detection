#include <stdio.h>
int daj_prost(){
    static int a=1;
	int i, prost=1;
	if (a==1) {
		a++;
		return 2;
	}
	else {
		do{
		a++;
		prost=1;
	        for(i=2;i<a;i++){
		       if(a%i==0){
		  	   prost=0;
		  	   }
		    }
		}
		while(prost==0);
	}
return a;
}
int main() {
	/*printf("Zadaća 3, Zadatak 1");*/
	int A,B,C,suma,broj_uspjesno_unesenih;
    /*scanf("%d %d", &A,&B);*/
	do{
	   printf("Unesite brojeve A i B: ");
	   broj_uspjesno_unesenih=scanf("%d %d", &A,&B);
       if(broj_uspjesno_unesenih==2) {
	      if(A<=0 && A<B)printf("A nije prirodan broj.\n");
	      else if(A>=B)printf("A nije manje od B.\n");
       } 
       else{ 
       	printf("Zasto ste pustili macku preko tastature?");
       	return 0;
       	}
	}
	while(A<=0 || B<=0 || A-B==0  || A>=B);
	suma=0;
	C=daj_prost();
	while(C<B){
		if(C>A && C<B)suma+=C;
	    C=daj_prost();
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);


return 0;
}
