#include <stdio.h>

int main() {
int r, k, s, i, j, l, a, b; /*r=redovi, k=kolone, s=sirina*/

do {
printf("Unesite broj redova: ");
scanf("%d", &r);
} while(r<=0 || r>10);

do {
printf("Unesite broj kolona: ");
scanf("%d", &k);
} while(k<=0 || k>10);

do {
printf("Unesite sirinu jedne kolone: ");
scanf("%d", &s);
} while(s<=0 || s>10);

for(i=0;i<r;i++) { 
    
    for(j=0;j<k;j++) {
        printf("+");
        
        for(l=0;l<s;l++) {
            printf("-");
        }
    }
    printf("+");
    printf("\n");
    
    for(a=0;a<k;a++) {
        printf("|");
        for(b=0;b<s;b++) {
            printf(" ");
        }
    }
    printf("|");
    printf("\n");
}
    for(j=0;j<k;j++) {
        printf("+");
        for(l=0;l<s;l++) {
            printf("-");
        }
    }
printf("+");
	return 0;
}
