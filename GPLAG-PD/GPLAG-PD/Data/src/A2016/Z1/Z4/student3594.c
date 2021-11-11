#include <stdio.h>

int main() {
	
	int i,j,k,n;
	
	for(k=0; k<50; k++){
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	if(n<=0 || n>50){
		printf("Pogresan unos\n");
		continue;
	}
	else{
		break;
	}
	}
	
	
	if(n==1){
	printf("***");
	
	}
		
	else{
	
	
	for(i=0;i<n;i++){
		
		for(j=0;j<=(2*n+((n-2)*2));j++){
			
			if(i==0 && (j==0 || j==((2*n)-2) || j==((4*n)-4))){
				printf("*");
			}
			
            else if(i>0 && i<n-1){
            	if(j==i){
            		printf("*");
            	}
            	else if((j==((2*n)-2)-i)){
            		printf("*");
            	}
            	else if((j==((2*n)-2)+i)){
            		printf("*");
            	}
            	else if((j==((4*n)-4)-i)){
            		printf("*");
            	}
            	else{
            		printf(" ");
            	
            		
            	}
            	
            }		
		
			else if(i==n-1 &&(j==3*(n-1) || j==n-1)){
				printf("*");
			
			}
			
			
			else {
				printf(" ");
			}
		    
		    
			
		}
	
		printf("\n");
				
			
	}
}



return 0;
}