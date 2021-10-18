#include <stdio.h>

int main() {
    
    int n; int i, j,x,y;
    char zvjezdice[20][20];
    
    printf("Unesite broj tacaka: ");
    scanf("%d", &n);
    
    while(n<=0 || n>10) {
        printf("Pogresan unos");
        printf("\nUnesite broj tacaka: ");
        scanf("%d", &n);
    }
    for(i=0; i<20; i++){
        for(j=0; j<20; j++){
            zvjezdice[i][j]=' ';
        }
    }
    
    for(i=0; i<n; i++){
        printf("Unesite %d. tacku: ", i+1);
        scanf("%d %d", &x, &y);
        while((x<0 || x>19) || (y<0 || y>19)){
            printf("Pogresan unos\n");
            printf("Unesite %d. tacku: ", i+1);
            scanf("%d %d", &x, &y);
        }
        zvjezdice[y][x] = '*';
    }
    for(i=0; i<20; i++){
        for(j=0; j<20; j++){
            if(zvjezdice[i][j]!='*') zvjezdice[i][j]=' ';
            printf("%c", zvjezdice[i][j]);
        }
        printf("\n");
    }
   
    
    
	return 0;
}
