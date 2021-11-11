#include <stdio.h>

int main() {
	int n=0, i, x=20, y=20, a, b;
	char ko_sistem[20][20];
	for(a=0; a<20; a++)
	         for(b=0; b<20; b++)
	                  ko_sistem[a][b]=' ';
	while(n<1 || n>10) {
		printf("\nUnesite broj tacaka: ");
		scanf("%d", &n);
		if(n<1 || n>10)
		       printf("Pogresan unos\n");
    }
    for(i=1; i<=n; i++){
    	while (x>19 || y>19 || x<0 || y<0) {
    		printf("Unesite %d. tacku: ", i);
    		scanf("%d %d", &x, &y);
    		if (x>19 || y>19 || x<0 || y<0)
    		         printf("Pogresan unos\n");
    		        
    }
    ko_sistem[x][y]='*';
    x=20, y=20;
    }
    for(a=0; a<20; a++)
             for(b=0; b<20; b++)
             {
             	if(b==0 && a!=0) printf("\n");
             	printf("%c", ko_sistem[b][a]);
             }
	return 0;
}