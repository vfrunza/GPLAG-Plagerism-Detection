#include <stdio.h>

int main() {
int i,j,k,n,niz[20][20]={{0,0}};
do{    
printf("Unesite broj tacaka: ");
scanf("%d",&n);
}while(n<0 && n>=10);
    for(k=0; k<n; k++){
    do{
        printf("Unesite %d. tacku: ",k+1);
        scanf("%d %d",&i,&j);
        if(i<0 || i>19 || j<0 || j>19){
            printf("Pogresan unos\n");
        }
        }while(i<0 || i>19 || j<0 || j>19);
        niz[i][j]=1;
    }
        for (i=0; i<20; i++){
            for (j=0; j<20; j++){
                if(niz[j][i]==1){
                    printf("*");
                }else if(niz[j][i]==0){
                    printf(" ");
                }
        }printf("\n");
            }
	return 0;
}
