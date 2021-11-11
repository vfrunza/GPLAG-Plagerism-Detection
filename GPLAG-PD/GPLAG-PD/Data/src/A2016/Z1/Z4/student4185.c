#include <stdio.h>

int main() {
      int n,a,b,c,d,f,e,g,h,i,j,k,l,m,t,o,p,r,v,x,y,q;
     
      do{ printf("Unesite broj n:");
      
            scanf("%d", &n);
            if (n<=0 || n>50) { printf(" Pogresan unos\n");
                  
            }
            
      } while(n<=0 || n>50);
      
  if (n==1) { printf(" ***"); 
        
  }else {
  if (n==2) {   h=2*n-3-2;
            l=1;
            c=1;
            x=n-2;
            r=2*n-5;
      	printf(" *");
      	for (j=1; j<=(2*n-3); j++) { printf(" "); 	}
      	printf("*");
      	for (j=1; j<=(2*n-3); j++) { printf(" "); 	}
      	printf("*");
      	printf("\n");
      	
      	
      	
      	for(j=1; j<=(n-2); j++) {
      	      
      	for(j=1; j<=l; j++) { printf(" "); } l++; printf("*");
      	for(p=1; p<=h; p++) { printf(" ");} h=h-2; printf("*");
      	for(t=1; t<=c; t++) {printf(" ");} c=c+2; printf("*");
      	for(y=1; y<=r; y++) {printf(" ");} r=r-2; printf("*");
      printf("\n");}
      
      for(g=1; g<=(n-1); g++) {printf(" ");} printf("*");
      for(v=1; v<=(2*n-3); v++) {printf(" ");} printf("*");
        
  } else {
  

            h=2*n-3-2;
            l=1;
            c=1;
            x=n-2;
            r=2*n-5;
      	printf(" *");
      	for (j=1; j<=(2*n-3); j++) { printf(" "); 	}
      	printf("*");
      	for (j=1; j<=(2*n-3); j++) { printf(" "); 	}
      	printf("*");
      	printf("\n");
      	
      	
      	
      	for(j=0; j<=(n-1); j++) {
      	      
      	for(j=1; j<=l; j++) { printf(" "); } l++; printf("*");
      	for(p=1; p<=h; p++) { printf(" ");} h=h-2; printf("*");
      	for(t=1; t<=c; t++) {printf(" ");} c=c+2; printf("*");
      	for(y=1; y<=r; y++) {printf(" ");} r=r-2; printf("*");
      printf("\n");}
      
      for(g=1; g<=(n-1); g++) {printf(" ");} printf("*");
      for(v=1; v<=(2*n-3); v++) {printf(" ");} printf("*");
  }
      
  }
      
	return 0;
}
