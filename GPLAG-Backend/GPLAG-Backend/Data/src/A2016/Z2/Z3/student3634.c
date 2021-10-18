#include <stdio.h>

int main() {
	
	char mat[20][20];
	int i, j, a, b, br_tacaka;
	
	for(i=0; i<20; i++) {
	    for(j=0; j<20; j++) {
	        mat[i][j]=' ';
	    }
	}
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d", &br_tacaka);
	if(br_tacaka<=0 || br_tacaka>10) printf("Pogresan unos\n");
	}while(br_tacaka<=0 || br_tacaka>10);
	

	
	for(i=0; i<br_tacaka; i++) {
		do{
	    printf("Unesite %d. tacku: ", i+1);
	    scanf("%d %d", &a, &b);
	    if(a<0 || a>19 || b<0 || b>19) printf("Pogresan unos\n");
		}while(a<0 || a>19 || b<0 || b>19);
	    mat[b][a]='*';
	}
	
	for(i=0; i<20; i++) {
	    for(j=0; j<20; j++) {
	        printf("%c", mat[i][j]);
	    }
	    printf("\n");
	}
	return 0;
}
