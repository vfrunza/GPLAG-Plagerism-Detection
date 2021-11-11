#include <stdio.h>
#define v 20
#define s 20

int main() {
    
    int i,j,g,h,n;
    char k[v][s]={0};
    do{
    printf("Unesite broj tacaka: ");
    scanf("%d",&n);
    if(n<=0 || n>10) printf("Pogresan unos\n");} while(n<=0 || n>10);
   
        for(i=0;i<n;i++){
            printf("Unesite %d. tacku: ",i+1);
            scanf("%d %d",&h,&g);
            if(g<0 || g>19 || h<0 || h>19){
                printf("Pogresan unos\n");
                i--;}
            else k[g][h]='*';
           }
        
      for(i=0;i<v;i++){
        for(j=0;j<s;j++){
            if(k[i][j]=='*') printf("%c", k[i][j]);
            else printf(" ");
        }
        printf("\n");}
    
	return 0;
}
