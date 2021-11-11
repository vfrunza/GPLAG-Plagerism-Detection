#include <stdio.h>
int daj_prost()
{
	static int x=2;
	int i;
	for(i=2;i<x;i++){
		if(x%i==0){ 
			x++; 
			i=2;
		}
	}
	if(i==x) 
	return x++;
}
int main() {
	int a,b,i;
	unsigned long int suma=0;
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d%d",&a,&b);
	if(a>=b){
		printf("A nije manje od B.\n");
	}
	else if(a<=0){
		printf("A nije prirodan broj.\n");
	}
	}while(a>=b || a<=0);
	for(i=0;i<=b;i++){
		int x=daj_prost();
		if(a<x && b>x) suma=suma+x;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %lu.",a,b,suma);
	return 0;
}
