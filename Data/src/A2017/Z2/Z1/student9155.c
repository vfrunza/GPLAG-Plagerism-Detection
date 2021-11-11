#include <stdio.h>

int main() {
	int i,j,n,a,b,c;
	
	do {
		
	    printf ("Unesite broj N: ");
	    scanf ("%d",&n);
	
	} while (n%4!=0 || n<8);
	printf ("\n");
	a=(n/2)+1;
	b=(n/4)+(n/2)+1;
	c=(n/4)+(n/2);
	
	/* X */
	
	    for (i=1;i<=n;i++) {
	    for (j=1;j<=n;j++) {
	        if (i<=(n/2) && j<=(n/2)) {
	            if (i==j && i<=(n/4) && j<=(n/4)) {
	                printf ("\\");
	            }
	        else if (i+j==a && j>(n/4) && i<=(n/4)) {
	           printf ("/");
	       }
            else if (i==j && i>(n/4) && j>(n/4)) {
            printf ("\\");
	        }
	        else if (i+j==a && j<=(n/4) && i>(n/4)) {
	            printf ("/");
	        }
	        else { printf (" ");
	        }}
	        
	        
	        /* gornji kvadrat */
	        
	       if (i<=(n/2) && j>(n/2)) {
	       if ((i==1 || i==(n/2)) && (j==a || j==n)) {
	       printf ("+");
	        } else if ((i==1 || i==(n/2)) && ((j!=a) && j!=n)) {
	            printf ("-");
	    } else if ((i!=1 && i!=(n/2)) && (j==a || j==n)) {
	        printf ("|");
	    }
	    else { printf (" ");
	    }
	    if (j==n) {
	        printf ("\n");
	    }}
	    
	    /* donji lijevi kvadrat */
	    
	    if (i>(n/2) && j<=(n/2)) {
	        if ((i==a || i==(n)) && (j==1 || j==(n/2))) {
	            printf ("+");
	        } else if ((i==n || i==a) && (j!=1) && j!=(n/2)) {
	            printf ("-");
	        } else if ((i!=n && i!=a) && (j==1||j==(n/2))) {
	            printf ("|");
	        }
	        else { printf (" ");
	        }
	        if (j==n) {
	            printf ("\n");
	        }}
	        
	        /* donji desni + */
	   
	       
	        if (i>(n/2) && j>(n/2)) {
	            if ((i==((n/2))+(n/4)) || i==((n/2)+(n/4)+1)) {
	                if ((j==(n/2)+(n/4)) || j==((n/2)+(n/4)+1)) {
	                printf ("+");
	            } else printf ("-");
	        }
	        if (i!=b && i!=c) {
	            if (j==b || j==c) {
	                printf ("|");
	            }
	        else { printf (" ");
	        }}
	        if (j==n) {
	            printf ("\n");
	 }}
	    	}}
	        return 0; 
}