#include <stdio.h>


int dva_od_tri(int *niz1,int vel1,int *niz2,int vel2,int *niz3,int vel3) {

	int i,j,NewNiz[100],counter=0;
	int OneOf3=0,TwoOf3=0;
    /* IZBACUJE DUPLIKATE IZ PRVOG NIZA*/
	for(i=0;i<vel1;i++){
	    for(j=0;j<counter;j++)
	        if(niz1[i]==NewNiz[j])break;
	         if(j==counter)NewNiz[counter++]=niz1[i];  
	    	
		}
	  /* IZBACUJE DUPLIKATE IZ DRUGOG NIZA*/
	for(i=0;i<vel2;i++){
	    for(j=0;j<counter;j++){
	        if(niz2[i]==NewNiz[j])break;
	        if(j==counter)NewNiz[counter++]=niz2[i];
	        }
	    }

	   /* IZBACUJE DUPLIKATE IZ TRECEG NIZA*/
	for(i=0;i<vel3;i++){
	    for(j=0;j<counter;j++)
	        if(niz3[i]==NewNiz[j])break;
	         if(j==counter)NewNiz[counter++]=niz3[i]; 
	    }
	    j=0;
	    /*GLEDA BROJEVE KOJI SE PONAVLJAJU U NIZOVIMA*/
	for(i=0;i<counter;i++){
		OneOf3=0;
		for(j=0;j<vel1;j++){
			if(niz1[j]==NewNiz[i]){
				OneOf3++;
				break;
				}	
			}
		for(j=0;j<vel2;j++){
			if(niz2[j]==NewNiz[i]){
				OneOf3++;
				break;
				}
			}
		for(j=0;j<vel3;j++){
			if(niz3[j]==NewNiz[i]){
				OneOf3++;
				break;
			}	
			
		}
		/*UZIMA SAMO ONE KOJI SU SE PONOVILI 2 PUTA*/
	    if(OneOf3==2)TwoOf3++;  
	  }
	 return TwoOf3;
}
int main(){
    
    return 0;
}