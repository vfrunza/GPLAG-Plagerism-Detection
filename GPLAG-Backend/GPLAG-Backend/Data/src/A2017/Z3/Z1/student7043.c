#include <stdio.h>


int dva_od_tri (int niz1[],int vel_1,int niz2[],int vel_2,int niz3[],int vel_3){
	int i,j,k,ima1_2=0,ima1_3=0,ima2_3=0,brojac=0,temp=0,niz_1[30],niz_2[30],niz_3[30],zamjena=0;
	for (i=0;i<vel_1;i++)
		niz_1[i]=niz1[i];
	for (i=0;i<vel_2;i++)
		niz_2[i]=niz2[i];
	for (i=0;i<vel_3;i++)
		niz_3[i]=niz3[i];
	
	for(i=0;i<vel_1;i++){
		for (j=0;j<vel_1;j++){
			if (i!=j){
				if (niz_1[i]==niz_1[j]){
					zamjena=niz_1[j];
					niz_1[j]=niz_1[vel_1-1];
					niz_1[vel_1-1]=zamjena;
					vel_1--;
					j--;
				}
			}
		}
	}
		for(i=0;i<vel_2;i++){
		for (j=0;j<vel_2;j++){
			if (i!=j){
				if (niz_2[i]==niz_2[j]){
					zamjena=niz_2[j];
					niz_2[j]=niz_2[vel_2-1];
					niz_2[vel_2-1]=zamjena;
					vel_2--;
					j--;
				}
			}
		}
	}
		for(i=0;i<vel_3;i++){
		for (j=0;j<vel_3;j++){
			if (i!=j){
				if (niz_3[i]==niz_3[j]){
					zamjena=niz_3[j];
					niz_3[j]=niz_3[vel_3-1];
					niz_3[vel_3-1]=zamjena;
					vel_3--;
					j--;
				}
			}
		}
	}
	
	
	
	
	
	for (i=0;i<vel_1;i++){                                                                                             
	      for (j=0;j<vel_2;j++){
	      	if (niz_1[i]==niz_2[j])  {
	      		temp=niz_1[i];
	      
	  	      	    for (k=0;k<vel_3;k++){
	    				ima1_3=0;
	      				if(niz_3[k]==temp){
	      					ima1_3=1;
	      					break;
	      				}		
	      				}
	      				if (ima1_3==0){
	      					brojac=brojac+1;
	      				}}}}
	      				
	for (i=0;i<vel_1;i++){                                                                                             
	      for (j=0;j<vel_3;j++){
	      
	      	if (niz_1[i]==niz_3[j]) {
	      		temp=niz_1[i];
	      		for (k=0;k<vel_2;k++){
	      			ima1_2=0;
	      				if(niz_2[k]==temp){
	      					ima1_2=1;
	      					break;
	      				}		
	      				}if (ima1_2==0){
	      					brojac=brojac+1;
	      				}}}}
	for (i=0;i<vel_2;i++){                                                                                             
	      for (j=0;j<vel_3;j++){
	      	
	      	if (niz_2[i]==niz_3[j]) {
	      		temp=niz_2[i];
	      		for (k=0;k<vel_1;k++){
	      			ima2_3=0;
	      				if(niz_1[k]==temp){
	      					ima2_3=1;
	      					break;
	      				}		
	      				}if (ima2_3==0){
	      					brojac=brojac+1;
	      				}  }}}
	return brojac;
}

int main() {
	int niz1[30],niz2[30],niz3[30],vel_1=0,vel_2=0,vel_3=0,i=0;
	printf("Unesite velicine nizova:");
	scanf("%d%d%d",&vel_1,&vel_2,&vel_3);
	printf("\nUnesite clanove prvog niza");
	for (i=0;i<vel_1;i++){
		scanf("%d",&niz1[i]);
	}
	printf("\nUnesite clanove drugog niza");
	for (i=0;i<vel_2;i++){
		scanf("%d",&niz2[i]);
	}
	printf("\nUnesite clanove trece niza");
	for (i=0;i<vel_3;i++){
		scanf("%d",&niz3[i]);
	}
	printf ("Funkcija vraca broj %d",dva_od_tri ( niz1,vel_1, niz2,vel_2, niz3, vel_3));
	return 0;
}
