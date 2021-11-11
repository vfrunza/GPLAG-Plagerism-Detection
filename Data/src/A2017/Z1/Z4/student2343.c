#include <stdio.h>

int main(){
    int i,j,k,n,m,p;
    do{printf("Unesite broj redova: ");
    scanf("%d",&n);}
    while(n<=0 || n>10);
    do{printf("Unesite broj kolona: ");
    scanf("%d",&m);}
    while(m<=0 || n>10);
    do{printf("Unesite sirinu jedne kolone: ");
    scanf("%d",&p);}
    while (p<=0 || p>10);
    for(i=1;i<=n;i++)
    {for(j=1;j<=m;j++){
        printf("+");
        for(k=1;k<=p;k++)
        {printf("-");}
        if(j==m){printf("+");}
        } printf("\n");
        for(j=1;j<=m;j++){
            printf("|");
            for(k=1;k<=p;k++)
            {printf(" ");}
            if(j==m){printf("|");}
        }
            printf("\n");
            if(i==n){
                for(j=1;j<=m;j++){printf("+");
                for(k=1;k<=p;k++){printf("-");}
                if(j==m)
                {printf("+");}
                }
                printf("\n");}
            }
        
        return 0;
    }
   
