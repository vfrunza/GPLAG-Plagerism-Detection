#include <stdio.h>
#include <math.h>
#define e 0.0000000001



int main () {

int i,j,znak1=100,znak2=100,m,n;
double a[100][100];

do {
printf("Unesite M i N: ");
scanf("%d %d", &m, &n);
if(m>100 || m<=0 || n>100 || n<=0) printf("Pogresan unos!\n");
else break;
} while(2);


printf("Unesite elemente matrice: ");
for(i=0;i<m;i++) {
for(j=0;j<n;j++) {
scanf("%lf", &a[i][j]);
}
}

for(i=0;i<m;i++) {
for(j=0;j<n;j++) {
if(i<m-1 && j<n-1) {
if( fabs( a[i][j] - a[i+1][j+1] ) > e ) znak1=0;
else if( fabs(a[i][j] - a[i+1][j+1]) < e && i==m-2 && j==n-2 && znak1!=0) znak1=1;
}
}
}

for(i=0;i<m-1;i++) {
if(znak1==1) {
if( fabs(a[i][n-1] - a[i+1][0])>e) znak2=0;
else if( fabs(a[i][n-1] - a[i+1][0] ) <e && i==m-2 && znak2!=0) znak2=1;
}
else znak2=0;
}

if(znak2==1 || m==1) printf("Matrica je cirkularna");
else if(znak1==0 && znak2==0) printf("Matrica nije ni cirkularna ni Teplicova");
else if((znak1==1 && znak2==0) || n==1) printf("Matrica je Teplicova");

return 0;
}
