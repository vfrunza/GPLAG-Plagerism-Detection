#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	 
      int n,a,b,y=0,x;
	  int brojac=0;
	  printf("Unesite broj: ");
	  scanf("%d",&n);
	  
	  
	  if(n<0)
	  n=abs(n);
	  if(n/10==0)
	  printf("0");
	  else {

	while(n/10!=0){
	   
		a=n%10;
		n=n/10;
		b=n%10;
		x=abs(a-b);
	    y=y+pow(10, brojac)*x;
	    brojac++;
	}
		printf("%d",y);

} 	
	return 0;
}