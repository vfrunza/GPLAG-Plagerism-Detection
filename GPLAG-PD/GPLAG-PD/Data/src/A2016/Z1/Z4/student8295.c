#include <stdio.h>
int main () {
int i, j, n;
do {
printf("Unesite broj n: ");
scanf("%d", &n);
if (n>50 || n<=0) printf ("Pogresan unos\n");
}
while (n<=0 || n>50);

if(n==1){printf("***");}
else{


printf("*");
for(i=0;i<2*n-3;i++) {printf(" ");}
printf("*");
for(i=0;i<2*n-3;i++) {printf(" ");}
printf("*\n");


for(i=0;i<n-2;i++){
    printf(" ");
    for(j=0;j<i;j++){
    printf(" ");}
    printf("*");
    for(j=0;j<2*(n-i)-5;j++){
    printf(" ");}
    printf("*");
    printf(" ");
    for(j=0;j<2*i;j++){
    printf(" ");}
    printf("*");
    for(j=0;j<2*(n-i)-5;j++){
    printf(" ");}
    printf("*\n");
    }

for(i=0;i<n-1;i++) {printf(" ");}
printf("*");
for(i=0;i<2*n-3;i++) {printf(" ");}
printf("*");

}
    
return 0;
}