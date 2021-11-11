#include <stdio.h>

int main(){
int i,j,m,n;
int cirk=0,tep=0;
double mat[100][100];


do{
printf("Unesite M i N: ");
scanf("%d %d",&m,&n);

if(m<=0 || m>100 || n<=0 || n>100){
	printf("Pogresan unos!\n");
      }
   
   

}while(m<=0 || m>100 || n<=0 || n>100);

printf("Unesite elemente matrice: ");
for(i=0;i<m;i++){
	for(j=0;j<n;j++){
		scanf("%lf",&mat[i][j]);
}
}
	
   
 
   
   for(i=0;i<m-1;i++){
   	for(j=0;j<n-1;j++){
   			if(mat[i][j]!=mat[i+1][j+1]){
   			tep=1;
   			}
   		}
   }
  

   for(i=0;i<m-1;i++){
      for(j=0;j<n-1;j++){
            if(mat[i][n-1]!=mat[i+1][0] || mat[i][j]!=mat[i+1][j+1]){
               cirk=1;
            }
      }
   }
            
    if(m==1)printf("Matrica je cirkularna");
    else if(n==1)printf("Matrica je Teplicova");
   else if(cirk==0 && tep==0) printf("Matrica je cirkularna");
   else if(cirk==0 && tep==1) printf("Matrica je cirkularna");
   else if(cirk==1 && tep==1) printf("Matrica nije ni cirkularna ni Teplicova");
   else if (tep==0 && cirk==1) printf("Matrica je Teplicova");
   	
  
   
   
return 0;	
}