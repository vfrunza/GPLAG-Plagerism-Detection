#include <stdio.h>

int main() {
	int n=0, x, prva=0, p1, ostale, p2, p3=1;
	while (n<1 || n>50) {
		    printf("\nUnesite broj n: ");
		    scanf("%d", &n);
		    if (n<1 || n>50)
		            printf("Pogresan unos");
	}
	
	for (x=1; x<=n; x++) {
		    
		    /* --- PRVA LINIJA --- */
		    
		    if (x==1) {
		    	    prva=2*n-3;
		    	    printf("*");
		    	    for (p1=1; p1<=prva; p1++)
		    	            printf(" ");
		    	    printf("*");
		    	    for (p1=1; p1<=prva; p1++)
		    	            printf(" ");
		    	    printf("*\n");
		    }
		    
		    if (n==1)
		            break;
		            
		    /* --- DRUGA LINIJA --- */
		    
		    if (x!=1 && x!=n) {
		    	    ostale=x-1;
		    	    for (p2=1; p2<=ostale; p2++)
		    	            printf(" ");
		    	    printf("*");
		    	    prva=prva-2;
		    	    for (p2=1; p2<=prva; p2++)
		    	            printf(" ");
		    	    printf("*");
		    	    for (p2=1; p2<=p3; p2++)
		    	            printf(" ");
		    	    printf("*");
		    	    p3+=2;
		    	    for (p2=1; p2<=prva; p2++)
		    	            printf(" ");
		    	    printf("*\n");
		    }
		    
		    /* --- ZADNJA LINIJA ---*/
		    
		    if(x==n) {
		            ostale=x-1;
		            for (p2=1; p2<=ostale; p2++)
		                    printf(" ");
		            printf("*");
		            for (p2=1; p2<=p3; p2++)
		                    printf(" ");
		            printf("*");
		            printf("\n");
		    }
	}
	return 0;
}