#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
//	printf("Zadaća 2, Zadatak 4");
    int mat1[100][100], mat2[100][100], mat3[100][100], i, j, k, pozitivni1[600], negativni1[600], m, n, pop, ima, nula1=0, pozitivni2[600], pozitivni3[600], negativni2[600], negativni3[600], nula2=0, nula3=0;
    for(i=0;i<600;i++){
        pozitivni1[i]=0;
        pozitivni2[i]=0;
        pozitivni3[i]=0;
        negativni1[i]=0;
        negativni2[i]=0;
        negativni3[i]=0;
    }
    
    do{
        printf("Unesite brojeve M i N: ");
        scanf("%d%d", &m, &n);
    }while(m>100 && m<=0 && n>100 && n<0);
    printf("Unesite clanove matrice A: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d", &mat1[i][j]);
        }
    }
     printf("Unesite clanove matrice B: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d", &mat2[i][j]);
        }
    }
     printf("Unesite clanove matrice C: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d", &mat3[i][j]);
        }
    }
    pop=0;
    ima=0;
     for(i=0;i<m;i++){
        for(j=0;j<n;j++){
   //         for(k=0; k<100; k++){
   //            if(mat1[i][j]==nizbr[k]){ nizkoliko[k]++;}
   //            else{ nizbr[pop]=mat1[i][j]; nizkoliko[pop]++; pop++;}
   //     }
            if(mat1[i][j]<0) negativni1[abs(mat1[i][j])]++;
            else if(mat1[i][j]>0) pozitivni1[abs(mat1[i][j])]++;
            else if(mat1[i][j]==0) nula1++;
        }
    }
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
   //         for(k=0; k<100; k++){
   //            if(mat1[i][j]==nizbr[k]){ nizkoliko[k]++;}
   //            else{ nizbr[pop]=mat1[i][j]; nizkoliko[pop]++; pop++;}
   //     }
            if(mat2[i][j]<0) negativni2[abs(mat2[i][j])]++;
            else if(mat2[i][j]>0) pozitivni2[abs(mat2[i][j])]++;
            else if(mat2[i][j]==0) nula2++;
        }
    }
    
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
   //         for(k=0; k<100; k++){
   //            if(mat1[i][j]==nizbr[k]){ nizkoliko[k]++;}
   //            else{ nizbr[pop]=mat1[i][j]; nizkoliko[pop]++; pop++;}
   //     }
            if(mat3[i][j]<0) negativni3[abs(mat3[i][j])]++;
            else if(mat3[i][j]>0) pozitivni3[abs(mat3[i][j])]++;
            else if(mat3[i][j]==0) nula3++;
        }
    }
    
    for(i=0; i<600; i++){
        if(pozitivni1[i]!=pozitivni2[i] || negativni1[i]!=negativni2[i] || nula1!=nula2 || pozitivni1[i]!=pozitivni3[i] || negativni1[i]!=negativni3[i] || nula1!=nula3){ printf("NE"); return 0;}
    }
    printf("DA");
   // for(i=0; i<100; i++) {
   //     printf("\n%d se ponavlja %d puta\n", nizbr[i], nizkoliko[i]);
    //}
	return 0;
}
