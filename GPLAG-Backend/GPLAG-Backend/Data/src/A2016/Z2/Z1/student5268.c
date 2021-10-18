#include <stdio.h>
#include <math.h>

int main() {
	int x,a,b,bc=0,x1,rez=0,rez1=0,cb,i;
    printf("Unesite broj: ");
    scanf("%d",&x);
    if(x>-9 && x<9){
    printf ("0");
    	return 0;
    }
    if(x<0){
        x=x+x*(-2);   
    	}
    	x1=x;
    	while(x1!=0){
    		x1=x1/10;
    		bc++;
    	} 
    	          cb=bc-1;
               	for(i=0;i<cb;i++){
              a=x-(x/10)*10;     	
              b=(x%100-a)/10;  		
              rez1=a-b;         
             	if(rez1<0){
             		rez1=rez1+rez1*(-2);
             		}
             		rez=rez+rez1*pow(10,i);
             		x=x/10;
               	}
             	
    	printf("%d",rez);
	return 0;
}
