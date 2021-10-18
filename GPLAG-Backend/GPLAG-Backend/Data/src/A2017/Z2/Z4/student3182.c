#include <stdio.h>
#include <math.h>
int main() {
    int A[100][100], B[100][100], C[100][100], i, j, ba[1000]={0}, bb[1000]={0}, bc[1000]={0}, m, n, r=0;
    do{ printf("Unesite brojeve M i N: ");
    scanf("%d %d", &m, &n);} while((m<0 || m>100) || (n<0 || n>100));
    printf("Unesite clanove matrice A: ");
        for(i=0; i<m; i++){
        for(j=0; j<n; j++)
        scanf("%d", &A[i][j]);}
    printf("Unesite clanove matrice B: ");    
        for(i=0; i<m; i++){
        for(j=0; j<n; j++)
        scanf("%d", &B[i][j]);}
    printf("Unesite clanove matrice C: ");    
        for(i=0; i<m; i++){
        for(j=0; j<n; j++)
        scanf("%d", &C[i][j]);}
        for(i=0; i<m; i++)
        for(j=0; j<n; j++) {
            if(A[i][j]<0)
            A[i][j]=sqrt(pow(A[i][j],2));
            if(B[i][j]<0)
            B[i][j]=sqrt(pow(B[i][j],2));
            if(C[i][j]<0)
            C[i][j]=sqrt(pow(C[i][j],2));
        }
    for(i=0; i<m; i++){
        for(j=0; j<n; j++) 
        ba[(A[i][j])]++;} 
           for(i=0; i<m; i++){
           for(j=0; j<n; j++) 
           bb[(B[i][j])]++;}  
             for(i=0; i<m; i++){
             for(j=0; j<n; j++) 
             bc[(C[i][j])]++;} 
   for(i=0; i<m; i++)
        for(j=0; j<n; j++){
        if(ba[A[i][j]]==bb[A[i][j]] && ba[A[i][j]]==bc[A[i][j]] && bb[B[i][j]]==bc[B[i][j]])
         r++;}
         if(r==m*n) printf("DA"); else printf("NE");
return 0;}