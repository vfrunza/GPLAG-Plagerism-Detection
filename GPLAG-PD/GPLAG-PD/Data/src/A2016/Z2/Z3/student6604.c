#include <stdio.h>

int main(){
    char mat[20][20];
    int i, j, x, y, t;
    for(i=0; i<20; i++){
        for(j=0;j<20;j++){
            mat[i][j]= ' ';
        }
    }
    
    for(;;){
        printf("Unesite broj tacaka: ");
        scanf("%d", &t);
        if(t<1||t>10) printf("Pogresan unos\n");
        else break;
    }
    for(i=0; i<t; i++){
        printf("Unesite %d. tacku: ", i+1);
        scanf("%d %d", &x, &y);
        if(x < 0 || x > 19 || y < 0 || y > 19) {
			printf("Pogresan unos\n");
			i--;
			continue;
			}
			mat[y][x]='*';
}

for(i=0; i<20; i++){
    for(j=0; j<20; j++){
        printf("%c", mat[i][j]);
    }
    printf("\n");
    
}
return 0;
}