#include <stdio.h>
#include <math.h>
int main() {
	int n,i=0,c1=0,c2=0,c=0,uk=0, k = 0, br = 0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0) n=(-1)*n;
	
	i=1;
	if (n>=0 && n<10) {
		uk=0;
		printf("%d",uk);
		return 0;
	}
	
	k = n;
	while(k != 0) {
		br++;
		k = k/10;
	}
	
	k = n;
	 while (br > 1) {
		   
		    	c1=n%10;
			c2=(n/10)%10;
			c=c1-c2;
			if (c < 0) c = c*(-1);
			uk=uk+c*i;
	    i=i*10;
	     n=n/10; 
			br--;
	      	} printf("%d",uk);
	 	
	 
						

			
				
	return 0;
}
