#include <stdio.h>

int main()
{
    int n, i, j;

    do{
    printf("Unesite broj n: ");
    scanf("%d", &n);
    if(n<=0 || n>50){
    printf("Pogresan unos\n");

    }
    else break;
    }while(1==1);
    if(n==1){
        printf("***");
    }
    else if(n>0 || n<=50){
        for(i=0;i<n;i++){
            for(j=0;j<(4*n)-3;j++){
                if( (i==j) || (j==(i+(n*4-3)/2)) ){
                printf("*");
                }

                else if((j==((n*4-3)/2)-i) || (j==(n*4-4)-i) ){
                    printf("*");
                }
                else{
                printf(" ");
                }
                }printf("\n");
                }


    }


    return 0;
}
