#include <stdio.h>

int main() {
	
	int M,N,i,j,nizA[100],nizB[100],nizC[100],temp;
	
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d%d",&M,&N);
	}while(M<0 || N<0 || M>100 || N>100);
	
	
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M*N;i++){

	scanf("%d",&nizA[i]);
	}
	
	for(i=0;i<M*N;i++){
		
		for(j=i+1;j<M*N;j++){
			
			if(nizA[j]<nizA[i]){
		
			temp=nizA[i];
			nizA[i]=nizA[j];
			nizA[j]=temp;
			}	
		}
	}
	
	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<M*N;i++){

	scanf("%d",&nizB[i]);
	}
for(i=0;i<M*N;i++){
		
		for(j=i+1;j<M*N;j++){
			
			if(nizB[j]<nizB[i]){
		
			temp=nizB[i];
			nizB[i]=nizB[j];
			nizB[j]=temp;
			}	
		}
	}
	
	
	printf("Unesite clanove matrice C: ");
	for(i=0;i<M*N;i++){
		
	scanf("%d",&nizC[i]);
	}
	
	for(i=0;i<M*N;i++){
		
		for(j=i+1;j<M*N;j++){
			
			if(nizC[j]<nizC[i]){
		
			temp=nizC[i];
			nizC[i]=nizC[j];
			nizC[j]=temp;
			}	
		}
	}
	
	
	int DA=1;
	
	for(i=0;i<M*N;i++){
	
	if((nizA[i]!=nizB[i]) || (nizA[i]!=nizC[i])){
		DA=0;
		break;
	}
	}
	
	if(DA==1){
		printf("DA\n");
	}
	else if(DA==0){
		printf("NE\n");
	}
	return 0;
}
