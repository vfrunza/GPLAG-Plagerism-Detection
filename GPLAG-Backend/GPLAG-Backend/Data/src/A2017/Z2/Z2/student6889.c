#include <stdio.h>

int main( int argc, char* argv[] ) {

	int n,i,niz[100],brojac=0,k=0;

	do{
	printf("Unesite velicinu niza: \n");
	scanf("%d",&n);
	}while(n<=0 || n>100);

	
	printf("Unesite clanove niza: \n");
	for(i=0;i<n;i++){
	scanf("%d",&niz[i]);
	if(i<0){
		i--;
	}
	

	}
	printf("Finalni niz glasi:\n");
	for(i=0;i<n;i++){
		
		
while(n!=0)
{
	k*=10;
	k+=n%10;
	n/=10;

}
while(k!=0)
{
	printf("%d ",k%10);
	k/=10;
}


	
		if(brojac==0){
		printf("%d ",niz[i]);
		}
			if(niz[i]==niz[i+1]){
		brojac++;
		
			}
	else if(niz[i]!=niz[i+1]){
		printf("%d ",brojac+1);
		brojac=0;
	}else{
		if(i==n){
			printf(" 1");
		}else{
			printf(" 1 ");
		}
	}
	}
	

	return 0;
}
