#include <stdio.h>

int main(){
    int a[20][20],n,i,j,x,y;
    for(i=0;i<20;i++)
    for(j=0;j<20;j++)
    a[i][j]=' ';
    
    do{
    printf("Unesite broj tacaka: ");
    scanf("%d",&n);
    if(n<1 || n>10){
    printf("Pogresan unos\n");
    }
    else
    break;
    }while(1);
    for(i=1;i<=n;i++){
        printf("Unesite %d. tacku: ",i);
        scanf("%d %d",&x,&y);
        if(x<0 || y<0 || x>19 || y>19){
        printf("Pogresan unos\n");
        i--;
        }
        else
        a[x][y]='*';
    }
    for(i=0;i<20;i++){
    for(j=0;j<20;j++){
    
    printf("%c",a[j][i]);
    }
    printf("\n");
    }
    return 0;
}