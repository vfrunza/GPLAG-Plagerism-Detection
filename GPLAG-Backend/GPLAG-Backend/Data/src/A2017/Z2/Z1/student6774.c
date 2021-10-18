#include <stdio.h>

int main() {
	int n,i,j;
	char c=92;
	do{
	 printf("Unesite broj N: ");
		scanf("%d",&n);
		if(n%4!=0||n<8)printf("Neispravno N!");
		printf("\n");
	}while(n%4!=0||n<8);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if((i>=1&&i<=n/4&&j>=1&&j<=n/4)||(i>n/4&&i<=n/2&&j>n/4&&j<=n/2)){
				if(i==j)printf("%c",c);
				else printf(" ");
		
				}	
				if((i>=1&&i<=n/4&&j>n/4&&j<=n/2)||(i>n/4&&i<=n/2&&j>=1&&j<=n/4))
				if(i+j==n/2+1)
			printf("/");
			else printf(" ");
			if(j>n/2){
			 if(i==1||i==n/2){
			  if(j==(n/2)+1||j==n)printf("+");
			  else printf("-");
			 }
			 if(i>1&&i<n/2){
			  if(j==(n/2)+1||j==n)printf("|");
			  else printf(" ");
			 }
			 
			}
		if(i>n/2){
		 if(i==(n/2)+1||i==n){
			  if(j==1||j==n/2)printf("+");
			  if(j<n/2&&j>1) printf("-");
			 }
			 if(i>=(n/2)+2&&i<n){
			  if(j==1||j==n/2)printf("|");
			  if(j>1&&j<n/2) printf(" ");
			 }
		 if(j>n/2){
		  if(j==n-n/4||j==n-n/4+1){
		   if(i>=n/2+1&&i<n-n/4||i<=n&&i>n-n/4+1)printf("|");
		  }
		  if(i==n-n/4||i==n-n/4+1){
		    if(j==n-n/4||j==n-n/4+1)printf("+");
		    if((j>n/2&&j<n-n/4)||(j>n-n/4+1&&j<=n))printf("-");
		   }
		   if((i>n/2&&i<n-n/4)||(i>n-n/4+1&&i<=n)){
		   if((j>n/2&&j<n-n/4)||(j>n-n/4+1&&j<=n)){
		    printf(" ");
		   }
		   }
		  }
		  
		 
		}
				
				
				
			}
			printf("\n");
			
			
			
			
		}
		return 0;
	}
	



/*
\  /+--+ 			\    /+----+
 \/ |  |             \  / |    |
 /\ |  |              \/  |    |
/  \+--+              /\  |    |
+--+ ||              /  \ |    |
|  |-++-            /    \+----+
|  |-++-            +----+  ||
+--+ ||             |    |  ||
                    |    |--++--
                    |    |--++--
                    |    |  ||
                    +----+  ||
                    
\          /+----------+
 \        / |          |
  \      /  |          |
   \    /   |          |
    \  /    |          |
     \/     |          |
     /\     |          |
    /  \    |          |
   /    \   |          |
  /      \  |          |
 /        \ |          |
/          \+----------+
+----------+     ||     
|          |     ||     
|          |     ||     
|          |     ||     
|          |     ||     
|          |-----++-----
|          |-----++-----
|          |     ||     
|          |     ||     
|          |     ||     
|          |     ||     
+----------+     ||                         
*/
