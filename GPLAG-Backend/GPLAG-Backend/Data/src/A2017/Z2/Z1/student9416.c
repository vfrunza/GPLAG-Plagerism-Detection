#include <stdio.h>

int main() {
	
	int i=0,j=0,n,l=0;

	do{
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if(n%4!=0 || n<8)printf("Neispravno N!\n");
	}while(n%4!=0 || n<8);
	
printf("\n");
l=n/2;


for(i=0; i<l; i++){

	for(j=0; j<l; j++){
	if(l-(i+1)==j)printf("/");
	else if(i==j)printf("\\");
	else printf(" ");}
	
	for(j=0; j<l; j++){
		if((i==0||i==l-1)&&(j==0||j==l-1))printf("+");
		else if(j==0||j==l-1)printf("|");
		else if(i==0||i==l-1)printf("-");
		else printf(" ");
	}
	printf("\n");}
	
for(i=0; i<l; i++){

	for(j=0; j<l; j++){
		
		for(j=0; j<l; j++){
		if((i==0||i==l-1)&&(j==0||j==l-1))printf("+");
		else if(j==0||j==l-1)printf("|");
		else if(i==0||i==l-1)printf("-");
		else printf(" ");
	}
	
	for(j=0;j<l;j++){
		if((i==l/2||i==l/2-1)&&(j==l/2||j==l/2-1))printf("+");
		else if(j==l/2 || j==l/2-1) printf("|");
		else if(i==l/2 || i==l/2-1)printf("-");
		else printf(" ");
	}
	printf("\n");
	}

	
}
return 0;
}
