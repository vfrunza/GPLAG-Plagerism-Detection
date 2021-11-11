#include <stdio.h>

    int daj_prost (){
        int i, prost=1;
        static int a=1;
       
        
        while(1){ 
            a++;
           
            if(a==2) {
            return a;
            }else {
            for (i=2; i<a; i++){
                if (a%i==0){ 
                    prost=0;
                    break;}
            }
        }
        if(prost){return a;}
        else{
            prost=1;
        }
        
    }

}




int main() {
	
	int a,b,c=0,suma=0;
	
	do{
	
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &a, &b);
	
	if( a < 1  ){ 
	    printf("A nije prirodan broj.\n");
	}
	else if( b <= a ){
	    printf("A nije manje od B.\n");
	}

	 
	}while(a<1 || a>=b);
	
	
	
    while(c<b){

	c=daj_prost();
	if(c>a && c<b){
        suma+=c;
    }
	
}

	printf("Suma prostih brojeva izmedju %d i %d je %d.", a,b,suma);
	
	
	
	
	
	
	
	
	
	return 0;
}
