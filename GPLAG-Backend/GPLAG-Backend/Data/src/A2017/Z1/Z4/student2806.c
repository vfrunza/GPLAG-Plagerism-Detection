#include <stdio.h>

int main() {
    int br_redova, br_kolona, i, j, sirina=0;
    char s;
    printf("Unesite broj redova: ");
    scanf("%d", &br_redova);
    printf("Unesite broj kolona: ");
    scanf("%d", &br_kolona);
    printf("Unesite sirinu jedne kolone: ");
    do{
        scanf("%c", &s);
        sirina++;
    } while(s=='-');
    
    for(i=0; i<2*br_redova+1; i++){
        for(j=0; j<br_kolona*sirina+br_kolona+1; j++){
            if (i%2==0&&j%(sirina+1)==0) printf("+");
            else if(i%2==1&&j%(sirina+1)==0) printf("|");
            else if(i%2==0) printf("-");
            else printf(" ");
        }
        printf("\n");
    }
    
	return 0;
}
