#include <stdio.h>

int main() {
	int i,j,n,k,z=0;
do{
	printf("\nUnesite broj N:");
	scanf("%d", &z);
	if((z%4==0)&&(z>=8))
	break;
	else printf("Neispravno N!");}
	while((z%4!=0)&&(z<8));
	printf("\n");
	
	k=z/2;

	for(i=0;i<k;i++)
	{	{
		for(j=0;j<k;j++)
			{
			if(i==j)
			printf("\\");
			else if(j==k-i-1)
			printf("/");
			else 
			printf(" ");
			}
		}
		
	if(i==0)
	{	printf("+");
		for(j=0;j<k-2;j++)
		{printf("-");}
		printf("+");}
	if(i!=0 && i!=k-1)
		{printf("|");
	for(j=0;j<k-2;j++)
		{printf(" ");}
		printf("|");}
	if(i==k-1)
		{printf("+");
	for(j=0;j<k-2;j++)
		{printf("-");}
		printf("+");}
		printf("\n");
	}
	for(i=k; i<z; i++){
		if(i == k){
      	printf("+");
        	
  	for(j=0; j<k-2; j++){
   		printf("-");
       	}
       	printf("+");
		}
	if(i == z-1){
      	printf("+");
       	for(j=0; j<k-2; j++){
   		printf("-");
        	}
       	printf("+");
	}
	if(i!=k && i !=z-1){
		printf("|");
    for(j=0; j<k-2; j++){
   		printf(" ");
       	}
       	printf("|");
	}
	if((i==(k + (k/2 ))) || (i==(k + ((k/2) - 1 )))){
		for(n=0; n<((k-2)/2); n++)
		printf("-");
		printf("++");
		for(n=0; n<((k-2)/2); n++)
		printf("-");
	}
	else{
		for(n=0; n<((k-2)/2); n++)
		printf(" ");
		printf("||");
		for(n=0; n<((k-2)/2); n++)
	printf(" ");}
		printf("\n");}

	return 0;
}
