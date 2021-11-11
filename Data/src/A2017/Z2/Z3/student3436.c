#include <stdio.h>
int main() {
    float A[100][100],B[100][100];
    int i,j,k,l,va,sa,vb,sb,da;
    
    printf("Unesite sirinu i visinu matrice A: ");
    scanf("%d %d",&sa, &va);
    printf("Unesite clanove matrice A: ");
    for(i=0; i<va; i++){
        for(j=0; j<sa; j++){
        scanf("%f", &A[i][j]);
        }
    }
    
     printf("Unesite sirinu i visinu matrice B: ");
    scanf("%d %d",&sb, &vb);
    printf("Unesite clanove matrice B: ");
    for(k=0; k<vb; k++){
        for(l=0; l<sb; l++){
        scanf("%f", &B[k][l]);
        }
    }
    if(va!=sb || vb!=sa){
        printf("NE");
        return 1;
    }
for(i=0; i<va; i++){
    for(j=0; j<sa; j++){   
    if(A[i][j] == B[j][sb-1-i]) {
    da=1;
    }
    else{
    printf("NE");
    return 2;  
    }
        
    }
        }
    if(da==1)
    printf("DA");

    return 0;
}