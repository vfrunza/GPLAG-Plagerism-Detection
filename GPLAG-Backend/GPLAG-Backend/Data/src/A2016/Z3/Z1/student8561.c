#include <stdio.h>

int IFPROST(int prost_br){
    int i,n,r;
    n=1;
    i=2;
    for(i=2;i<prost_br;i++){
        if(prost_br%i==0){
            n=0;
            break;
        }
    } 
    if(n==1) r=1;
    else r=0;
    return r;
}

int Daj_prost(){
    static int prost_br=2;
    while(IFPROST(prost_br)==0){
        prost_br++;
    }
    prost_br++;
    return prost_br-1;
}

int main() {
	int a,b,suma,prost,i;
	suma=0;
	
	do{
	    printf("Unesite brojeve A i B: ");
	    scanf("%d %d",&a,&b);
	    if(a>=b) printf("A nije manje od B.\n");
	    else if(a<=1) printf("A nije prirodan broj.\n");
	    else if(b<=1) printf("B nije prirodan broj.\n");
	} while (a>=b || b<=1 || a<=1);
	
	while((prost=Daj_prost())<=a)
	suma=0;
	
	for(i=a+1;i<b;i++){
	    if(prost>=b) break;
	    suma+=prost;
	    prost=Daj_prost();
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	
	return 0;
}
