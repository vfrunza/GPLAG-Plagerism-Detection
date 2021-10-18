#include<stdio.h>
int main()
{
   int n,d=0,j,i;
do {
printf("Unesite broj n: ");
scanf("%i",&n);
if(n<=0||n>50) printf("Pogresan unos\n"); }
while(n<=0 || n>50);
if (n==1) printf("***");
else if(n>=2 && n<=50) {
d=n*3+(n-3);
for(j=0;j<n;j++) 
{
    for(i=0;i<d;i++)
    {
    if(i<n && i==j) { printf("*");}
   else  if(i<=d/2  && i+j==d/2) { printf("*"); } 
    else if(i<=d-n && i-j==d/2) { printf("*"); }  
    else if(d-i-1==j) { printf("*"); }  else { printf(" "); }  
      }
      printf("\n"); }
      
}
return 0;
}
