#include <stdio.h>
#include <math.h>

int main() {
	int n, x, a, b, c;
	int i=10;
	int rez=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	

	
	
	
	if(n>-10 && n<10) printf("0");
	else
	{
		x=n;
		if(n<0)
		  x=fabs(n);
	
	  a=x%10;
	  x/=10;
	  while(x>0){
      b=x%10;
      c=a-b;
      if(c<0) c=fabs(c);
      if(rez==0)
        rez+=c;
      else{
      	
      	rez+=(c*i);
      	i*=10;
      }  
      a=b;
      x/=10;
      
	}  
		  
	}
	
	printf("%d", rez);
	
	
	
	
	
	
	return 0;
}
