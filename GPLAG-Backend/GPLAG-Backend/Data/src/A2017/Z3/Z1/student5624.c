#include <stdio.h>
#include <stdbool.h>
bool da_li_je_u_nizu(int clan, int niz1[], int vel){
	int i;
	for(i = 0; i<vel; i++){
		if(niz1[i]==clan) return true;
	}
	return false;
}

int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3){
	int i,j;
	int niz1_n[100];
	int pozicija_pom=0;
	int vel_pom=0;
	for(i=0; i<vel1;i++){
		if(i==0) {
			niz1_n[pozicija_pom] = niz1[i];
			pozicija_pom++;
			vel_pom++;
		}
		else if(!da_li_je_u_nizu(niz1[i], niz1_n, vel_pom)){ 
			niz1_n[pozicija_pom]=niz1[i];
			pozicija_pom++;
			vel_pom++;
		}
	}
	int niz2_n[100];
	pozicija_pom=0;
	int vel_pom2=0;
	for(i = 0; i<vel2; i++){
		if(i==0){
			niz2_n[pozicija_pom]=niz2[i];
			pozicija_pom++;
			vel_pom2++;
		}
		else if(!da_li_je_u_nizu(niz2[i], niz2_n, vel_pom2)){
			niz2_n[pozicija_pom] = niz2[i];
			pozicija_pom++;
			vel_pom2++;
		}
	}
	int niz3_n[100];
	pozicija_pom=0;
	int vel_pom3=0;
	for(i = 0; i<vel3; i++){
		if(i==0){
			niz3_n[pozicija_pom]=niz3[i];
			pozicija_pom++;
			vel_pom3++;
		}
		else if(!da_li_je_u_nizu(niz3[i], niz3_n, vel_pom3)){
			niz3_n[pozicija_pom]=niz3[i];
			pozicija_pom++;
			vel_pom3++;
		}
	}
	int vel_s=vel_pom+vel_pom2+vel_pom3;
	int spojeni_niz[300];
	int pozicija_s=0;
	for(i=0;i<vel_pom;i++){
		spojeni_niz[pozicija_s]=niz1_n[i];
		pozicija_s++;
	}
	for(i=0;i<vel_pom2;i++){
		spojeni_niz[pozicija_s]=niz2_n[i];
		pozicija_s++;
	}
	for(i=0;i<vel_pom3;i++){
		spojeni_niz[pozicija_s]=niz3_n[i];
		pozicija_s++;
	}
	int temp;
	for(i=0;i<vel_s-1;i++){
		for(j=0;j<vel_s-i-1;j++){
			if(spojeni_niz[j]>spojeni_niz[j+1]){
			 	temp=spojeni_niz[j+1];
			 	spojeni_niz[j+1]=spojeni_niz[j];
			 	spojeni_niz[j]=temp;
			}
		}
	}
	int	brojac_el=0;
	int brojac=0;
	for(i = 0; i<vel_s; i++){
		if(i==0){
			brojac_el++;
			continue;
		}
		if(spojeni_niz[i]==spojeni_niz[i-1]){ 
			brojac_el++;
		}
		if (spojeni_niz[i]!=spojeni_niz[i-1] || i == vel_s-1){
			if(brojac_el==2) {
				brojac++;
				brojac_el=1;
			}
			else{
			 	brojac_el=1;
			}
		}
	}
	return brojac;	
}
int main() {
	int niz1[]={1,1,1,1,1,1,1,1,1,1,2,3,4};
	int niz2[]={1,3,4,5,6};
	int niz3[]={6,4,3,1};
	int rez= dva_od_tri(niz1,13,niz2,5,niz3,4);
	printf("%d",rez);
	return 0;
}
