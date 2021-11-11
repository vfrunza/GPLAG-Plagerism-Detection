#include <stdio.h>
int daj_prost() {
	static int prost=1;
	int i, br=0;
while(1) {
	prost++;
	for(i=2; i<=prost/2; i++) {
		br=0;
		if(prost%i==0) {
			br++;
			break;
		}
	}
	if(br==0)
	return prost;
}
}
int main() {
	int a,b,i,temp,suma=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		if(a<1) printf("A nije prirodan broj.\n");
		if(a>=b) printf("A nije manje od B.\n");
	} while(a>=b || a<1);
	for(i=2; i<b; i++) {
		temp=daj_prost();
		if(temp>a && temp<b)
		suma+=temp;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a,b,suma);
	return 0;
}
