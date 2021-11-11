#include <stdio.h>

int daj_prost(){
	static int n=2;
	for(;;){
		int i, broj=1;
		for(i=2;i<n;i++){
			if(n%i==0) broj=0;
			if(broj==0) {n++;break;}
			}
			if(broj==1) {
				broj=n;
				n++;
				return broj;
		}
	}
}

int main() {
	int a,b,suma=0,i,broj=daj_prost();
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
	    if(a<=0){
	    	printf("A nije prirodan broj.\n");
	    	continue;
	    }
	    if(a>=b){
	    	printf("A nije manje od B.\n");
	    	continue;
	    }
	}while(a<=0 || a>=b);
	
		for(i=a+1;i<b;i++){
			while(i>broj) broj=daj_prost();
			if(i==broj) suma+=broj;
		}

	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	
	return 0;
}
