#include <stdio.h>

int main() {
	int bredova,bkolona,skolona,i,j,k;
	do{
	printf("Unesite broj redova: ");
	scanf("%d",&bredova);}
	while(bredova<=0 || bredova>10);
	do{
	printf("Unesite broj kolona: ");
	scanf("%d",&bkolona);
	} while(bkolona<=0 || bkolona>10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&skolona);}
	while(skolona<=0 || skolona>10);
	
	for ( i=1;i<=2*bredova+1;i++){
		if(i%2==1)
	 {
		for(j=1;j<=bkolona;j++)
		{
			printf("+");
			for(k=1;k<=skolona;k++)
			{
				printf("-");
			}
		}printf("+\n");
	 }
	 else
	 { 
	 	for(j=1;j<=bkolona;j++)
	 	{
	 	printf("|");
	 	    for(k=1;k<=skolona;k++) 
	 	    {
	 	    	printf(" ");
	 	    }
	   }printf("| \n");
	 	
	 }
	}
	
	return 0;
}
