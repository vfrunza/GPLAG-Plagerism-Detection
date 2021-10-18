#include <stdio.h>

int main() {
    int N;
    int i,j;
    
    do {
    	printf("Unesite broj N: ");
    	scanf("%d", &N);
    	if(N%4!=0 || N==4 || N<8) {
    		printf("Neispravno N!\n");
    	} else 
    	 	break;
    	
    } while(N%4==0 || N==4 || N<8);
    printf("\n");
    
    /*Unosim karaktere pomocu dvije for petlje kojima cu prolaziti kroz crteze*/
    
    for(i=0; i<N; i++) {
    	for(j=0; j<N; j++) {
    		/*Ispisivanje X-a u gornjem lijevom uglu..*/
    		if(j==N/2-i-1 && i<N/2 && j<N/2) {
    			printf("/");
    		}
    		else if(i==j && i<N/2 && j<N/2) {
    			printf("\\");
    		} /*Ispis kvadrata u gornjem desnom uglu*/
    		else if((i==0 && (j>N/2 && j<N-1)) || (i==N-1 && (j<N/2-1 && j>0))) {
    			printf("-");
    		} /*Fale minusi s druge strane, dalje uslovima..*/
    		else if((i==N/2-1 && (j>N/2 && j<N-1)) || (i==N/2 && (j<N/2-1 && j>0))) {
    			printf("-");
    		} /*Dalje mi trebaju plusici, uslovi za ispis +*/
    		else if((i==0 && (j==N/2 || j==N-1)) || (i==N/2 && (j==0 || j==N/2-1))) {
    		    printf("+");
    		} /*jos plusica */
    		else if((i==N/2-1 && (j==N/2 || j==N-1)) || (i==N-1 && (j==0 || j==N/2-1))) {
    		    printf("+");
    		} /*Od karaktera nedostaje jos | za znak u donjem desnom uglu i za stranice kvadrata */
    		else if((j==N/2 && (i>0 && i<N/2-1)) || (j==0 && (i>N/2 && i<N-1))) {
    		    printf("|");
    		} /*jos maloo*/
    		else if((j==N-1 && (i>0 && i<N/2-1)) || (j==N/2-1 && (i>N/2 && i<N-1))) {
    		    printf("|");
    		}
    		
    		/*Treba namjestiti gdje tacno ide koji znak ide..*/
    		/*za minuse*/
    		else if((i==(N/2)+(N/2)/2 || i==(N/2)+(N/2)/2-1) && j<N && j>N/2-1 && j!=(N/2)+N/4-1 && j!=(N/2)+(N/4)) {
    		    printf("-");
    		} else if(i>N/2-1 && (j==(N/2)+(N/2)/2 || j==(N/2)+(N/2)/2-1) && i<N && i!=(N/2)+N/4-1 && i!=(N/2)+(N/4) ) {
    		    printf("|");
    		}
    		/*samo jos pluseve popraviti */
    		else if((i==(N/2)+(N/4) || i==(N/2)+(N/4)-1) && (j==N/2+(N/4) || j==N/2+(N/4)-1 || j==N/2+(N/4)-2)) {
    		    printf("+");
    		}
    		else {
    		    printf(" ");
    		}
    		
    		
    	}printf("\n"); 
    	
    	
    }
	return 0;
}
