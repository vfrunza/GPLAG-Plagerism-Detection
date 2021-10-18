#include <stdio.h>
#include <stdlib.h>


int daj_prost() {
	static int k=1;
	int i;
	k++;
	for(i=2;i<k;i++) {
		if(k%i==0) {k++; i=2;}
	}
	
	
	return k;
}

int main() {
	
	int a,b,suma=0,k;
	
	pocetak:
	
	printf("Unesite brojeve A i B: ");
	if( scanf("%d %d", &a, &b) != 2 ) {
		while ((getchar()) != '\n');
		 printf("A nije prirodan broj.\n");
		 goto pocetak;
	}
	else {

	do{
		if(a<1)  { printf("A nije prirodan broj.\n");
				printf("Unesite brojeve A i B: ");
				if(scanf("%d %d", &a, &b) != 2) { while ((getchar()) != '\n'); printf("A nije prirodan broj.\n"); goto pocetak; }
		}
		else if(a>=b) {	printf("A nije manje od B.\n");
						printf("Unesite brojeve A i B: ");
						if(scanf("%d %d", &a, &b)!= 2) { while ((getchar()) != '\n'); printf("A nije prirodan broj.\n"); goto pocetak; }
		}
	}while(a<1 || a>=b);
}
	
	
	do{
		k=daj_prost();
		
	}while(k<=a);
	suma=k;
	if(k>b) suma-=k;
	
	while(k<b) {
		
		k=daj_prost();
		suma+=k;
		if(k>=b) suma-=k;
		
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	
	return 0;
}
