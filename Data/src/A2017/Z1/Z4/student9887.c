#include <stdio.h>

int main() {
	int br,bk,sk,i,j;
	int k,s;
	
	do {
		printf("Unesite broj redova: ");
	    scanf("%d", &br);
	} while(br<=0 || br>10);
	do {
	    printf("Unesite broj kolona: ");
	    scanf("%d", &bk);
	} while(bk<=0 || bk>10);
	do {
	    printf("Unesite sirinu jedne kolone: ");
	    scanf("%d", &sk);
	} while(sk<=0 || sk>10);
	
	    k=sk*bk+bk+1;
	    s=2*br+1;
	    
	    for(i=0; i<s; i++){
	    	for(j=0; j<k; j++){
	    		if((i==0 || i%2==0) && (j==0 || j%(sk+1)==0)){
	    			printf("+");
	    		} else if (i%2!=0 && (j==0 || j%(sk+1)==0))
	    			printf("|");
	    	    } else if ((i==0 || i%2==0) && (j%(sk+1)!=0)){
	    	    	printf("-");
	    	    } else {
	    	    	printf(" ");
	    	    }
	    } printf("\n");
	   }

	return 0;
}
