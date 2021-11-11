#include <stdio.h>

int main() {
    int i, j, a;
    
    printf("Unesite broj n: ");
    scanf("%d", &a);
    while (a<=0 || a>50) 
    { 
        printf("Pogresan unos\n");
        printf("Unesite broj n: ");
        scanf("%d", &a);
    }
    if(a==1) {
         printf("***");
    } else {
    for (i=1; i<=a; i++) { 
        for(j=1; j<=4*a-3; j++) { 
            if(i==j || i+j==2*a || i+j==4*a-2 || j-i==2*a-2) 
            printf("*");
          else printf(" ");
        }
            printf("\n");
    }
    }
	return 0;
}
