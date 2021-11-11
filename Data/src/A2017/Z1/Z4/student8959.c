#include <stdio.h>

int main() {
	int BR,BK,SJK,i,j,k;
	do {
	printf("Unesite broj redova: ");
	scanf("%d",&BR);
	   } while(BR<=0 || BR>10);
	   
	   do {
	printf("Unesite broj kolona: ");
	scanf("%d",&BK);
	   } while(BK<=0 ||BK>10);
	   
	   do {
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&SJK);
	   } while(SJK<=0 ||SJK>10);
	 
	 for(k=0;k<=BR;k++)
	 {
	   for(i=0;i<BK;i++)
	   {
	   	if(i==0) printf("+");
	   	for(j=0;j<SJK;j++)
	   	{
	   		printf("-");
	   	}
	   	printf("+");
	   }
	   printf("\n");
	   if(k==BR) return 1;
	    for(i=0;i<BK;i++)
	   {
	   	if(i==0) printf("|");
	   	for(j=0;j<SJK;j++)
	   	{
	   		printf(" ");
	   	}
	   	printf("|");
	   }
	   printf("\n");
	   
	   
	 	
	 }
	 
	return 0;
}
