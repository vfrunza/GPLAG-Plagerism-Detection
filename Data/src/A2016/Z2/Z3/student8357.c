#include <stdio.h>

int main() {
    char mat[20][20];
	int n,x,j,i,a,b;
	unos:
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n<1||n>10){
	    printf("Pogresan unos\n");
	    goto unos;}
	
	
	 
	 for(i=0;i<20;i++){
	     for(j=0;j<20;j++){
	         mat[i][j]=' ';
	     }
	 }
	 
	 
    for(i=0;i<n;i++){
        do{ 
    	printf("Unesite %d. tacku: ",i+1);
    	scanf("%d %d",&b,&a);
        if(a<0||a>19||b<0||b>19)
            printf("Pogresan unos\n");
        }
            while(a<0||a>19||b<0||b>19);
            mat[a][b]='*';
            }
        
            
        
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            printf("%c",mat[i][j]);
        }
        printf("\n");}
   
          
	return 0;
}
