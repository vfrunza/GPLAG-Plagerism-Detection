#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int x,i,n,c,z,y,b,NOVI_BROJ,temp,O;
	int w;
	b=0;
	printf("Unesite broj: ");
	scanf("%d", &x);
	 x=abs(x);
	if(x%10==x) {printf("0");
	return 0;}
	
	temp=x;
      do {
		w=temp/10;
		b++;
		
		temp=temp/10;
		
	}	while(w!=0);
	n=b;
	NOVI_BROJ=0;
	
	
	for (i=0; i<b; i++){
		
		c=x%10;
		z=x/10;
		y=z%10;
		n=abs(c-y);
		
		NOVI_BROJ=NOVI_BROJ + n*pow(10,i);
		
		
       x=x/10;
       	
       if(x%10==x){ 
       break;}
       
       
      
	}
	printf("%d", NOVI_BROJ);
	return 0;
}
