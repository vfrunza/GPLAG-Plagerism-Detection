#include<stdio.h>
int main()
{
    int n,i,j;


    printf("Unesite broj n: ");
    scanf("%d",&n);

     while (n<=0 || n>50){
        printf("Pogresan unos\n");
        printf("Unesite broj n: ");
        scanf("%d",&n);
     } 
   
        if(n==1) printf("***");
        else{
    for(i=1;i<=n;i++){
        for(j=1;j<=(n+(3*(n-1)));j++){
            if((i==j)|| (j==(2*n)-i && i<=n) || (i<=n && j==i+n+n-2) || (i<=n && j==4*n-i-2))
                printf ("*");
                  else printf(" ");
        }
        printf("\n");
    }
}
return 0;
}


