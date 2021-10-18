#include <stdio.h>

int main() {
	int n,i,j,k,l,o,s,m,h,g,d,t,p;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	while (n<=0 || n>50)
    { printf("Pogresan unos \n");
	  printf("Unesite broj n: ");
	  scanf("%d",&p);
		n=p;
	}
	
	if(n==1) printf("***");
	
	
	else{
	
	printf("*");
	for(h=1; h<=2*(n-1)-1; h++) printf(" ");
	printf("*");
		for(g=1; g<=2*(n-1)-1; g++) printf(" ");
		printf("*");
	printf("\n");
	
	
	for(i=2; i<=n-1; i++){
		for(j=1; j<i; j++) {printf(" "); 
		}
		printf("*");
		
		for(l=1; l<2*(n-i); l++) {printf(" "); 
		}
		 printf("*");
		
		for(m=1; m<2*i-2; m++) {printf(" "); 
		}
		printf("*");
		for(o=1; o<2*(n-i); o++) {printf(" "); 
		}
		printf("*");
		
		printf("\n");
	}
	
	
	for(d=1; d<=n-1; d++) printf(" ");
	printf("*");
		for(t=1; t<=2*i-3; t++) printf(" ");
		printf("*");
	printf("\n");	
	
	}
	
	return 0;
}
