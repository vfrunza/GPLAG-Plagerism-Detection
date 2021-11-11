#include <stdio.h>

int da_li_je_prost_broj(int broj){
	int kazi=1, i;
	if(broj<2) return 0;
	for (i=2; i<broj; i++){
		if(broj%i==0) {kazi=0; break;}
	}
	return kazi;
}

int daj_prost(){
	static int a=1;
	a++;
	while(da_li_je_prost_broj(a)!=1) a++;
	return a;

}


int main() {
	int A, B, p, suma=0;
	do{
	printf ("Unesite brojeve A i B: ");
	scanf ("%d %d",&A,&B);
	if (A < 1) printf ("A nije prirodan broj. \n");
	else if (A > B) printf ("A nije manje od B. \n");
	else if (A == B) printf ("A nije manje od B. \n");
	}while(A<1 || A==B || A>B);
	
	p=daj_prost();
	while (p<=A) p=daj_prost();
	while (p<B) {
		suma+=p; 
		p=daj_prost();
	}
	printf ("Suma prostih brojeva izmedju %d i %d je %d. ",A, B, suma);
	return 0;
}
