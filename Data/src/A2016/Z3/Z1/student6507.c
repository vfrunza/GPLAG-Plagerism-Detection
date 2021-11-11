#include <stdio.h>
#include <math.h>

int daj_prost(){
	int i;
	static int c=1; /*Koristimo staticku promjenljivu zbog uslova zadatka*/
	c++;
	if(c==2) return 2;
	if(c==3) return 3;
	for(i=2; i<=sqrt(c); i++){
		if(c%i==0) {
			c++; 
			i=1;
		}
	}
	return c;
}

int main() {
	int a, b, x, suma=0;
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &a, &b);
	while(a<=0 || a>=b){
		if(a<=0) printf("A nije prirodan broj.");
		else printf("A nije manje od B.");
		
		printf("\nUnesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
	}
	
	x=daj_prost();
	
	while(x<=a){
		x=daj_prost();
	}
	while(x<b){
		suma+=x;
		x=daj_prost();
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
