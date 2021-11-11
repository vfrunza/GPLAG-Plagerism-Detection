#include <stdio.h>
#define vel 100


int main() {
	
	int x,i,niz[vel],rast[vel],rst=0;
	do{
		
		printf("Unesite velicinu niza: ");
		scanf("%d", &x);
		
	}while(x<0||x>100);
	
	again:
	
	printf("Unesite clanove niza: ");

			
		for(i=0;i<x;i++){
			scanf("%d", &niz[i]);
			if(niz[i]<0) goto again;
			
		}
		
	
	
	do{
		for(i=0;i<x;i++)
		rast[i] = niz[i] % 10;
        niz[i] /= 10;
        i++;
        rst++;
	}while(i==x);
	
	
	
	
	
	printf("Finalni niz glasi: \n");
	for(i=0;i<x;i++){
		printf("%d %d",rast[i],rst );
	}
	
	
	
	
	return 0;
}
