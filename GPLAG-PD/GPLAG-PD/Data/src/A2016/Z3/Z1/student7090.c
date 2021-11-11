#include <stdio.h>
#include <math.h>

int daj_prost(){
	static int pocetni=2;
	int i,x;
	if (pocetni==2)
	return pocetni++;
	x=0;
	while(!x){
		x=1;
		for(i=2;i<=sqrt(pocetni)+1;i++)
		if(pocetni%i==0){
			x=0;
			pocetni++;
		}
	}
	return pocetni++;
}
int main() {
	int a,b;
	int prost;
	int zbir=0;
	for(;;){
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&a,&b);
	if (a<=0)
	printf("A nije prirodan broj.\n");
	//else if (b<=0)
	//printf("B nije prirodan broj.\n");
	else if(!(a<b))
	printf("A nije manje od B.\n");
	else break;
	}
	prost=daj_prost();
	while(prost<=a)
	prost=daj_prost();
	while(prost<b){
		zbir=prost+zbir;
		prost=daj_prost();
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,zbir);
	return 0;
}
