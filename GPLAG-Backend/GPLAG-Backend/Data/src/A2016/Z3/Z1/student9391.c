#include <stdio.h>
#include <math.h>

int prostbr(int br) {
	int i, j=sqrt(br);
	if(br==2) return 1;
	else if (br<2 || !(br%2)) return 0;
	for (i=3;i<=j;i+=2) {
		if(br%i==0) return 0;
	}
	return 1;
}


int daj_prost() {
	static int prosti=1;
	for(;;) {
		if(prostbr(prosti)==0) prosti++;
		else break;
	}
	prosti++;
	return prosti-1;
}


int main() {
	int a, b, i, suma=0, br;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		if(a<=0) {
			printf("A nije prirodan broj.\n");
		} else  if (a>=b) {
			printf("A nije manje od B.\n");
		}
	} while (a<=0 || a>=b);
	
	for(i=0;i<b;i++) {
		br=daj_prost();
		if(br>a && br<b) {
			suma+=br;
		}
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	//printf("Zadaća 3, Zadatak 1");
	return 0;
}
