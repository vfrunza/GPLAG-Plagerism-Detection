#include <stdio.h>
int dalijeprosT(int t){
	int a=1,i;
	for(i=2;i<t;i++){ 
	if(t%i==0){
	t=0;
	break;
	}
	}
	return t;
}
int daj_prost () {
	static int x=1;
	while(1) {
		if(dalijeprosT(++x)) return x;
	}
	}

int main() {
	int t,a,e,r,suma=0,br;
	do {
		printf("Unesite brojeve A i B:");
		scanf("%d%d", &t,&a);
		if(t<=0)
		printf(" A nije prirodan broj.\n");
		else if(t>=a)
		printf(" A nije manje od B.\n");
		
	} while (t<=0 || t>=a);
	e=t;
	r=a;
	for(;;){
		br= daj_prost();
		if(br>=r) break;
		else if(br>e)
		suma+=br;
	}
printf(" Suma prostih brojeva izmedju %d i %d je %d.",t,a,suma);
	return 0;
}
