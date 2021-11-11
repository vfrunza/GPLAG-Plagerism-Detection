#include <stdio.h>

int daj_prost() {
	int i, prost;
	static int a=2;
	while(5==5){
		prost=1;
	for(i=2;i<a;i++){
		if(a%i==0)prost=0;
	}
	if(prost==0)a++;
	else {
		a++;
		return a-1;
	}
	}
	}

	
	
int main() {
	int a,b;
	int broj;
	int suma=0;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d%d", &a,&b);
		if(a<b && a>0 && b>0)break;
		if(a<=0)printf("A nije prirodan broj.\n");
		else if(a>=b)printf("A nije manje od B.\n");
	}while(a<=0 || b<=0 || a>=b);
	
	while(5==5){
	broj=daj_prost();
	if(broj<=a)continue;
	if(broj>=b)break;
	suma+=broj;
	}
    printf("Suma prostih brojeva izmedju %d i %d je %d.", a,b,suma);
	return 0;
}
