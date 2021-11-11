#include <stdio.h>

int main() {
	int i,j,k,m,t,n,pn[10],h,dn[10];
	char mat[20][20];
	
	
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			mat[i][j]=' ';
		}
	}
	for(i=0;i<1;i++){
		printf("Unesite broj tacaka: ");
		scanf("%d",&t);
		if(t<=10 && t>0){
			break;
		}
		else{
			printf("Pogresan unos\n");
			i--;
		}
	}
	
	
	for(i=0;i<t;i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d%d",&pn[i],&dn[i]);
		if((pn[i]>19 || pn[i]<0)||(dn[i]>19 || dn[i]<0)){
			printf("Pogresan unos\n");
			i--;
		}
	}
   for(h=0;h<t;h++){
   	
   	for(k=0;k<20;k++){
   		for(j=0;j<20;j++){
   			if(pn[h]==j && dn[h]==k)
   				mat[k][j]='*';
   			
   		}
   		
   	}
   }
   for(i=0; i<20; i++){
   	for(j=0; j<20; j++){
   		printf("%c", mat[i][j]);
   	}
   	printf("\n");
   }
	return 0;
}
