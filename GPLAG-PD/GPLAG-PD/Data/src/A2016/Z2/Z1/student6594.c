#include <stdio.h>
#include <stdlib.h>
int main() {
	
	int n,k=1,c1,c2,raz=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	
    if(n<0)
    n=abs(n);
     
   while(n>=10){
    
   c1=n%10;
   c2=(n/10)%10;
   raz+=abs(c1-c2)*k;
    k*=10;
    n/=10;
   }
  
   printf("%d",raz);
	    
	    
	
   
    return 0;
 }
