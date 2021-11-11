#include <stdio.h>

int main() {
	/*printf("Zadaća 1, Zadatak 4");*/
    int br_redova, br_kolona, sirina;
    int i,j;
    do{
    	printf("Unesite broj redova: ");
    	scanf("%d",&br_redova);
     }while(br_redova<1 || br_redova>10);
    
    do{
    	printf("Unesite broj kolona: ");
    	scanf("%d",&br_kolona);
    }while(br_kolona<1 || br_kolona>10);
    
    do{
    	printf("Unesite sirinu jedne kolone: ");
    	scanf("%d",&sirina);
    }while(sirina<1 || sirina>10);
    
    for(i=0; i<(3+(br_redova-1)*2); i++){
        for(j=0; j<((sirina+2)+(br_kolona-1)*(sirina+1)); j++){
           if(i%2==0 && j%(sirina+1)==0) printf("+");
           else if(j%(sirina+1)==0) printf("|");
           else if(i%2==0) printf("-");
           else  printf(" ");
            
        }
        printf("\n");
    }
    
    
    
    
    
    
   
    	

	return 0;
}
