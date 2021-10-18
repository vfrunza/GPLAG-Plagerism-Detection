#include <stdio.h>


int main() {
	int x=0,y=0,i=0,j=0,br_tacaka=0;
	char mat[20][20];
	
	for (i=0;i<20;i++) {
		for (j=0;j<20;j++) {
			mat[i][j]=' ';
		}
	}
    
    do {
    printf("Unesite broj tacaka: ");
    scanf("%d", &br_tacaka);
    if (br_tacaka<=0 || br_tacaka>10) printf("Pogresan unos\n");
    } while(br_tacaka<=0 || br_tacaka>10);
    

         for (i=0;i<br_tacaka;i++) {
            do {
       	    printf ("Unesite %d. tacku: ",i+1);
	        scanf("%d %d", &x,&y);
	        if (x>0 || x<19 || y>0 || y<19) 
	        break;
	        if (x<0 || x>19 || y<0 || y>19) printf("Pogresan unos\n");
	        } while(x<0 || x>19 || y<0 || y>19);
	        mat[y][x]='*';
}
	    
	 
	 for(i=0;i<20;i++) {
	 	for(j=0;j<20;j++) {
	 		printf("%c", mat[i][j]);
	 }
	 printf("\n");
	 }
	 
	 
return 0;
}