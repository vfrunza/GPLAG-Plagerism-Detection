#include <stdio.h>
#define B 25 

int main() {
	int i, j, k, n, a[B], b[B];
	int l=0;
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n<=0 || n>10) printf("Pogresan unos\n");
	

	}while(n<=0 || n>10);
	 
	
	for(i=0; i<n; i++){

		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &a[i], & b[i]);
		if(a[i]<0 || a[i]>19  || b[i]<0 || b[i]>19){ printf("Pogresan unos\n"); i--;}
	
    
	}
	
    for(j=0; j<20; j++){
	    for(k=0;k<20; k++){
             for(i=0; i<n; i++){
   			 if(a[i]==k && b[i]==j) {printf("*"); l++; break;}
   			 
			}
			if(l==0)printf(" ");
			else l=0;
	    }
       printf("\n");	
    }
	
	
	return 0;
}
