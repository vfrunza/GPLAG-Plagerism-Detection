#include <stdio.h>

int main() {

int n,i,j;
int b=(n/2-2)/2;
 do{
 	printf("Unesite broj N: ");
 
	scanf("%d",&n);
	if(n<8 || n%4!=0)
	printf("Neispravno N!");
		printf("\n");
}while(n<8 || n%4!=0);
  
for(i=0;i<n/2;i++){
	for(j=0;j<n;j++){
		
		if(i==j && i<=n/2-1 && j<=n/2-1)
		 printf("\\");
		

	   else if(i<=n/2-1 && j==n/2-1-i  ){
	   	printf("/");
	   	}else if(!((i==0 || i==n/2-1) &&(j>=n/2-1 )) &&(!(j==n-2)&& i<=n/2-1)) {
	   		
	   		printf(" ");
	   	}
			
	   if(i==0 || i==n/2-1){
	 	
			if(j==n/2-1  || j==n-1)
			printf("+");
			
	else if( j>n/2 && j<n-1 )
	
	printf("-");
			
		}else{if((j==n/2-1 || j==n-2) && i<=n/2-1)
			printf("|");
					}
		

	} 
	printf("\n");
}


for(i=n/2;i<n;i++){
	for(j=0;j<n;j++){


	if(i==n/2 || i==n-1){
	 	
			if(j==0  || j==n/2-1)
			printf("+");
			
	else if( j>0 && j<n/2-1 )
	
	printf("-");
	else if(j==n/2 || j==n-1)
	printf(" ");
	/*else if(j>n/2 || j<n-1)
	printf("|") */;
			
		}else if(i>=n/2){
			
		 if(j==0 || j==n/2-1) 
			printf("|");
			 else if(j>0 && j<n/2-1) printf(" "); 
		}
	     	b=(n/2-2)/2;
		 if(i==n/2+b || i==n/2+b+1){ 
		 	if (j>=n/2-1  && j<n/2-1+b  || j>=n/2-1+b+2 && j<n-1)
		printf("-");
		   else if((i==n/2+b || i==n/2+b+1) && (j==n/2-1+b  || j==n/2-1+b+1))
		printf("+");
		 } 
		 
		 else if(n==8 &&(i==n/2 || i==n-1)){
			if((j==3 ))
		 	printf(" ||");
		 	
            else if(j>=n/2-1  && j<n/2-1+b  || j>=n/2-1+b+2 && j<n-1)
            printf(" ");
		}
		 
		 
		 	else if(i==n/2 || i==n-1){
			if((j==n/2-2+b  || j==n/2-1+b))
		 	printf("|");
		 	
            else if(j>=n/2-1  && j<n/2-1+b  || j>=n/2-1+b+2 && j<n-1)
            printf(" ");
		}
		 
		 
		 else if(i>n/2-1 && i<n/2+b || i>n/2+b+1 && i<n-1){
		 	if((j==n/2-1+b  || j==n/2-1+b+1))
		 	printf("|");
		 	
            else if(j>=n/2-1  && j<n/2-1+b  || j>=n/2-1+b+2 && j<n-1)
            printf(" ");
		 }
		
}
printf("\n");
} 
	

	return 0;
}
