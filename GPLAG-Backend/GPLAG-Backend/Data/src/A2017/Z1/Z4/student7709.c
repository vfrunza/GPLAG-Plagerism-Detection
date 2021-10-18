#include <stdio.h>

int main() {
	int r,k,s,i,j,l,m,n,z,v;
	do{ printf("Unesite broj redova: ");
		scanf("%d",&r);
	} 
	while(r<=0 || r>10);
	
	while(k<=0 || k>10);
	do{	printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&s);
	} 
	while(s<=0 || s>10);
	
	for(i=0; i<r; i++){
    	for(j=0; j<k; j++){
    		printf("+");
    	for(l=0; l<s; l++)
    		printf("-");
    	}
   		printf("+\n");
    
		for(m=0; m<k; m++){
    		printf("|");
    	for(n=0; n<s; n++)
			printf(" ");
		}
    	printf("|\n");
   }
    
    for(z=0; z<k; z++){
    	printf("+");
    for(v=0; v<s; v++)
    printf("-");
    }
      printf("+\n");
	return 0;
}
