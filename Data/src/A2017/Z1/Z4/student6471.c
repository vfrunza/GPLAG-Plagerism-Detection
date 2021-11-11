#include <stdio.h>

int main() {
	int i,s,j,k,n,p,z,m;
	do{ printf("Unesite broj redova: ");
		scanf("%d",&n);
	} 
	while(n<=0 || n>10);
	do{	printf("Unesite broj kolona: ");
		scanf("%d",&k);
	} 
	while(k<=0 || k>10);
	do{	printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&s);
	} 
	while(s<=0 || s>10);
    
    
    
   for(m=0; m<n ;m++){
    for(j=0; j<k; j++){
    	printf("+");
    for(i=0; i<s; i++)
    printf("-");}
      printf("+\n");
    
    for(z=0; z<k; z++){
        printf("|");
    for(p=0; p<s; p++)
    printf(" ");}
    printf("|\n");}
    
    for(j=0; j<k; j++){
    	printf("+");
    for(i=0; i<s; i++)
    printf("-");}
      printf("+\n");

    
    return 0; }
    
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
