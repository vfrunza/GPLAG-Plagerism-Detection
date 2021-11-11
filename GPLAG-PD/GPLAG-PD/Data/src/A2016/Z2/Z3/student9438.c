#include <stdio.h>

int main(){
	int brojtacaka,nizx[10],nizy[10],i,j,k, ima=0;
	while(0==0)
	{
	    printf("Unesite broj tacaka: ");
	scanf("%d",&brojtacaka);
	if(brojtacaka<1 || brojtacaka>10) printf("Pogresan unos\n");
	else break;
	}
	for(i=0;i<brojtacaka;i++) {
	    while(0==0)
	    {
	        printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&nizx[i],&nizy[i]);
		if(nizx[i]<0 || nizx[i]>19 || nizy[i]<0 || nizy[i]>19)
		printf("Pogresan unos\n");
		else break;
	    }
	}
	
	   
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
		    ima=0;
			for(k=0;k<brojtacaka;k++){
				if( i==nizy[k] && j==nizx[k])
				{printf("*"); ima=1;}
				
				
				
				
				
				
			}
			if(ima==0) printf(" ");
			
		}printf("\n");
	}
	return 0;
}
