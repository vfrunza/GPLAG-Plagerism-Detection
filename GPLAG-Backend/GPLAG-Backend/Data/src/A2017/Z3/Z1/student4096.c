#include <stdio.h>
#define br_el 1000

int dva_od_tri(int niz1[],int niz2[],int niz3[],int v1,int v2,int v3)
{
 int i;
	for(i=0;i<v1;i++)
}

int main() {
   int i,v1,v2,v3;
   int  niz1[br_el],niz2[br_el],niz3[br_el];
   
   printf("Unesite velicinu prvog niza: ");
   scanf("%d",&v1);
   printf("Unesite velicinu drugog niza: ");
   scanf("%d",&v2);
   printf("Unesite velicinu treceg niza: ");
   scanf("%d",&v3);
  
   for(i=0;i<=v1;i++)
   {
       scanf("%d",&niz1[i]);
   }
    for(i=0;i<=v2;i++)
   {
       scanf("%d",&niz2[i]);
   }
    for(i=0;i<=v3;i++)
   {
       scanf("%d",&niz3[i]);
   }
	return 0;
}
