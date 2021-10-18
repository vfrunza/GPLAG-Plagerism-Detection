#include <stdio.h>

int main() {
    int i=0, j=0, z=0, a=0, b=0, k=0;
    do{
    printf("Unesite broj redova: ");
    scanf("%d", &a);

    }
    while(a<=0 || a>10);
    do{
    printf("Unesite broj kolona: ");
    scanf("%d", &b);
    }
    while(b<=0 || b>10);
    do{
    printf("Unesite sirinu jedne kolone: ");
    scanf("%d", &k);
    
    }
    while(k<=0 || k>10);

    for(i=0;i<a;i++){
    for(j=0; j<((b*k)+(b+1)); j++){
    if(j==0 || j==k+1 || j==2*(k+1) || j==3*(k+1) || j==4*(k+1) || j==5*(k+1) || j==6*(k+1) || j==7*(k+1) || j==8*(k+1) || j==9*(k+1) || j==10*(k+1)){
        printf("+");
    }
    else{
        printf("-");
    }
    }
    printf("\n");
    for(z=0;z<((b*k)+(b+1));z++){
        if(z==0 || z==k+1 || z==2*(k+1) || z==3*(k+1) || z==4*(k+1) || z==5*(k+1) || z==6*(k+1) || z==7*(k+1) || z==8*(k+1) || z==9*(k+1) || z==10*(k+1)){
            printf("|");   
        }else{
            printf(" ");
        }
    }
    printf("\n");
    }
     for(j=0; j<((b*k)+(b+1)); j++){
    if(j==0 || j==k+1 || j==2*(k+1) || j==3*(k+1) || j==4*(k+1) || j==5*(k+1) || j==6*(k+1) || j==7*(k+1) || j==8*(k+1) || j==9*(k+1) || j==10*(k+1)){
        printf("+");
    }
    else{
        printf("-");
    }
    }
	return 0;
}
