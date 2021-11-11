#include <stdio.h>
#define brojel 20

int main() {
    int koord_sistem [brojel][brojel]={0};
    int x_koord;
    int y_koord;
    int brojtacaka;
    int i;
    do{
    printf("Unesite broj tacaka: ");
    scanf("%d",&brojtacaka);
    if(brojtacaka < 1 || brojtacaka > 10) printf("Pogresan unos\n");
    }
    while(brojtacaka < 1 || brojtacaka > 10);
    
    for(i=0;i<brojtacaka;i++){
        printf("Unesite %d. tacku: ",i+1);
        scanf("%d %d",&x_koord,&y_koord);
        if(x_koord<0 || x_koord>19 || y_koord<0 || y_koord>19){ printf("Pogresan unos\n"); i--; continue;}
        koord_sistem[x_koord][y_koord]=1;
    }
    
    for(x_koord=0;x_koord<20;x_koord++){
        for(y_koord=0;y_koord<20;y_koord++){
            if(koord_sistem[y_koord][x_koord]==1) printf("*");
            else printf(" ");
        }
        printf("\n");
    }

return 0;
}