#include <stdio.h>
int daj_prost () {
	int i,m,l;
	static int t=2;
	
	if(t==2){
         t++;	
		return 2;
	}
    for(i=t;i<10000;i++){
    	m=1;
    	for(l=2;l<t;l++){
    		if(t%l==0){
    			m=0;
    		}
    	}
    		t++;
    		if(m==0){
    			continue;
    		}
    	if(m==1){
    		return i;
    	}
    		
    	}
    	
    }

int main() {
	int i,a,b,suma=0,l;
	for(i=0;i<1;i++){
		printf("Unesite brojeve A i B: ");
		scanf("%d%d",&a,&b);
		if(a<1){
			printf("A nije prirodan broj.\n");
			i--;
			continue;
		}
		if(a>=b){
			printf("A nije manje od B.\n");
			i--;
		}
	}
	for(i=1;i<b;i++){
		l=daj_prost();
		if(l>a && l<b){
			suma=suma+l;
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
