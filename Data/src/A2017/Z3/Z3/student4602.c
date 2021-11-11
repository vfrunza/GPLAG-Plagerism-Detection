#include <stdio.h>
#include<stdlib.h>

int izbaci_cifre(int a[], int b[], int m){

   int i, d;
   int c[100]={0},x=0,temp;

   for(i=0; i<m; i++){
      while(a[i]){
        x=a[i]%10;
        temp=x;
        x=c[i];
        c[i]=temp;
        a[i]/=10;

      }
    if(c[i]==b[i]){
        c[i]=c[i+1];
        m--;
        d=1;
    }
    else if(a[i]<0 || b[i]<0 || b[i]>9)
      d=0;

   for(int j=i+1; j<m; j++){
    if(a[i]==a[j])
        d=0;
   }}

   return d;

}



int main()
{
   int m, a[100], b[100],i;

   printf("Unesite dimenzije niza brojeva: ");
   scanf("%d", &m);
   printf("Unesite clanove niza brojeva: ");
   for(i=0; i<m; i++)
     scanf("%d", &a[i]);
   printf("Unesite clanove niza cifara: ");
   for(i=0; i<m; i++)
     scanf("%d", &b[i]);
   printf("%d", izbaci_cifre(a,b,m));



    return 0;
}