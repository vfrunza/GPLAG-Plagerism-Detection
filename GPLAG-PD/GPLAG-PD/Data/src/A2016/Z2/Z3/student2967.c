#include <stdio.h>

int main(){
    char mat[20][20];
    int x=0,y=0,n,i,j;
    
    for(i=0; i<20; i++){
        for(j=0; j<20; j++){
            mat[i][j]=' ';
        }
        
    }
    do{
        printf("Unesite broj tacaka: ");
        scanf("%d",&n);
        if(n<=0 || n>10){
            printf("Pogresan unos\n");
        }
    } while(n<=0 || n>10);
    
    for(i=0; i<n; i++){
        do{
            printf("Unesite %d. tacku: ",i+1);
            scanf("%d %d",&y,&x);
            if(y<0 || x<0 || y>=20 || x>=20){
                printf("Pogresan unos\n");
            }
            else{
                mat[x][y]='*';
            }
            
        } while(y<0 || x<0 || y>19 || x>19);
    }
    
    for(i=0; i<=19; i++){
        for(j=0; j<=19; j++){
            printf("%c",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}




