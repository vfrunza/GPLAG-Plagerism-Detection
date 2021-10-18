#include <stdio.h>

int main() {
 
 int n,i,j;
 int nb=0;
 int br=0, br1=0;
 int niz[100], niz1[100],niz_br[100];
 int temp, brojac = 0;
 
 printf("Unesite velicinu niza: ");
 scanf("%d",&n);
 
 printf("Unesite clanove niza: ");
 for(i=0; i<100; i++) {
  niz[i]=0; }
  for(i=0; i<n; i++) 
  {
   scanf("%d",&niz[i]);
  }
 
 for(i=0; i<n; i++)
 {
  nb=0;
  
  while(niz[i]!=0)
  
 {
  nb=nb*10+niz[i]%10;
  niz[i]/=10;
 }
 
 
 niz[i]=nb; 
  
 }
 
 for(i=0; i<n; i++) 
 {
  br=0;
  for(j=0; j<100; j++) 
  {
   while(niz[i]!=0)
   {
    niz1[j]=niz[i]%10;
    br++;
    br1++;
    j++;
    niz[i]/=10;
   }
    j=br-1;
    i++;
    if(i>=n) break;
   }
   break;
 }
 
 printf("Finalni niz glasi:\n");

 for(i=0;i<br1; i++) {
  temp=niz1[i];
  brojac = 0;
  while(i < br1 && niz1[i] == temp)
  {
   brojac++;
   i++;
  }
   i--;
  printf("%d %d ", temp,brojac);
  
 }
	return 0;
}