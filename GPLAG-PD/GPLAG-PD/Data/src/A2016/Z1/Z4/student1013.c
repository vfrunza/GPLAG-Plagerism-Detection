#include <stdio.h>

int main() {

int i,j,n;

while(2) {
printf("Unesite broj n: ");
scanf("%d", &n);
if(n<=50 && n>0) break ;
else printf("Pogresan unos\n");
}
if(n==1) printf("***");
else {
for(i=0;i<n;i++) {
for(j=0;j<4*n-3;j++) {
if(i==j || j==i+2*n-2 || j==2*n-i-2 || j==4*n-4-i) printf("*");
else printf(" ");
}
printf("\n");
}
}
return 0;
}