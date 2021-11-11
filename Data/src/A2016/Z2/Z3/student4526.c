#include <stdio.h>
#define z 20
int main() {
    int niz1[z][z]={'nekiniz'};
    int i,a,j,x,t,y,o;

do{
printf("Unesite broj tacaka: ");
scanf("%d", &a);if(a<0 || a==0 || a>10)printf("Pogresan unos\n");}while(a<0 || a==0 || a>10);

for(i=0;i<a;i++){
  printf("Unesite %d. tacku: ", i+1);//kr od 1
    scanf("%d %d", &o, &x); if (o<0 || o>19 || x<0 || x>19){printf("Pogresan unos\n");i--;
} else niz1[x][o]='ovdjejetacka'; }
for(i=0;i<z;i++){
    for(j=0;j<z;j++){
        if (niz1[i][j]=='ovdjejetacka'){ printf("*");} else printf(" ");
    }printf("\n");
}

	return 0;
}
