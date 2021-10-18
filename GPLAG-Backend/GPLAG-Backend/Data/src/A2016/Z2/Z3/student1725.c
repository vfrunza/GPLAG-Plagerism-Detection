#include <stdio.h>
int main(){

	int tacka[10][2],i,j,x=0,br,mat[20][20];
	
	printf("Unesite broj tacaka: ");
	scanf("%d", &br); 
	 while(br<=0 || br>10) {
	 	printf("Pogresan unos\n");
	 	printf("Unesite broj tacaka: ");
	 	scanf("%d",&br);
	 }
	
	for(i=0;i<br;i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d",&tacka[i][0],&tacka[i][1]);
		if(tacka[i][0]<0 || tacka[i][0]>19 || tacka[i][1]<0 || tacka[i][1]>19) {
			printf("Pogresan unos\n");
			i--; }
	}
	    
	      
	      for(i=0;i<20;i++){
			for(j=0;j<20;j++){
				int nasao=0;
				for(x=0;x<br;x++){
					if(tacka[x][0]==j && tacka[x][1]==i) { 
					printf("*");
					nasao=1; 
					
					}
				}
				if(nasao==0) printf(" ");
				
				
				
			}
			printf("\n");
		}
	return 0;
}