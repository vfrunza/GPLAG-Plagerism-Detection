#include <stdio.h>

int main() {

	
 int brredova,brkolona,i,j,teplicova=1,cirkularna=1,t=0,c=0;
 double matrica[100][100];
 
 do
 {
 	printf("Unesite M i N: ");
 	scanf("%d%d",&brredova,&brkolona);
 	if(brredova<=0 || brredova>100 || brkolona<=0 || brkolona>100)
 	printf("Pogresan unos!\n");
 	
 }while(brredova>100 || brkolona>100 || brredova<=0 || brkolona<=0);
 
 printf("Unesite elemente matrice: ");
 for(i=0;i<brredova;i++) {
 	for(j=0;j<brkolona;j++)
 	{
 		scanf("%lf",&matrica[i][j]);
 	}
 }
 
 if (brredova==1 && brkolona==1)
 printf("Matrica je cirkularna");
 else if (brredova==1)
 printf("Matrica je cirkularna");
 else if(brkolona==1)
 printf("Matrica je Teplicova");
 
 
 
 
 else if(brredova!=0 && brkolona!=0)
    {
 	for(i=1;i<brredova-1; i++)
 	 {
 	 	if(matrica[i][0]!=matrica[i-1][brkolona-1]) cirkularna=0;
 	 	else cirkularna=1;
 	 	for(j=1;j<brkolona-1;j++) {
 	 	if(matrica[i][j]!=matrica[i-1][j-1]) cirkularna=0;
 	 	else {
 	 		c=1; cirkularna=1; break;
 	 	     }
 	 	} 
 	 	if(c==1) break;
 	 }
 	
    
    for(i=0;i<brredova-1;i++)
     {
     	for(j=0;j<brkolona-1;j++)
     	{
     		if(matrica[i][j]==matrica[i+1][j+1]) teplicova=0;
     		else { teplicova=1; t=1; break; }
     	}
     	if(t==1) break;
     }
      if(cirkularna!=0 && teplicova!=0 )
      printf("Matrica nije ni cirkularna ni Teplicova");
      else if(cirkularna==0 && teplicova==0)
      printf("Matrica je cirkularna");
      else if(cirkularna==0 && teplicova!=0)
      printf("Matrica je cirkularna");
      else if(teplicova==0 && cirkularna==1)
      printf("Matrica je Teplicova");
      
    }

	return 0;
}
