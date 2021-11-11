#include <stdio.h>

int main() {
	int x,i,j,k,z,br,bk,sk;
	
	do { printf("Unesite broj redova: ");
	scanf("%d",&br); }while(br>10 || br<=0);
	do { printf("Unesite broj kolona: ");
     scanf("%d",&bk); } while(bk>10 || bk<=0);
	do { printf("Unesite sirinu jedne kolone: ");
	 scanf("%d",&sk);} while(sk>10 || sk<=0);
	for (x=0;x<br;x++){
	for (i=0;i<bk;i++) {
	       printf("+"); 
	        for(j=0;j<sk;j++)
	        { printf("-"); }
	        
	
	
	}
	printf("+");
	printf("\n");
	for(k=0;k<=bk;k++)
	{  printf("|") ;
	    for(z=0;z<sk;z++)
	     {printf(" ");}
	     
	}
	 printf("\n");
	
	
	}
	
	
 	for (i=0;i<bk;i++) {
	       printf("+"); 
	        for(j=0;j<sk;j++)
	        { printf("-"); }}
	printf("+");
	return 0;
}
