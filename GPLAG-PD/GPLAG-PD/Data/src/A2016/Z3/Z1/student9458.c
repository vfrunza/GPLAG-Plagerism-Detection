#include <stdio.h>
#define true 1
#define false 0
#define bool int

bool Da_li_je_prost(unsigned n){
	unsigned i;
	for(i=2; i<n; i++)
		if(n%i==0)return false;
		return true;
}

int daj_prost(){
	static unsigned prost_povratni=1;
	if(prost_povratni==1)
		return ++prost_povratni;
	for(;;){
		prost_povratni++;
		if(prost_povratni%2==0)
			continue;
		if(Da_li_je_prost(prost_povratni))
			return prost_povratni;
	}
}

int main() {
	int a,b,d,sum=0;
	printf("Unesite brojeve A i B: ");
	scanf("%d%d",&a,&b);
	while(a<=0 || b<=0 || a>=b){
		if (a<=0 )printf("A nije prirodan broj.\n");
		else if(a>=b)printf("A nije manje od B.\n");
		printf("Unesite brojeve A i B: ");
		scanf("%d%d",&a,&b);
	}
	for(;;){
		d=daj_prost();
		if(d<a+1)continue;
		if(d>=b)break;
		sum+=d;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.\n",a,b,sum);
	return 0;
}
