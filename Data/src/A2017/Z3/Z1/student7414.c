#include <stdio.h> 
           
         
int dva_od_tri(int *niz1,int vel1,int *niz2,int vel2,int *niz3,int vel3){
	int brojac = 0,i,j,k,l,cs;
	
	for(i = 0; i < vel1; i++){
		cs = 0; 
		
		for(j = 0; j < vel2; j++)
			if(niz1[i] == niz2[j]){ cs = 1; break;}
			
		for(k = 0; k < vel3; k++)
			if(niz1[i] == niz3[k]){cs = 0; break;}
			
		for(l = 0; l < i; l++)
			if(niz1[i]==niz1[l]){cs = 0; break;}
			
		if(cs)brojac++;
	}
	
	for(i = 0; i < vel2; i++){ 
		cs = 0; 
		for(j = 0; j < vel3; j++) 
			if(niz2[i] == niz3[j]){ cs = 1; break;} 
		for(k = 0; k < vel1; k++) 
			if(niz2[i] == niz1[k]){cs = 0; break;} 
		for(l = 0; l < i; l++) 
			if(niz2[i]==niz2[l]){cs = 0; break;} 
		if(cs)brojac++; 
	} 
	 
	for(i = 0; i < vel1; i++){ 
		cs = 0; 
		for(j = 0; j < vel3; j++) 
			if(niz1[i] == niz3[j]){ cs = 1; break;} 
		for(k = 0; k < vel2; k++) 
			if(niz1[i] == niz2[k]){cs = 0; break;} 
		for(l = 0; l < i; l++) 
			if(niz1[i]==niz1[l]){cs = 0; break;} 
		if(cs)brojac++; 
	} 
	
	return brojac;
}
      

int main() {
	int vel1=4,vel2=5,vel3=6,niz1[100]={1,2,3,5},niz2[100]={1,2,4,6,7},niz3[100]={1,3,4,8,9,10},rez,i;
	/*
	for(i = 0; i < vel1; i++)scanf("%d",&niz1[i]);
	for(i = 0; i < vel2; i++)scanf("%d",&niz2[i]);
	for(i = 0; i < vel3; i++)scanf("%d",&niz3[i]);
	*/
	rez = dva_od_tri(niz1,vel1,niz2,vel2,niz3,vel3);
	printf("%d",rez);
	return 0;
}
