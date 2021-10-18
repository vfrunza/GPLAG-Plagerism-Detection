#include <stdio.h>
int daj_prost(){
	static int brojac=0;
	int broj=1,prost=1,i,j;
	brojac++;
	if(brojac==1) return 2;
	for(i=3; i<brojac*10; i++){
		prost=1;
		for(j=2; j<i;j++){
			if(i%j==0){
				prost=0;
				break;
			}
		}
		if(prost==1){

			broj++;
			if(broj==brojac){

			return i;}
		}
	}
}

int main() {
	int a,b,i,j,prost,suma=0;
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &a, &b);
	if(a>=b) printf("A nije manje od B.\n");
	else if(a <1) printf("A nije prirodan broj.\n");
	else if(b<1) printf("B nije prirodan broj.\n");
	}while(a<1 || b<1 || a>=b);
		j=daj_prost();
		while(j<a)
			j=daj_prost();
		if(j>a && j<b) suma+=j;
		while(j<b && j>=a)
		{
			j=daj_prost();
			if(j<b && j>a)
			suma+=j;
		}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a,b,suma);
	return 0;
}
