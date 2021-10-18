#include <stdio.h>


int main() 
{
	int i,n,A[100],B[1000], brojac[101]={1},temp;
	printf("Unesite velicinu niza: ");
    scanf("%d",&n);
    
  printf("Unesite clanove niza: ");
  for(i=0; i<n; i++) 
  {
  scanf("%d", &A[i]);
  if (A[i]==-1) break;
  if (A[i]<0 || A[i]>100) 
  {
  i--;
 }
 }

	n=i;
	for(i=1;i<n;i++)
	{
	   
	   if(A[i]==A[i+1]) 
	   { 
	       
	       brojac[A[i]]++ ;
	       
	   }
	   }
	
	
	
	
for (i=0; i<n; i++)
{    
    A[i+1]=A[i+2];
    brojac[A[i]]=A[i+1]; }
    
    for(i=0; i<n;i++) {
        B[i]=A[i];
    }
    
    printf
    for(i=0;i<n;i++)
    {
    printf("%d ",brojac[A[i]]);
   
    }
       
    
 
   
 
   return (0);
}
