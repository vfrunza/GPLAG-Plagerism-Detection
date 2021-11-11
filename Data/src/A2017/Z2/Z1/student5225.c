#include <stdio.h>

int main() {
	int n, i,j;
	
	do{
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n>0 && (n%4==0 || n==8)) break;
	}while(n%4!=0 || n!=8 || n<0);
	
	for(i=0; i<n/2; i++){
		for(j=0; j<n/2; j++){
		    if(j==i) printf("\\");
			else if(i+j== (n/2-1)) printf("/"); 
			else printf(" ");
		}
		printf("\n");
	}
	//printf("+");
   for(i=0; i<n/2; i++){
	 for(j=0; j<n/2; j++){
	    if(i==0 || i==n/2-1) printf("-"); 
	    else if(j==0 || j==n/2-1) printf("|");
	    else if(j==n/2) printf("+");
	    else printf(" ");

		}
		printf("\n");
	}
 for(i=0; i<n/2; i++){
	 for(j=0; j<n/2; j++){
	    if(i==0 || i==n/2-1) printf("-"); 
	    else if(j==0 || j==n/2-1) printf("|");
	    else if(j==n/2) printf("+");
	    else printf(" ");

		}
		printf("\n");
	}
	 for(i=0; i<n/2; i++){
	     for(j=0; j<n/2; j++){
			if()
	return 0;
}
















