#include <stdio.h>

int main() {
    int red, kolona, sirina_kolone, i, j;
    
    do {printf("Unesite broj redova: ");
    scanf("%d", &red); }
    while (red<=0 || red>10);
    
    do {printf("Unesite broj kolona: ");
    scanf("%d", &kolona); }
    while (kolona<=0 || kolona>10);
    
    do {printf("Unesite sirinu jedne kolone: ");
    scanf("%d", &sirina_kolone); }
    while (sirina_kolone<=0 || sirina_kolone>10);
    
    for(i=0; i<(red*2)+1; i++) {
        for(j=0; j<kolona*(sirina_kolone+1)+1; j++) {
            if(i%2==0 && j%(sirina_kolone+1)==0)
            printf("+");
            else if(j%(sirina_kolone+1)==0)
            printf("|");
            else if(i%2==0)
            printf("-");
            else {printf(" "); }
        } printf("\n");
    }
return 0;
}