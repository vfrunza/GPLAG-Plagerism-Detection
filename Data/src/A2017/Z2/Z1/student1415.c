#include <stdio.h>

int main()
{
    int n,i,j;
    do {
        printf("Unesite broj N: ");
        scanf("%d",&n);
        if(n%4!=0 || n<8) printf("Neispravno N!\n");
    } while(n%4!=0 || n<8);
    
    printf("\n");
    
    for(i=0; i<n; i++) {

        for(j=0; j<n; j++) {

            if(i==0 || i==n/2-1) {
                if(i==j) printf("\\");
                else if(i==(n/2-(j+1))) printf("/");
                else if(j==n/2||j==n-1) printf("+");
                else if(j>n/2-1 && j<n-1) printf("-");
                else printf(" ");

            }

            else if(i>0 && i<n/2-1) {
                if(i==j) printf("\\");
                else if(i==(n/2-(j+1))) printf("/");
                else if(j==n-1||j==n/2) printf("|");
                else printf(" ");

            }

            else if(i==n/2 || i== n-1) {

                if (j==0 || j==n/2-1) printf("+");
                else if (j>0 && j<n/2-1) printf("-");
                else if (j==n*3/4-1||j==n*3/4) printf("|");
                else printf(" ");
            }
            
                else if(i==n*3/4-1 || i==n*3/4)
                { 
                if(j==0 || j==n/2-1) printf("|");
                else if((j>n/2-1 && j<n*3/4-1) || ( j> n*3/4)) printf("-");
                else if(j==n*3/4-1 || j==n*3/4) printf("+");
                else printf(" ");
                 }
                 
            else  {
                if(j==0 || j==n/2-1) printf("|");
                else if(j==n*3/4-1 || j==n*3/4) printf("|");
                else printf(" ");
            }
            
       
            }

        printf("\n");

    }



    return 0;
}
