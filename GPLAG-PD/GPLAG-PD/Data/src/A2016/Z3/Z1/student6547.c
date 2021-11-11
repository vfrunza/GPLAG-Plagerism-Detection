#include <stdio.h>

int daj_prost () {
	int i,prost=0, broj=0;
	static int n=2;
	
	
	while(broj!=n) {
		prost=0;
		
	for(i=2;i<n;i++) {
		
		if(n%i==0)  prost++;
		if(prost==1) break;
	} 
	
	if(prost==1) { n++; }
	else {
		broj=n;
		n++;
		return broj;
	}
	
}
	 return 0;

}


int main() {
	int a,b,suma=0, y=0;
	do {
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&a,&b);
	if(a<=0) printf("A nije prirodan broj.\n");
	else if(a>=b) printf("A nije manje od B.\n"); 
	else if(b<=0) printf("B nije prirodan broj.\n");
	} while(a<=0 || b<=0 || a>=b);
	
		while(y<b) {
		y=daj_prost();
		if(y>a && y<b) suma+=y;
		}
	
	
	
		
		
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
