#include <stdio.h>

int daj_prost() {
	int k,l,prost=1;
	static int temp=-1,kraj=1,temp1=0;
    for (k=kraj+1; k>0; k++) {
    	prost=1;
    	for (l=k-1; l>1; l--) {
    		if (k%l==0) {
    			prost=0;
    		}
    	}
    	if (prost!=0) {
    		temp++;
    	}
    	if (temp1==temp) {
    		kraj=k;
    		temp1++;
    		break;
    	}
    }
    return kraj;
}

int main() {
	int a,b,pretpostavka=1,suma=0;
	while (pretpostavka!=0) {
	 printf("Unesite brojeve A i B: ");
	 scanf("%d %d", &a,&b);
	 if (a<=0) {
	  printf("A nije prirodan broj.\n");
	 }
     else if (a>=b) {
	  printf("A nije manje od B.\n");
     }
	 else pretpostavka=0;
	}
	while (pretpostavka<b) {
		pretpostavka=daj_prost();
	    if (pretpostavka<=a) {
	    	continue;
	    }
	    else if (b>pretpostavka) {
	    	suma+=pretpostavka;
	    }
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a,b,suma);
	return 0;
}
 