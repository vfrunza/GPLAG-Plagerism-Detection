#include <stdio.h>
#define MAX_SIZE 100

int main() {
int vel, i, j;
int niz[MAX_SIZE];
int brojac=1;
int tmp_niz[1000];
	do{
	printf("Unesite velicinu niza: ");
	scanf("%d,", &vel);
	printf("Unesite clanove niza: ");
	for(i=0; i<vel; i++){
		scanf("%d", &niz[i]);
		if(niz[i] <= 0){
			printf("Ponovite unos: ");
				for(i=1; i<vel; i++){
					scanf("%d", &vel);	
				}			
		}
		
while(niz[i] > 0){
		for(i=0; i<tmp_niz[1000]; i++){
		brojac=1;
			if(niz[i]==niz[i+1])
				brojac++;
		}
		for(j=i+1; j<tmp_niz[1000]; j++){
			if(niz[j]==niz[j+1]){
				brojac++; 
				
			}
		}	i=i+(brojac-1);
	
	}
		
	

	return 0;
	}
