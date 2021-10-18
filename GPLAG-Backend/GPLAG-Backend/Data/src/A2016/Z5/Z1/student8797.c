#include <stdio.h>
#include <string.h>

struct Student {
    char ime[20], prezime[20];
    int ocjene[50];
	int br_ocjena;
};

float funkcija_prosjek(struct Student s){
	float sum=0;
	int j=0;
	float p;
	if(s.br_ocjena==0) return 5;
		else {
			for(j=0;j<s.br_ocjena;j++){
				if(s.ocjene[j]==5) return 5; 
				sum=sum+s.ocjene[j];
			}
			p=sum/s.br_ocjena;
			
			
	return p;
}}


int genijalci(struct Student s[], int vel, float prosjek){
	int i=0, j=0, dokle=3;
	float pom_prosjek;
	int max[3];
	float maxprosjek;
	
	for(i=0;i<vel;i++){

		pom_prosjek=funkcija_prosjek(s[i]);
       
		if(pom_prosjek<prosjek){
			for(j=i;j<vel-1;j++){
				s[j]=s[j+1];
			}
			vel--;
			i--;
		}
	}
	if(vel<3)
	    dokle=vel;
	
	
	
	for (j=0; j<dokle; j++){
		maxprosjek=0;
		
		if(j==0){
			 for(i=0;i<vel;i++){
				
				pom_prosjek=funkcija_prosjek(s[i]);
				
				if(pom_prosjek>maxprosjek){
					max[j]=i;
					maxprosjek=pom_prosjek;}
					
				else if(pom_prosjek==maxprosjek){
					if(strcmp(s[i].prezime,s[max[j]].prezime)<0) max[j]=i;
					else if(strcmp(s[i].prezime,s[max[j]].prezime)==0){
							if(strcmp(s[i].ime,s[max[j]].ime)<0) max[j]=i;						
					}
				}	
			}
	    }
	    
	    if(j==1){
			 for(i=0;i<vel;i++){
				
				pom_prosjek=funkcija_prosjek(s[i]);
				
				if(pom_prosjek>maxprosjek && max[0]!=i){
					max[j]=i;
					maxprosjek=pom_prosjek;}
				else if(pom_prosjek==maxprosjek&& max[0]!=i){
					if(strcmp(s[i].prezime,s[max[j]].prezime)<0) max[j]=i; 
					else if(strcmp(s[i].prezime,s[max[j]].prezime)==0){
							if(strcmp(s[i].ime,s[max[j]].ime)<0) max[j]=i;						
					}  
				}	
			}
	    }
	    
	    if(j==2){
			 for(i=0;i<vel;i++){
				
				pom_prosjek=funkcija_prosjek(s[i]);
				
				if(pom_prosjek>maxprosjek && max[0]!=i && max[1]!=i){
					max[j]=i;
					maxprosjek=pom_prosjek;}
				else if(pom_prosjek==maxprosjek && max[0]!=i && max[1]!=i){
					if(strcmp(s[i].prezime,s[max[j]].prezime)<0) max[j]=i; 
					else if(strcmp(s[i].prezime,s[max[j]].prezime)==0){
							if(strcmp(s[i].ime,s[max[j]].ime)<0) max[j]=i;						
					} 
				}	
			}
	    }
	}
	
	
	
	
	
	for(j=0;j<dokle;j++){
		for(i=0;i<vel;i++){
			if(i==max[j]){
				printf("%s %s\n", s[i].prezime, s[i].ime);
			}
		}
	}
	
	return vel;
}



int main() {
	
    struct Student studenti[5] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,8,8}, 5}, 
};
    printf("Ostalo: %d",genijalci(studenti, 6, 7));
	return 0;
}
