#include <stdio.h>

int prost (int n){
	int i;
	for(i=2; i<n; i++)
		if (n%i==0) return 0;
		 return 1;
}
int daj_prost () {
	int static a=1;
	a++;
	while (prost(a)==0) a++;
	return a;
}

int main() {
	int a=0, b=0, suma=0, br;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d%d", &a, &b);
		if (a<=0) printf ("A nije prirodan broj.\n");
		if (a>=b) printf ("A nije manje od B.\n");
		} while (a<=0 || a>=b);
		br=0;
		while(br<a)br=daj_prost();
		for (;;) {
			if (br>a && br<b) suma+=br;
			if(br>=b)break;
			br=daj_prost();
		}
	printf ("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}





























