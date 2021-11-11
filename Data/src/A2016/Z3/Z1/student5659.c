#include <stdio.h>

 int daj_prost(){
     static int i=1;
     int j;
     i++;
     
     for(j=2;j<i;j++){
        if(i%j==0) {
            i++; j=2;
            
        }
       }
       
     
        return i;
 }

int main() {
    int i,y,a,b,suma=0;
    do {
    printf("Unesite brojeve A i B: ");
    scanf("%d %d",&a,&b);
    if(a<=0) printf("A nije prirodan broj.\n");
    else if(a>b || a==b) printf("A nije manje od B.\n");
    } while(a<=0 || b<=0 || a>b || a==b);
    for(i=0; ;i++){
        y=daj_prost();
        if(y>=b) break;
        else if(y<=a) continue;
        suma=suma+y;
        
    }
    
    
    printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
    
   
	return 0;
}
