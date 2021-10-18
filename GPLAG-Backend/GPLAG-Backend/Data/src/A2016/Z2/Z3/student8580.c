#include <stdio.h>

int main() {
	int x[10],y[10],i,j,u,t,b;
	do{
	    printf("Unesite broj tacaka: ");
	    scanf("%d",&b);
	    if(b>10||b<=0){
	    printf("Pogresan unos\n");}
	}while(b>10||b<=0);
	for(u=0;u<b;u++){
	    printf("Unesite %d. tacku: ",u+1);
	    scanf("%d %d",&x[u],&y[u]);
	    if(x[u]<0||x[u]>19||y[u]<0||y[u]>19){
	    printf("Pogresan unos\n");u--;}
	    	}
	    	
	    	
	    for(i=0;i<=19;i++){
	        for(j=0;j<=19;j++){
	            for(t=0;t<b;t++){
	                if(i==y[t]&&j==x[t]){
	                printf("*");
	                break;}
	            }
	            if(t==b)
	            printf(" ");
	        }
	        printf("\n");
	        
	    }
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	    	
	return 0;
}
