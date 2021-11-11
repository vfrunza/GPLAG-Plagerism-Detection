#include <stdio.h>

int main() {
	
	int i,j,m,n,r,k,s;
	
	do {
    printf("Unesite broj redova: ");
 	scanf("%d", &r);
	} while(r<=0 || r>10);
	
	do {
	printf("Unesite broj kolona: ");
	scanf("%d", &k);
	} while(k<=0 || k>10);
	
	do{
	
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&s);
	
	} while(s<=0  || s>10);
	
	m=2*r+1;
	n=k*s+k+1;
	
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			if(i==0 && j==0  || i==m-1 && j==0 || i==0 && j==n-1 || i==m-1 && j==n-1) printf("+"); //coskovi
			else if(j==0 && i%2!=1 ) printf("+");     //srednji lijevi
			else if(j==n-1 && i%2!=1 ) printf("+");  //srednji desni
			else if(i==0 && j%(s+1)==0) printf("+"); //srednji gornji
			else if(i==m-1 && j%(s+1)==0) printf("+"); //unutrasnji
			else if(i%2!=1 && j%(s+1)==0) printf("+");//srednji donji
		    else if(i==0 || i==m-1 || i%2!=1) printf("-");
		    else if(j%(s+1)==0 || j==0 || j==n-1) printf("|"); 
		    
			else printf(" ");
		}
	printf("\n");
	}
	return 0;
}
