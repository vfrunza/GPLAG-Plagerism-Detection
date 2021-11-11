#include <stdio.h>

int main() {
	
	int redovi,kolone,sirina_kolone,i,j;
	
	printf("Unesite broj redova: ");
	scanf("%d", &redovi);
	printf("Unesite broj kolona: ");
	scanf("%d", &kolone);
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &sirina_kolone);
    
    
    for(i=0; i<=redovi*2; i++) {
         for(j=0; j<sirina_kolone*kolone+kolone+1; j++) {
		        
	        	if(j%(sirina_kolone+1)==0 && i%2==0) {
			        printf("+");
		            }
		        else if(i%2!=0 && j%(sirina_kolone+1)==0) {
		        	printf("|");
		        }
		        else if(i%2!=0) {
		        	printf(" ");
		        }
		        else printf("-");
	      }		
	      printf("\n");
    }
	return 0;
}
