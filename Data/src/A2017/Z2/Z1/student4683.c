#include <stdio.h>
#include <math.h>

int main() {
    char znak=92;
    int i,j,N;
    do { 
        printf("Unesite broj N: ");
        scanf("%d",&N); 
        if(N<8 || N%4!=0)
        printf("Neispravno N!");
        printf("\n");
    } while (N%4!=0 || N<8);
    
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            if (i==j && j>=0 && i>=0  && i<N/2 && j<N/2) printf("%c", znak);
            else if (i==N/2-1-j && j>=0 && j<N/2 && i>=0 && j<N/2) printf("/");
            else if(i==0 && (j==N/2 || j==N-1)) printf("+");
            else if(i==0 && j>N/2 && j<N-1) printf("-");
            else if(j==N/2 && i>0 && i<N/2-1) printf("|");
            else if(j==N-1 && i>0 && i<N/2-1) printf("|");
            else if(i==N/2-1 && j>N/2 && j<N-1) printf("-");
            else if(i==N/2-1 && (j==N/2 || j==N-1)) printf("+");
            else if(i==N/2 && (j==0 || j==N/2-1)) printf("+");
            else if(i==N/2 && j>0 && j<N/2-1) printf("-");
            else if(j==0 && i>N/2 && i<N-1) printf("|");
            else if(j==N/2-1 && i>N/2 && i<N-1) printf("|");
            else if(i==N-1 && (j==0 || j==N/2-1)) printf("+");
            else if(i==N-1 && j>0 && j<N/2-1) printf("-");
            else if(j==3*N/4-1 && i>N/2-1 && i<3*N/4-1) printf("|");
            else if(j==3*N/4 && i>N/2-1 && i<3*N/4-1) printf("|");
            else if(j==3*N/4-1 && i>3*N/4  && i<N) printf("|");
            else if(j==3*N/4 && i>3*N/4 && i<N) printf("|");
            else if(i==3*N/4-1 && j>N/2-1 && j<3*N/4-1) printf("-"); 
            else if(i==3*N/4-1 && j>3*N/4 && j<N) printf("-");
            else if(i==3*N/4 && j>N/2-1 && j<3*N/4-1) printf("-");
            else if(i==3*N/4 && j>3*N/4 && j<N) printf("-");
            else if(i==3*N/4 && j>N/2-1 && j<3*N/4-1) printf("-");
            else if(i==3*N/4-1 && (j==3*N/4-1 || j==3*N/4)) printf("+");
            else if(i==3*N/4 && (j==3*N/4-1 || j==3*N/4)) printf("+");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}