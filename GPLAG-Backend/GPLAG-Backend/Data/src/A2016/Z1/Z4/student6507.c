#include <stdio.h>

int main() {
	int n, i, j, k, l, m, o, p, z, y;
pocetak:
	
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	if(n<=0 || n>50){
		printf("Pogresan unos\n");
		goto pocetak;}

	else{
		if(n==1){
			printf("*");
	    	for(i=1; i<=2*n-3; i++){
	        	printf(" ");
	    	}
	    	printf("*");
	    
	    	for(j=1; j<=2*n-3; j++){
	        	printf(" ");
	    	}
	    	printf("*\n");
	}
		
if (n>1){
	printf("*");
	    	for(i=1; i<=2*n-3; i++){
	        	printf(" ");
	    	}
	    	printf("*");
	    
	    	for(j=1; j<=2*n-3; j++){
	        	printf(" ");
	    	}
	    	printf("*\n");
	    	
		 for(k=1; k<=n-2; k++){
	        for(l=1; l<=k; l++){
	            printf(" ");
	        }
	        printf("*");
	        for(m=1; m<=2*(n-k)-3; m++){
	            printf(" ");
	        }
	        printf("*");
	        
	       if(l==1){
	           printf(" ");
	       }
	       else{
	           
	        for(o=1; o<=2*k-1; o++){
	            printf(" ");
	            }
       	 	}
	        
	        printf("*");
	        
	        for(p=1; p<=2*(n-k)-3; p++){
	            printf(" ");}
	        
	        printf("*\n");
	        
	    }
	 
	for(z=1; z<=n-1; z++){
		printf(" ");
	}
	printf("*");
	
	for(y=1; y<=2*n-3; y++){
		printf(" ");
	}
	printf("*");
	
	}
}
	return 0;
}
