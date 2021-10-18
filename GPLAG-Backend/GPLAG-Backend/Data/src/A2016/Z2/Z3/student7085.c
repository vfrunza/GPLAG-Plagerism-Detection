#include <stdio.h>

int main() {
	int mat[20][20]={1};
	int i,j,x,y,n,br1=1;
    
    do{
    	printf("Unesite broj tacaka: ",n);
	    scanf("%d",&n);
	    
	     if(n<=0 || n>10)
	     printf("Pogresan unos\n");
	     }
	 while(n<=0 || n>10);
	 
	 do{
	    printf("Unesite %d. tacku: ",br1,x,y);
		scanf("%d %d",&x,&y);
         
         if(x<0 || x>19 || y<0 || y>19){
	     printf("Pogresan unos\n");
		 br1--;
		 }else 
	    mat[x][y]=10;
        br1++;}
       	while(br1<=n);
	       
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
	       if(mat[j][i]==10){ printf("*");}
	       else{ printf(" ");}
		}
	       printf("\n");
	    }
    

	return 0;
}
