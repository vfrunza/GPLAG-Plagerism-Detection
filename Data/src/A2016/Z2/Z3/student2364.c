#include <stdio.h>
#define MAX 20
int main (){

int mat[MAX][MAX]={0};
int i,j,x,y,w;
do{
    printf("Unesite broj tacaka: ");
    scanf("%d", &w);
    if(w>10 || w<=0)
        printf("Pogresan unos\n");
}
    while(w<1 || w>10);
    
for(i=0; i<w; i++){
    printf("Unesite %d. tacku: ", i+1);
    scanf("%d %d",&x, &y);
    if(x>=MAX || x<0 || y>=MAX || y<0){
    printf("Pogresan unos\n");
    i-=1;
    }
    else 
    mat[x][y]=1;
}
for(i=0; i<MAX; i++){
    for(j=0; j<MAX; j++){
        if(mat[j][i]==1)
        printf("*");
        else
        printf(" ");
    }
    printf("\n");
}
        

    return 0;
}
