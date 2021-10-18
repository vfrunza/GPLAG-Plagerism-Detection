#include <stdio.h>
#define visina 20
#define sirina 20
int main() {
    int j,i,n,nizA[visina],nizB[sirina],l;
    char mat[visina][sirina];
    do {
        printf("Unesite broj tacaka: ");
        scanf("%d",&n);
        if(n<=0 || n>10)
        printf("Pogresan unos\n");
        }
        while(n<=0 || n>10);
        for(l=0;l<n;l++){
            printf("Unesite %d. tacku: ",l+1);
            scanf("%d %d",&nizA[l],&nizB[l]);
            while((nizA[l]<0 || nizA[l]>19) || (nizB[l]<0 || nizB[l]>19)){
                printf("Pogresan unos\n");
                printf("\nUnesite %d. tacku: ",l+1);
                scanf("%d %d",&nizA[l],&nizB[l]);
            }
        }
        for(i=0;i<visina;i++){
            for(j=0;j<sirina;j++){
                mat[i][j]=' ';
            }
        }
        for(l=0;l<n;l++) {
            for(i=0;i<visina;i++){
                for(j=0;j<sirina;j++){
                    if(i==nizB[l] && j==nizA[l])
                    mat[i][j]='*';
                }
            }
        }
        for(i=0;i<visina;i++){
            for(j=0;j<sirina;j++){
                printf("%c",mat[i][j]);
            }
        printf("\n");
        }
	return 0;
}
