#include <stdio.h>

int main()
{
    int matrica[20]
    [20]= {{0}},i,j,brtac,pom;
    while(1) {
        printf("Unesite broj tacaka: ");
        scanf("%d", &brtac);
        /*Ucitava broj tacki*/
        if((brtac>10) || (brtac<=0)){
            printf("Pogresan unos\n");
            continue;
        }
        break;
    }
    for(pom=0; pom<brtac; pom++) {
        while(1){
        printf("Unesite %d. tacku: ", pom+1);
        scanf("%d%d", &i,&j);
        if(i>19 || i<0 || j>19 || j<0){
            printf("Pogresan unos\n");
            continue;
        }
        break;
        }
        /*Cita kordinate i upisuje u matricu*/
        if(i>19 || i<0 || j>19 || j<0)
            pom=pom-1;
        else {
            matrica [j][i]=1;
            /*Prvo se upisuje kolona pa onda red*/
        }
    }
    for(i=0; i<20; ++i) {
        for(j=0; j<20; ++j) {
            if(matrica [i][j]==1)
                printf("*");
            if(matrica[i][j]==0)
                /*Ispisuje matricu :D*/
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
