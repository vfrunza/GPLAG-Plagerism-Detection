#include <stdio.h>
int daj_prost () {
	static int j=1;
	int i=0;
	/*Traženje prostih brojeva između A i B*/
	do {
		j++;
    	for(i=2 ; i<j ; i++) 
    		if (j%i==0) 
    		break; 
		}
    while (i!=j);  
	return j;
}
int main() {
	int A=0,B=0,suma=0,x=0;
	printf ("Unesite brojeve A i B: ");
	do {
		scanf("%d %d",&A,&B);
		if (A<=0) {
			printf ("A nije prirodan broj.\n");
			printf ("Unesite brojeve A i B: ");
		}
		else if (A>=B) {
			printf ("A nije manje od B.\n");
			printf ("Unesite brojeve A i B: ");
		}
	}
	while ((A<1) || (B<1) || (A>=B));
	/* Računanje sume prostih brojeva*/
	do {
		x=daj_prost();
		if (x>A && x<B)
			suma+=x;
	}
	while (x<B);
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}
