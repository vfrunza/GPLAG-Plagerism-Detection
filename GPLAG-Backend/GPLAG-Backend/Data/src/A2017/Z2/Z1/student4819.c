#include <stdio.h>

int main() {
	int a=0,b=0,i,j,n=0;

	
	printf("Unesite stranice pravougaonika a,b: ");     /* PRAVOUGAONIK U DESNIM COSKU*/
	scanf("%d", &a);
	
	 for(i=0;i<n;i++){
          for(j=0;j<i+1;j++){
              printf("\\");
          }
          printf("\n");
          
      }
	
	
	if(a==1 && b==1){
		printf("+");
	}
    else if(a==1 && b!=1){
    	printf("+\n");
    	for(j=0;j<b-2;j++){
    		printf("|\n");
    	}
    	printf("+\n");
    }
    else if(b==1 && a!=1){
    	printf("+");
    	for(i=0;i<a-2;i++){
    		printf("-");
    	}
    	printf("+\n");
    }
    else{
        printf("+");
        for(i=0;i<a-2;i++){
            printf("-");
        }
        printf("+\n");
        for(i=0;i<b-2;i++){
         printf("|");
         for(j=0;j<a-2;j++){
         printf(" ");
         }
         printf("|\n");
        
    }
    printf("+");
    for(i=0;i<a-2;i++){
        printf("-");
    }
    printf("+\n");
    }
	
	
	return 0;
}
