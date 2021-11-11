#include <stdio.h>
int main() {
	int i,j,n,x,y;
	char mat [20][20];
 
	 
		for (i=0;i<20;i++){
   	for (j=0;j<20;j++){
   mat [i][j]=' ';
   	}
   }
	while(1){
	printf("Unesite broj tacaka: ");
	scanf ("%d",&n);
	if(n<=0 || n>10)
	printf("Pogresan unos\n");
	else 
	break;
	
};
	for(i=0;i<n;i++){
 	printf ("Unesite %d. tacku: ",i+1);
	scanf ("%d %d", &x,&y );
	if (x<0 || y<0 || x>19 || y>19){ printf("Pogresan unos\n");
	i--;}
	else {
	
			mat [x][y]='*';
			
			}}
		
			for (i=0;i<20;i++){
				for (j=0;j<20;j++)
				{
				 printf("%c",mat[j][i]);
					
				}
			
	printf("\n");
}
			
	return 0;
}
