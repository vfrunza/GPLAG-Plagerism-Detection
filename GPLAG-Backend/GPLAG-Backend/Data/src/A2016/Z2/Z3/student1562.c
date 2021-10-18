#include <stdio.h>

int main() {
	int brojtacaka,br=1,i,j,k;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&brojtacaka);
	if(brojtacaka<1 || brojtacaka>10)printf("Pogresan unos\n");
	}while(brojtacaka<1 || brojtacaka>10);
    int x[20],y[20];
	for(i=0;i<brojtacaka;i++){
		
		do{
		printf("Unesite %d. tacku: ",br);
		
		scanf("%d", &x[i]);
		scanf("%d", &y[i]);
		if(x[i]<0 || x[i]>19 || y[i]<0 || y[i]>19)printf("Pogresan unos\n");
		}while(x[i]<0 || x[i]>19 || y[i]<0 || y[i]>19);
		br++;
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			
			int brojac=0;
			for(k=0;k<brojtacaka;k++){
			if(j==x[k] && i==y[k] ){
				printf("*");
			    brojac=1;
			 }
			 if(brojac==1)break;
			}
			if(brojac==0)printf(" ");	        	
			    
		}
	  printf("\n");	
	} 
	
	
	
	return 0;
}
