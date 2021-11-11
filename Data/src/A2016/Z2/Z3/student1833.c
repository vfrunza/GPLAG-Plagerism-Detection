#include <stdio.h>

int main() {
	int i, j, br, k;
	char mat[20][20];
	int nizi[10];
	int nizj[10];
	for(;;) {
	printf("Unesite broj tacaka: ");
	scanf("%d", &br);
	if(br<0 || br>10) printf("Pogresan unos\n");
	else break;
	}
	  
   for(i=0;i<br;i++) {

 		printf("Unesite %d. tacku: ",i+1);
 		scanf("%d", &nizi[i]); 
 		scanf("%d", &nizj[i]);
     }
     for(i=0;i<20;i++) {
         for(j=0;j<20;j++) {
             mat[i][j]=' ';
         }
     }
    for(i=0;i<br;i++) {
 		for(j=0;j<20;j++) {
 			for(k=0;k<20;k++) {
 			mat[nizi[i]][nizj[i]]='*'; 
 	}
 }
    }
     for(i=0;i<20;i++) {
     	for(j=0;j<20;j++) {
     		printf("%c", mat[i][j]);
     	}
     	printf("\n");
     }
	return 0;
}
