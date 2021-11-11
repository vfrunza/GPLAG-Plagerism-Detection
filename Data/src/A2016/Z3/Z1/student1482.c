#include <stdio.h>
int daj_prost () {
	int i, b=0;
	static int prost_broj=1;
	if(prost_broj==1)
		prost_broj=2;
	else if (prost_broj==2)
		prost_broj=3;
	else
	{
		prost_broj+=2;
		for(i=2; i<=prost_broj;i++)
			if(prost_broj%i==0)
				b++;
		if(b!=1)
			daj_prost();
	}
	  
	return prost_broj;
}

int main() {
	int A,B,suma=0,prost_broj;
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B);
	if(A<=0)
		printf("A nije prirodan broj.");
	else if(A>=B)
	    printf("A nije manje od B.");
	else { 
		prost_broj=daj_prost();
		while(prost_broj<B) {
			if(prost_broj>A)
			 	suma+=prost_broj;
			 prost_broj=daj_prost();
		}
		printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	}
	return 0;
}
