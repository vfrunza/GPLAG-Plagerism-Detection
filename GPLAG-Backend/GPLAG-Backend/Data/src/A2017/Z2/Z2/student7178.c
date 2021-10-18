#include <stdio.h>
#define br_elemenata 100
#include <math.h>

int main() {
	int velicina,t,k=0,s,br,br_clanova=0,i,y,niz[br_elemenata],nizBrojaca[10]={0};

	printf("Unesite velicinu niza: ");
	scanf("%d", &velicina);
	printf("Unesite clanove niza: ");
	
	for(i=0; i<velicina; i++){
		scanf("%d",&niz[i]);
	}
	
	for(i=0; i<velicina; i++){
	t=0;
		do{
			y=niz[i]%10;
			t=(t+y)*10;
			niz[i]=niz[i]/10;
			br_clanova=br_clanova+1;
		}while(niz[i]!=0);
	t=t/10;
	
	do{
			y=t%10;
			k=(k+y)*10;
			t=t/10;
		}while(t!=0);

	} br=k/10;	printf("%d\n",br);
	printf("%d",br_clanova);
	
	for (i=0; i<10; i++){
	
	do{
			s=br%10;
			nizBrojaca[s]++;
			br=br/10;
		}while(br!=0);	
		
		
	}
	
	
	
	return 0;
}
