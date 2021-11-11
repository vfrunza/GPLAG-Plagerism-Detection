#include <stdio.h>

int main() {
    int broj_tacaka, x[20], y[20],i , j, k, pronadjena;
    do { 
    	printf("Unesite broj tacaka: ");
    	scanf("%d", &broj_tacaka);
    	if(broj_tacaka<=0 || broj_tacaka>10) 
    		printf("Pogresan unos\n");
    } while (broj_tacaka<=0 || broj_tacaka>10);
    for(i=0; i<broj_tacaka; i++) {
    	do { 
		  	printf("Unesite %d. tacku: ", i+1);
    		scanf("%d %d", &x[i], &y[i]);
    		if(x[i]<0 || x[i]>19 || y[i]<0 || y[i]>19) { 
    			printf("Pogresan unos\n");
    		}
    	} while (x[i]<0 || x[i]>19 || y[i]<0 || y[i]>19);
    }
    for(i=0; i<20; i++) {
    	for(j=0; j<20; j++) {
    		pronadjena = 0;
    		for(k=0; k<broj_tacaka; k++)
    			if(x[k] == j && y[k] == i) {
    				printf("*");
    				pronadjena = 1;
    				break;
    			}
    			else continue;
    		if(!pronadjena) printf(" ");
    	}
    	printf("\n");
    }
	return 0;
}
