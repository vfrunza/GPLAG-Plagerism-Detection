#include <stdio.h>
int daj_prost (){
	static int x=2;
	int i,c, a=0;
	if (x==2){ 
		x++; 
		return 2;}
	while (a==0){
	for(i=2; i<x; i++){
		if(x%i==0) {
			a=0; 
			break;
		}
		else a=1;
	}
	if(a==0) x++;
	}
	c=x;
	x++;
	
	return c;
}

int main() {
	int A, B, c,i, suma=0;
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	while(A<=0 || B<=0 || A>=B){
		if(A>0 && B>0 && A<B) break;
		else if(A<=0) printf("A nije prirodan broj.\n"); 
		else if (A>=B) printf ("A nije manje od B.\n");
		else if (B<=0) printf ("B nije prirodan broj.\n");
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
	}
	
	for(i=0; i<B; i++){
		c=daj_prost();
		if (c>A && c<B)
		suma=suma+c;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}
