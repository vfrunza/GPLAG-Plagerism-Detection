#include <stdio.h>

int main() {
	int n=10, i, j, k=0,ima=0;
	int nizA[20]={0},nizB[20]={0};
	
	
	
    printf("Unesite broj tacaka: ");
    scanf("%d", &n);
    while(n<=0 || n>10) {
        printf("Pogresan unos\n");
        printf("Unesite broj tacaka: ");
        scanf("%d", &n); }
    

    for(i=0; i<n; i++)
    {
        printf("Unesite %d. tacku: ", i+1);
    	scanf("%d", &nizA[i]);
    	scanf("%d", &nizB[i]);
    	if(nizA[i]<0 || nizA[i]>19 || nizB[i]<0 || nizB[i]>19) { printf("Pogresan unos\n"); i--; }
    }
	
	
    for(i=0; i<20; i++)
    {
    	for(j=0; j<20; j++)
    	{
    	    ima=0;
    	    for(k=0; k<n; k++) {
    	    
    		if ((nizA[k]==j) && (nizB[k]==i)) { printf("*"); ima=1; }
    		if(ima) break;
    	    
    	}
    	
    	if(ima==0) printf(" ");
    }
    printf("\n");
	}



	return 0;
}
