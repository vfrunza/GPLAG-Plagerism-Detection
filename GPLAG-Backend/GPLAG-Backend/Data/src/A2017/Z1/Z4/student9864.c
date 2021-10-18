#include <stdio.h>

int main() {
	int n,m,t,i,j;
    do{
    	printf("Unesite broj redova: ");
    	scanf("%d",&n);
    }
    while(n<=0 || n>10);
    do{
    	printf("Unesite broj kolona: ");
    	scanf("%d",&m);
    }
    while(m<=0 || m>10);
    do{
    	printf("Unesite sirinu jedne kolone: ");
    	scanf("%d",&t);
    }
    while(t<=0 || t>10);
    
    for (i=0;i<=2*n;i++) {
    	for(j=0;j<=(m*t)+m;j++){
    		if(i%2==0){
    			if(j%(t+1)==0) {
    				printf("+");
    			}
    			else {
    				printf("-");
    			}
    		} else {
    			if(j%(t+1)==0) {
    				printf("|");
    			}
    			else {
    				printf(" ");
    			}
    		}
    		
    	}
    	printf("\n");
    }
    
	
	
	return 0;
}
