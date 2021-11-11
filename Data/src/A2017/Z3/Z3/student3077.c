#include <stdio.h>
#include <stdlib.h> 

int ima_li(int broj, int niz[], int vel){
	int i; 
	for(i=0; i<vel; i++){
		if(broj == niz[i]) return 1; 
	}
	return -1; 
}

int rastavi_na_cifre(int clan_niza, int nizcifara[], int vel){
	int tmp=abs(clan_niza);
	int uredjen=0, pom=0; 
	int krajnji =0; 
	while(tmp!=0 ){
		pom = tmp %10; 
		tmp = tmp /10; 
		if((ima_li(pom, nizcifara, vel)) == 1 ) continue; 
		uredjen = uredjen*10 + pom; 
	}
	
	while(uredjen != 0){
	int pom; 
	pom = uredjen %10; 
	uredjen = uredjen / 10; 
	krajnji = krajnji * 10 + pom; 
	}
	if(clan_niza < 0) krajnji = krajnji * -1; 
	
	
	return krajnji;
}


int izbaci_cifre(int niz1[], int vel1, int niz2[], int vel2){
	int i; 
	int j; 
	for(i = 0; i < vel2; i++){
		
		if(niz2[i] < 0 || niz2[i] > 9)  return 0; 
	for(j=i+1; j < vel2; j++) if(niz2[j]==niz2[i]) return 0; 
		
	}
	
	for(i=0; i < vel1; i++){
		niz1[i] = rastavi_na_cifre(niz1[i], niz2, vel2); 
	}
	
	return 1; 
}

int main(){
return 0; 
}

