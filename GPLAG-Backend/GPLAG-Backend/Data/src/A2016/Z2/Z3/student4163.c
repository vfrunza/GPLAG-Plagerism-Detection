#include <stdio.h>
#include<stdlib.h>

int main() {
    int i,j;
    char mat[20][20];
    int x,y;
    int broj_tacaka;
    while(1){
        printf("Unesite broj tacaka: ");
        scanf("%d", &broj_tacaka);
        if(broj_tacaka<=0 || broj_tacaka>10)  printf("Pogresan unos\n");
        else break;
    }
    for(i=0;i<20;i++)
        for(j=0;j<20;j++)
            mat[i][j]=' ';
        
    
    for(i=0;i<broj_tacaka;i++){
            printf("Unesite %d. tacku: ", i+1);
            scanf("%d %d", &x, &y);
            if(x<0 || y<0 || x>19 || y>19){
                printf("Pogresan unos\n");
                i--;
                continue;
            }
        mat[x][y]= '*';
    }
    for(j=0;j<20;j++){
        for(i=0;i<20;i++){
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
