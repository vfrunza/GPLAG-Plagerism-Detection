#include <stdio.h>

int main() {
    int n,i,j;
    int p=1;
    char znak;
    printf("Unesite broj N: ");
    scanf("%d",&n);
    znak='\\';
   if(n<8 || n%4!=0){
   do{
   		printf("Neispravno N!\n");
   		printf("Unesite broj N: ");
   		scanf("%d",&n);
   }while(n<8 || n%4 !=0);
   }
   printf("\n");
   for(i=0;i<n;i++){
   	  for(j=0;j<n;j++){
   	  	if(i<n/2){
   	  	if(i==j){
   	  		printf("%c",znak);
   	  	}else if(j==(n/2 -p)){
   	  		printf("/");
   	  	}else if((j==n/2 || j==(n-1)) && (i==0 || i==(n/2-1))){
   	  		printf("+");
   	  	}else if(j>n/2  && j<(n-1) && (i==0 || i==(n/2-1)) ){
   	  		printf("-");
   	  	}else if((j==n/2 || j==(n-1)) && i>0 && i<n/2){
   	  	    printf("|");
   	  	}else{
   	  		printf(" ");
   	  	}
   	  }
   	  else if(i>=n/2){
   	  
   	   if(i==n/2 && (j==(n/2-1) || j==0)){
   	  		printf("+");
   	  	}else if(j>(n/2+(n/2)/2-2) && j<(n-(n/2)/2 +1)  && i<(n/2 + (n/2)/2-1)){
   	  		printf("|");
   	  	}else if(i==n/2 && j<n/2){
   	  		printf("-");
   	  	}else if((i<n/2 || i<(n-1)) && (j==0 || j==(n/2-1))){
   	  		printf("|");
   	  	}else if((j<=(n/2 + (n/2)/2 -2) || j>=(n-(n/2)/2+1)) && j>=n/2 && (i>=(n/2 +(n/2)/2 -1) && i<(n/2 + (n/2)/2 +1))){
   	  	printf("-");
   	    }else if(i>=(n/2 + (n/2)/2-1) && j>=n/2 &&  i<=(n/2 + (n/2)/2) && (j>=(n/2+(n/2)/2 -1) || j<(n-(n/2)/2 +1))){
   	        printf("+");
   	    }else if(i>=(n/2 + (n/2)/2 +1) && j>(n/2+(n/2)/2-2) && j<(n-(n/2)/2+1)){
   	        printf("|");
   	    }else if(i==(n-1) && (j==0 || j==(n/2-1))){
   	        printf("+");
   	    }else if(i==(n-1) && j<n/2 && j>0){
   	        printf("-");
   	    }
   	  	else{
   	  		printf(" ");
   	  	}
   	  }
   	 }
   	 printf("\n");
   	  p++;
   }
    
	return 0;
}
