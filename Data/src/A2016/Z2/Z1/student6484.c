#include <stdio.h>

int main() {


   int a,b,c, brojac,k,z,s;
   long int broj,rez,m,n;
    rez=0; 
    printf("Unesite broj: "); 
    scanf("%ld", &broj);
    
    
    

    brojac=0;
    m=broj;
   while(m>0){
       k=m%10;
       brojac++;
       m=m/10;
       }
    if(brojac==1) printf("0");
    
    
    
    
    
    else {
     
     
     
     if(broj<0) 
     broj=broj*(-1);
  
  
  
   z=broj%10;
  broj=broj/10; 
   s=broj%10; 
   broj=broj/10; 
  a=z;
  b=s;
  

  
   do {
       c=a-b; 
      if(c<0)
      c=c*(-1); 
    
     
   	rez=( rez+c)*10;
   	
   	a=b; 
   	b=broj%10; 
   	broj=broj/10; 
   
   }while(broj>0);

   
    c=a-b; 
      if(c<0) c=c*(-1); 
    
    rez= (rez+c)*10;
   	a=b; 
   	b=broj%10; 
   	broj=broj/10; 
 
 
   	n=0;
   	while(rez>0){
   	    n=n*10+ rez%10;
   	    rez=rez/10;
   	}
   
   	if(z==s) n=n*10;
   	
  printf("%ld",n);
    }
	return 0;
}
