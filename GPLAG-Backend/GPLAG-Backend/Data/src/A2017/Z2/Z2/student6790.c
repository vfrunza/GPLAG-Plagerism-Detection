#include <stdio.h>
#define DUZINA1  100
#define DUZINA2 1000

int main() {
	int pniz[DUZINA1],fniz[DUZINA2];
	int i,n,x=0;
	
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
	
	printf("Unesite clanove niza: ");
	while(x<n) {
	   int clan;
	   scanf("%d",&clan);
	   if(clan<0) continue;
	   pniz[x]=clan;
	   x++;
	} 
	
	for(i=0;i<n;i++) {
		
	}
	
	for(i=0;i<n;i++) {
		printf("%d ",pniz[i]);
	}
	
	
	
	
	return 0;
}
