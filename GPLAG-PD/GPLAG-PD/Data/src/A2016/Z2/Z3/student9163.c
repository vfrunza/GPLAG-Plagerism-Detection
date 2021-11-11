#include <stdio.h>

int main() {
	char matrica[20][20];
	int brtacaka,x,y,i,j,k;
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			matrica[i][j]='0';
		}
	}
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&brtacaka);
	if(brtacaka<=0 || brtacaka>10)
	{printf("Pogresan unos\n");continue;}
	  
	  for(k=0;k<brtacaka;k++){
			printf("Unesite %d. tacku: ",k+1);
			scanf("%d %d",&x,&y);
			if(x<0 || x>19 || y<0 || y>19) {printf("Pogresan unos\n"); k--;continue;}
		    else{
		    for(i=0;i<=y;i++)
		     {
				for(j=0;j<=x;j++)
			 	{
					if(i==y && j==x)
						matrica[i][j]='*';
					else
					{
						if(matrica[i][j]=='*') matrica[i][j]='*';
						else matrica[i][j]=' ';
		   			}
				}
		    }
		    
		   }
			
		
	  }
	 
	}while(brtacaka<=0 || brtacaka>10);

	for (i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			
			if(matrica[i][j]!='0')printf("%c",matrica[i][j]);
			else printf(" ");
			
		}
		printf("\n");
	}
	
	
	
	return 0;
}
