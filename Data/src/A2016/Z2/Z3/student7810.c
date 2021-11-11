#include <stdio.h>
#define PI 3.1415926
int main() { 
    int i,j,k,x[10],y[10],n=-1;
    char matrica[20][20];
    while (1){
        printf("Unesite broj tacaka: ");
        scanf("%d",&n);
        if (n<=10 && n>0) break; 
        printf("Pogresan unos\n");
    } 
    for (i=0;i<20;i++){
	for (j=0;j<20;j++){
	matrica[i][j]=' ';
	}
	}
    for(i=0;i<n;i++) {
        printf("Unesite %d. tacku: ",i+1);
        scanf("%d %d" ,&x[i],&y[i]);
        if (x[i]<0 || x[i]>19 || y[i]<0 || y[i]>19) {
            printf("Pogresan unos\n");
            i--;
        }
    }
            for (i=0;i<20;i++){
                for (j=0;j<20;j++){
                     for(k=0;k<n;k++){
                    if (j==x[k] && i==y[k]) matrica[i][j]='*';
                }
            }
        }
    for (i=0;i<20;i++){
        for(j=0;j<20;j++){
        printf("%c",matrica[i][j]);}
        printf("\n");
        
    }
    
        

	return 0;
}
