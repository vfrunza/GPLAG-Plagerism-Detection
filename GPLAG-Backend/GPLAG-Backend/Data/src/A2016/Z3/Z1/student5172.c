#include <stdio.h>

int daj_prost() {
	int j;
	int static i=2;
	
	for(; ; i++) {
		for(j=2; j<=i; j++) {
			
			if(j==i)
			{
				return i++;
			}
			if(i%j==0)
			{
			   break;	
			}
		}
	}
}

int main() {
	int A,B,suma=0,broj;
	
do {
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	if(A<1) 
	{
		printf("A nije prirodan broj.\n");
	}
	if(A>=B) 
	{
		printf("A nije manje od B.\n");
	}
	}while(A<1 || A>=B);
	
	
broj = daj_prost();
while(broj<B) {
	if(broj>A) 
	{
		suma+=broj;
	}
	broj = daj_prost();
}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d. ",A,B,suma);
	
	return 0;
}