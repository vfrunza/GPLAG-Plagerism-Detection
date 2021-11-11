#include <stdio.h>

int main() {

int x,y,n,i,j,xmax=-1000000,niz[100];
char a[20][20];


for(i=0;i<20;i++) {
for(j=0;j<20;j++) {
a[i][j]=' ' ;
}
}



while(2) {
printf("Unesite broj tacaka: ");
scanf("%d", &n);
if(n<=0 || n>10) printf ("Pogresan unos\n");
else break ;
}

for(i=0;i<n;i++) {
printf("Unesite %d. tacku: ", i+1);
scanf("%d %d", &x, &y);

if(x>19 || x<0 || y>19 || y<0) {
printf("Pogresan unos\n");
i--;
continue;
}
niz[i]=y;
a[x][y]='*';
}

for(i=0;i<n;i++) {
if(niz[i]>xmax) xmax=niz[i];
}


for(j=0;j<=xmax;j++) {
for(i=0;i<20;i++) {
printf("%c", a[i][j]);
}
printf("\n");
}
return 0;	
}