#include <stdio.h>

int main() {
    int unos, i, j;
    char a[20][20];
    for (i = 0; i < 20; i++){
        for (j = 0; j < 20; j++){
            a[i][j] = ' ';
        }
    }
    
    do {
	printf("Unesite broj tacaka: ");
	scanf ("%d", &unos);
	if (unos <= 0 || unos > 10)
	printf("Pogresan unos \n");
	else break;
    } while (1);
    for (i = 0; i < unos; i++){
    int x,y;
    printf("Unesite %d. tacku: ",i+1);
    scanf("%d %d",&x, &y);
    if (x >= 0 && x<=19 && y>=0 && y<=19){
        a[x][y] = '*';
    }
    else {
        printf("Pogresan unos\n");
        i--;
    }
    }
    
    
    int kocka = 0;
    for (kocka; kocka < 20; kocka++){
        int sat = 0;
        for (sat; sat < 20; sat++){
            if (a[sat][kocka] == '*')
                printf("*");
            else printf (" ");
    
        }
        printf("\n");
    
    }
    
    
    
	return 0;
}
