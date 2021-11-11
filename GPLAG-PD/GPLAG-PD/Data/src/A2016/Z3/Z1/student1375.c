#include <stdio.h>
int daj_prost()
{
	static int n=2; int prost, i,j;
    for(i=n; i<5000; i++) {
		prost=1;
		for(j=2; j<i; j++) 
		if(i%j==0) { prost=0; break;}
		if(prost==1) {n=i; break;} }
     return n++;
	 }


int suma(int A, int B)
{
	int suma=0, i,x;
    for(i=A+1; i<B; i++){
    	x=daj_prost();
    	if(x<=A){ i--; continue;
    }
	if(x>=B) break;
	suma+=x;
}
	return suma;
}

int main() {
	int A, B;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
	if (A==B || A>B) printf("A nije manje od B.\n");	
	else if(A<=0) printf("A nije prirodan broj.\n");
	else if(B<=0) printf("B nije prirodan broj.\n");
	}while(A<=0 || B<=0 || A==B || A>B);
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma(A,B));
	
	return 0;
}
