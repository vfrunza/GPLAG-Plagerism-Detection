#include <stdio.h>
#include <stdlib.h>
int main() {
	int x,y=0,z=0,t,u=0,brojac=0,zadnjaipredzadnjacifraiste=0;
	printf("Unesite broj: ");
	scanf("%d",&x);
	if (x<0) x=abs(x);
	if (x>0 && x<10) printf ("0");
	else {
		while (x>0){
		brojac++;
		y=x%10;
		x=x/10;
	    if (x!=0) {
	    	z=z*10;
	    	z=z+ abs (y-(x%10));
	    	if(brojac==1)
	    	{
	    		if(y==x%10)
	    			zadnjaipredzadnjacifraiste=1;
	    	}
	    }
		
	}
	while (z>0){
		t=z%10;
	    z=z/10;
	    u=u*10; u=u+t; 
	    
	}
	if(zadnjaipredzadnjacifraiste==1) u=u*10;
	printf("%d",u);
	}
	
	
	
	return 0;
}
