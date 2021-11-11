#include <stdio.h>

int daj_prost() {
	static int a=1;
	int i;
	a++;
	for(i=2;i<a;i++)
		if(a%i==0) {
			a++;
			
			i=1;
		}
	return a;
}

int main()
{
	int a, b;
	int suma=0;
	int y;

ponovi:	
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &a, &b);
	if(a<=0 && b>=a) {
		printf("A nije prirodan broj.\n");
		goto ponovi;
	} else {
		if((a<=0 && b<=0) && b>=a) {
			printf("a nije prirodan broj.\n");
			goto ponovi;
		} else {
			if(a>=b) {
				printf("A nije manje od B.\n");
				goto ponovi;
			}
		}
	}
	
	while(1) {
		y=daj_prost();
		if(y<=a) continue;
		if(y>=b) break;
		suma+=y;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}