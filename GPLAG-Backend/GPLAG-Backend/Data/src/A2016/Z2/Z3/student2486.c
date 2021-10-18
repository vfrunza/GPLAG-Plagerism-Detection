#include <stdio.h>

int main() {
	
	int broj_tacaka;
	int l, i, j;
	char mat[20][20];
	int koordinata1[20], koordinata2[20];
	
	do{
	    printf("Unesite broj tacaka: ");
	    scanf("%d",&broj_tacaka);
	    if(broj_tacaka>10||broj_tacaka<=0) printf("Pogresan unos\n");
	}while(broj_tacaka<=0||broj_tacaka>10);
	
	for(l=0;l<broj_tacaka;l++){
	    printf("Unesite %d. tacku: ",l+1);
	    scanf("%d",&koordinata1[l]);
	    scanf("%d",&koordinata2[l]);
	    if(koordinata1[l]<0||koordinata1[l]>19||koordinata2[l]<0||koordinata2[l]>19){
	        printf("Pogresan unos\n");
	        l--;

	    }
	}
	
	for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            mat[i][j]=' ';
        }
     }
	for(l=0;l<broj_tacaka;l++){
	    for(i=0;i<20;i++){
	        for(j=0;j<20;j++){
	            if(koordinata1[l]==j&&koordinata2[l]==i){
	                mat[i][j]='*';
	            }
	        }
	    }
	}
	    
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%c",mat[i][j]);
		}
		printf("\n");
	}
	
	
	
	
	return 0;
}
