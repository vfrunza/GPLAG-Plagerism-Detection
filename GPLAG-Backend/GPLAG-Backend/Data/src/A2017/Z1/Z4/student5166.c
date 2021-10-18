#include <stdio.h>
int main (){

    int i,j,red,kol,sir;
    
    do {
    printf ("Unesite broj redova: ");
    scanf ("%d", &red);
    }while (red<=0 || red>10);
    
    do{
    printf ("Unesite broj kolona: ");
    scanf ("%d", &kol);
    }while (kol<=0 || kol>10);
    
    do{
    printf ("Unesite sirinu jedne kolone: ");
    scanf ("%d", &sir);
    }while (sir<=0 || sir>10);
    
    for (i=0; i<(red*2)+1; i++){
        for (j=0; j<kol*(sir+1)+1; j++){
            
            if (i%2==0 && j%(sir+1)==0)
            printf ("+");
            else if (i%2==1 && j%(sir+1)==0)
            printf ("|");
            else if (j%(sir+1)!=0 && i%2==0)
            printf ("-");
            else
            printf (" ");
        }
        printf ("\n");
    }
    return 0;
}