#include <stdio.h>

int main() {
    
    int i,j,r,k,l;
     do{
    printf("Unesite broj redova: ");
    scanf("%d", &r);}while (r<=0 || r>10);
    do{
    printf("Unesite broj kolona: ");
    scanf("%d", &k);}while (k<=0 || k>10);
    do{
    printf("Unesite sirinu jedne kolone: ");
    scanf("%d", &l);}while (l<=0 || l>10);
   
    for(i=0; i<=r*2; i++){
     if(i%2==0) {   
         for(j=0; j<=k*(l+1);j++){
            if(j%(l+1)==0) printf("+"); else printf("-");
        }
        printf("\n");
         
     }
     else{for(j=0; j<=k*(l+1);j++){
            if(j%(l+1)==0) printf("|"); else printf(" ");
        }
        printf("\n");
         
     }
        
    }

	return 0;
}
