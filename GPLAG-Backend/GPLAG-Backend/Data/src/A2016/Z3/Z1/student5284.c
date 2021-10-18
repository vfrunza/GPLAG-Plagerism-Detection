#include <stdio.h>

int Jel_prost(int n) {

int i;
int prost=1;
	for(i=2; i<n; i++) {
	if(n%i==0) prost=0;
}

return prost;
}

int daj_prost() {
static int n=1; 
		
		while(1==1)
		{
			n++;
			if(Jel_prost(n)) break;
			
		}
		
return n;
}

int main() {
int i,A,B;
int suma=0;
int pom;

do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	if(A<1) printf("A nije prirodan broj.\n");
	else if(A>=B) printf("A nije manje od B.\n");
	else if(B<1) printf("B nije prirodan broj.\n");
} while(A>=B || (A<1 || B<1));


for(i=0; i<B; i++) {
	pom=daj_prost();
	if (pom>A &&  pom<B) suma+=pom;
	
}
printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B ,suma);
	
	
return 0;
}
