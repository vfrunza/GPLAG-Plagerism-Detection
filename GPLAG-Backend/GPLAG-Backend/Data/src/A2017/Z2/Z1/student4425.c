#include <stdio.h>

int main() {
//	printf("Zadaća 2, Zadatak 1");
    int i, j, n, x=0;
    
    do{
        x++;
        
        if(x>1) printf("Neispravno N!\nUnesite broj N: ");
        else printf("Unesite broj N: ");
    	scanf("%d", &n);
    }while(n<8 || n%4!=0); //PAZNJAAA
    
    printf("\n");
    for(i=1; i<=n/2; i++){
    	for(j=1; j<=n; j++){
    		if(i==j) printf("\\");
    		else if(i+j==((n/2)+1)) printf("/");
    		else if((j==n/2+1 && i==1) || (j==n/2+1 && i==n/2) || (j==n && i==1) || (j==n && i==n/2)) printf("+");
    		else if((j==n/2+1 && i!=1 && i!=n/2) || (j==n && i!=1 && i!=n/2)) printf("|");
    		else if((i==1 && j>n/2+1 && j!=n) || (i==n/2 && j>n/2+1 && j!=n)) printf("-");
    		else printf(" ");
    	}
    	printf("\n");
    }
    
    for(i=1; i<=n/2; i++){
    	for(j=1; j<=n; j++){
    	    if((j==1 && i==1) || (j==1 && i==n/2) || (j==n/2 && i==1) || (j==n/2 && i==n/2)) printf("+");
    		else if((j==n/2 && i!=1 && i!=n/2) || (j==1 && i!=1 && i!=n/2)) printf("|");
    		else if((i==1 && j<n/2+1 && j!=1) || (i==n/2 && j<n/2+1 && j!=1)) printf("-");
    		else if((i==n/4 && j==3*n/4) || (i==n/4 && j==3*n/4+1) || (i==n/4+1 && j==3*n/4) || (i==n/4+1 && j==3*n/4+1)) printf("+");
    		else if((i==n/4 || i==n/4+1) && j>n/2) printf("-");
    		else if(j==3*n/4 || j==3*n/4+1) printf("|");
    		else printf(" ");
    	}
    	printf("\n");
    }
    

	return 0;
}
