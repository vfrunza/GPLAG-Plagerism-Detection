#include <stdio.h>

int main() {
	int p,q,NekiBrN;
	
	do{
		printf("Unesite broj n: ");
		scanf("%i", &NekiBrN);
		if(NekiBrN<1 || NekiBrN>50)
		printf("Pogresan unos\n");
	}while(NekiBrN<1 || NekiBrN>50);
	
	if(NekiBrN==1) printf("***");
	else{
	    for(p=1;p<=2*NekiBrN;p++){
		    for(q=1;q<=NekiBrN;q++){
			   p!=q ? printf(" ") : printf("*");
	     	}
		    for(q=NekiBrN-1;q>1;q--){
			   p!=q ? printf(" ") : printf("*");
		    }
		    for(q=1;q<=NekiBrN;q++){
			   p!=q ? printf(" ") : printf("*");
		    }
		    for(q=NekiBrN-1;q>=1;q--){
			   p!=q ? printf(" ") : printf("*");
		    } 
		printf("\n");
	    } 
	}
	return 0;
}
