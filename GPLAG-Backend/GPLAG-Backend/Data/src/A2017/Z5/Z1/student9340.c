#include <stdio.h>
#include <stdio.h>
#include <math.h>

struct Datum {
    int dan, mjesec, godina 
    
};

struct Uposlenik {
   	char ime_prezime[50];
   	struct Datum datum_rodjenja;
};
   
   
int suzi_listu (struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana){
   	int i,j,k,brojac,brojac2, brojac3, brojac_direktor, brojac4, brojac5, brojac6;
   	for (i=0; i<vel; i++){
   	
   		if (kandidati[i].datum_rodjenja.godina > direktor.datum_rodjenja.godina) continue;
   		
   		else if (kandidati[i].datum_rodjenja.godina == direktor.datum_rodjenja.godina){
   			  brojac=0; 
   			  brojac2=0; 
   			  for (k=1; k<=kandidati[i].datum_rodjenja.mjesec; k++){
   			     if (k==kandidati[i].datum_rodjenja.mjesec){
   			  		 brojac2+=kandidati[i].datum_rodjenja.dan;
   			  		 continue;
   			  	 }
   			  	 if (k==2) {                      /* FEBRUAR */
   			  	 	brojac_direktor = kandidati[i].datum_rodjenja.godina;
   			  	 	if (brojac_direktor%4==0 && brojac_direktor%100!=0 || brojac_direktor%4==0 && brojac_direktor%400==0){
   			  	 		brojac2+=29;
   			  	 	}
   			  	 	else {
   			  	 		brojac2+=28;
   			  	 	}
   			  	 }
   			  	 else if (k==1 || k==3 || k==5 || k==7 || k==8 || k==10 || k==12){
   			  	 	brojac2+=31;
   			  	 }
   			  	 else {
   			  	 	brojac2+=30;
   			  	 }
   			  	 }
   			  
   			  	 
   			  	 
   			  	 
   			  	 brojac3=0;
   			  	     for (k=1; k<=direktor.datum_rodjenja.mjesec; k++){
   			  	     	if (k==direktor.datum_rodjenja.mjesec){
   			  	     		brojac3+=direktor.datum_rodjenja.dan;
   			  	     		continue;
   			  	     	}
   			  	     	
   			  	     	if (k==2){
   			  	     		brojac_direktor == direktor.datum_rodjenja.godina;
   			  	     	if (brojac_direktor%4==0 && brojac_direktor%100!=0 || brojac_direktor%4==0 && brojac_direktor%400==0){
   			  	     		brojac3+=29;
   			  	     	}
   			  	     	else {
   			  	     		brojac3+=28;
   			  	     	}
   			  	     	}
   			  	     	else if (k==1 || k==3 || k==5 || k==7 || k==8 || k==10 || k==12 ){
   			  	     		brojac3+=31;
   			  	     	}
   			  	     	else {
   			  	     		brojac3+=30;
   			  	     	}
   			  	     }
   			  	     
   			  	     
   			  	     if (brojac3 - brojac2 > broj_dana){ /* Ako je stariji za broj dana izbaci */
   			  	     	  for (k=i; k<vel-1; k++){
   			  	     	  	kandidati[k] = kandidati[k+1];
   			  	     	  }
   			  	     	  vel--;
   			  	     	  i--;
   			  	     }
   			  	     
   			  	     
   			  	     continue;
   			  }
   			  
   			  /* Sljedeci dio koda za godine koje su ispod direktorove godine rodjenja*/
   			  brojac = 0;
   			  for (j=kandidati[i].datum_rodjenja.godina; j<=direktor.datum_rodjenja.godina; j++){
   			      if (j%4==0 && j%100!=0 || j%4==0 && j%400==0) brojac+=366;
   			      else brojac+=365;
   			  }
   			  brojac2=0; 
   			  for (k=1; j<=kandidati[i].datum_rodjenja.mjesec; k++){
   			      if (k==kandidati[i].datum_rodjenja.mjesec){
   			          brojac2+=kandidati[i].datum_rodjenja.dan;
   			          continue;
   			      }
   			      
   			      if (k==2){
   			          brojac_direktor = kandidati[i].datum_rodjenja.godina;
   			          if (brojac_direktor%4==0 && brojac_direktor%100!=0 || brojac_direktor%4==0 && brojac_direktor%400==0){
   			              brojac2+=29;
   			          }
   			          else {
   			              brojac2+=28;
   			          }
   			      }
   			      else if (k==1 || k==3 || k==5 || k==7 || k==8 || k==10 || k==12 ){
   			          brojac2+=31;
   			      }
   			      else {
   			          brojac2+=30;
   			      }
   			  }
   			  brojac = brojac-brojac2;
   			  
   			  brojac2 = 0;
   			  for (k=1; k<=direktor.datum_rodjenja.mjesec; k++){
   			      if (k==direktor.datum_rodjenja.mjesec){
   			          brojac2+=direktor.datum_rodjenja.dan;
   			          continue;
   			      }
   			      if (k==2){
   			          brojac_direktor = direktor.datum_rodjenja.godina;
   			          if (brojac_direktor%4==0 && brojac_direktor%100!=0 || brojac_direktor%4==0 || brojac_direktor%400==0){
   			              brojac2+=29;
   			          }
   			          else {
   			              brojac2+=28;
   			          }
   			      }
   			      else if (k==1 || k==3 || k==5 || k==7 || k==8 || k==10 || k==12){
   			          brojac2+=31;
   			      }
   			      else {
   			          brojac2+=30;
   			      }
   			  }
   			  
   			  
   			  
   			  if (direktor.datum_rodjenja.godina%4==0 && direktor.datum_rodjenja.godina%100!=0 || direktor.datum_rodjenja.godina%4==0 && direktor.datum_rodjenja.godina%400==0){
   			      brojac2=366-brojac2;
   			  }
   			  else {
   			      brojac2 = 365 - brojac2;
   			  }
   			  
   			  
   			  brojac = brojac-brojac2;
   			  if (brojac > broj_dana){
   			      brojac=0;
   			      brojac2=0; 
   			      brojac3=0;
   			      brojac4=0;
   			      while (kandidati[i].ime_prezime[brojac]!='\0'){
   			          brojac++;
   			      }
   			      while (direktor.ime_prezime[brojac2]!='\0'){
   			          brojac2++;
   			      }
   			      while (kandidati[i].ime_prezime[brojac]!=' ') brojac--; 
   			      while (direktor.ime_prezime[brojac2]!=' ') brojac2--;
   			      brojac++;
   			      brojac2++;
   			      brojac3=brojac;
   			      brojac4=brojac2;
   			      brojac5=brojac;
   			      brojac6=brojac2;
   			      while (kandidati[i].ime_prezime[brojac3]!='-' && kandidati[i].ime_prezime[brojac3] != '\0') brojac3++;
   			      while (direktor.ime_prezime[brojac4] != '-' && direktor.ime_prezime[brojac4]!='\0')brojac4++;
   			      brojac3++;
   			      brojac4++;
   			      while (kandidati[i].ime_prezime[brojac]==direktor.ime_prezime[brojac2]&&kandidati[i].ime_prezime[brojac]!='\0' && direktor.ime_prezime[brojac2]!='\0'){
   			          brojac++;
   			          brojac2++;
   			      }
   			      
   			      
   			      if (kandidati[i].ime_prezime[brojac]=='-' && direktor.ime_prezime[brojac2]=='\0') continue;
   			      if (kandidati[i].ime_prezime[brojac]=='\0' && direktor.ime_prezime[brojac2]=='-') continue;
   			      if (kandidati[i].ime_prezime[brojac]=='\0' && direktor.ime_prezime[brojac2]=='\0') continue;
   			      brojac2=brojac4;
   			      brojac=brojac5;
   			      while (direktor.ime_prezime[brojac2] == kandidati[i].ime_prezime[brojac]&& direktor.ime_prezime[brojac2]!='\0'){
   			          brojac2++;
   			          brojac++;
   			      }
   			      if (direktor.ime_prezime[brojac2]=='\0' && kandidati[i].ime_prezime[brojac]=='\0')continue;
   			      brojac=brojac3;
   			      brojac2=brojac6;
   			      
   			      while (direktor.ime_prezime[brojac2]==kandidati[i].ime_prezime[brojac] && kandidati[i].ime_prezime[brojac]!='\0'){
   			          brojac++;
   			          brojac2++;
   			      }
   			      if (direktor.ime_prezime[brojac2]=='\0' && kandidati[i].ime_prezime[brojac]=='\0')continue;
   			      while (kandidati[i].ime_prezime[brojac3] == direktor.ime_prezime[brojac6] && kandidati[i].ime_prezime[brojac3]!='\0'){
   			          brojac3++;
   			          brojac6++;
   			      }
   			      if (kandidati[i].ime_prezime[brojac3] == '\0' && direktor.ime_prezime[brojac6]=='-') continue;
   			      
   			      while (kandidati[i].ime_prezime[brojac4] == direktor.ime_prezime[brojac5] && kandidati[i].ime_prezime[brojac4]!='\0'){
   			          brojac4++;
   			          brojac5++;
   			      }
   			      
   			      if (kandidati[i].ime_prezime[brojac4] == '\0' && direktor.ime_prezime[brojac5] == '-') continue;
   			      
   			      for (k=i; k<vel-1; k++){
   			          kandidati[k]=kandidati[k+1];
   			      }
   			      vel--;
   			      i--;
   			  }
   			  
   		}
   		
   		return vel;
   	}
   	
int main (){
	
	return 0;
}