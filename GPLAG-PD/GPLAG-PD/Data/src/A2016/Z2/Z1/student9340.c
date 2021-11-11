#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
int n,k=1,z,t,x=0;
printf("Unesite broj: ");
scanf("%d",&n);
if(n<0){
	n=abs(n);
}
   k=1;
    while(n>=10)           
    {
   
        z=n%10;         
        t=(n/10)%10;    
        x+=abs(z-t)*k; 
        k*=10;              
        n/=10;              
}
  printf("%d",x);

return 0;
}
