#include <stdio.h>

int main() {
	float a1, b1, a2, b2, x, y, D, R;
		printf("Unesite a1,b1,a2,b2: ");
		scanf("%f,%f,%f,%f", &a1, &b1, &a2, &b2);
		 
		 
		 	if((a1==a2)&&(b1!=b2)) {
			printf("Paralelne su");	}
		
			else if(b1==b2) {
				printf("Poklapaju se");
				}
			
		  
				if((a1!=a2) && (b1!=b2)) {
				D=b2-b1;
				R=a1-a2;
				x= D/R;
	  	        y= a1*x + b1; 
	  	        
	  	        printf("Prave se sijeku u tacci (%.1f,%.1f)", x,y);
			}
			return 0;
			
			
				
			
			
			
			

 }