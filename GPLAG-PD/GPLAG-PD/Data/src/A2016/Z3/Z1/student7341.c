#include <stdio.h>

int daj_prost(){
	int i;
	static int c=1;
    do{
        c++;
        for(i=2; i<c; i++){
            if(c%i==0) break;
        }
        
    }while(c!=i);
    
	return c;	
	
}

int main(){
    int a,b,j, suma=0, prostbroj;
 	printf ("Unesite brojeve A i B: ");

 	scanf("%d%d", &a, &b);
 	while(a<=0 || b<0 || b<=a) {
 	   if (b<=a){
 			printf("A nije manje od B.\nUnesite brojeve A i B: ");
 			scanf("%d%d", &a,&b);
 		}
    	 else if (a<=0){
 			printf("A nije prirodan broj.\nUnesite brojeve A i B: ");
 			scanf("%d%d", &a,&b);
  		}
 		else if(b<0){
 			printf("B nije prirodan broj.\nUnesite brojeve A i B: ");
 			scanf("%d%d", &a,&b);
 		}
 	
 		
 	}
 	
 	for(j=1;j<=b;j++){
 	    prostbroj=daj_prost();
 	    if(prostbroj>a && prostbroj<b){
 	        suma+=prostbroj;
 	    }
 	    }
  printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma); 	   
   
   return 0;
 	    
 	}
 	
 	
 	