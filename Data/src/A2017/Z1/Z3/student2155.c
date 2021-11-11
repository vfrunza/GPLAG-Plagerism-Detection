#include <stdio.h>
#define eps 100.00
int main() {
char m;
int i;
int n=0;
int z=0;
int l=0;
int x=0;
int y=0;
double q,w,a,r,u;
printf("Unesite vozila: ");
while(1) {
    scanf("%c",&m);
    if(m=='c' || m=='C'){
 
    n++;}
    else if(m=='b' || m=='B'){
  
    y++;}
    else if(m=='s' || m=='S'){
   
    z++;}
    else if(m=='v' || m=='V'){
  
    l++;}
    else if(m=='p' || m=='P'){
   
    x++;}
    
    else if(m=='k' || m=='K')
    break;
    else if (m!='s' && m!='S' && m!='v' && m!='V' && m!='p' && m!='P' && m!='b' && m!='B' && m!='c' && m!='C' )
    printf("Neispravan unos\n");
    continue;
   }
   i=n+z+l+x+y;
 
 printf("Ukupno evidentirano %d vozila. ",i);
  
 if(i==0 && x==0 && y==0 && l==0 && z==0 && n==0)
 printf("\nNajpopularnija boja je crna (0.00%%).");
 
 
 else if((n>z || n==z) && (n>l || n==l) && (n>x || n==x) && (n>y || n==y) ){
   q=(n*eps)/i;
 printf("\nNajpopularnija boja je crna (%.2f%%).", q);}
 
 else if((y>n) && (y>l || y==l) && (y>x || y==x) && (y>z || y==z)){
     u=(y*eps)/i;
 printf("\nNajpopularnija boja je bijela (%.2f%%).", u);}

 else if((z>n || z==n) && (z>l || z==l) && (z>x || z==x) && (z>y) ){
     w=(z*eps)/i;
  printf("\nNajpopularnija boja je siva (%.2f%%).", w);}
 
 else if((l>z) && (l>n) && (l>x || l==x) && (l>y) ){
     a=(l*eps)/i;
 printf("\nNajpopularnija boja je crvena (%.2f%%).", a);}

 else if((x>n) && (x>l) && (x>z) && (x>y) ){
     r=(x*eps)/i;
 printf("\nNajpopularnija boja je plava (%.2f%%).", r);}
 

 

	return 0;
}
