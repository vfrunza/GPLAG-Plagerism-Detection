#include <stdio.h>
#define epsilon 0.0001
#include <string.h>

struct Student{    
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};


/*Funckija racuna prosjek svakog studenta pojedinacno u zavsnosti koliko ima ocjena*/
float prosjek(int niz[],int vel){   
	int i=0,suma=0;
	if (vel==0) return 5;           
	for(i=0;i<vel;i++){
		if (niz[i]==5) return 5;    
		suma+=niz[i];     
	}
	return (float)suma/vel;         
}

/*Funkcija prima 2 studenta, vraca 1 ako prvi treba biti ispred drugog, odnosno 0 ako ne treba*/
int dalijeveci(struct Student pr, struct Student dr){  
     
        if(prosjek(pr.ocjene,pr.br_ocjena)>prosjek(dr.ocjene,dr.br_ocjena)) return 1;       
        if(prosjek(pr.ocjene,pr.br_ocjena)<prosjek(dr.ocjene,dr.br_ocjena)) return 0;       
  
     
        if(strcmp(pr.prezime,dr.prezime)>0) return 0;
        else if(strcmp(pr.prezime,dr.prezime)<0) return 1;
           
        
       
        if(strcmp(pr.ime,dr.ime)>0) return 0;            
        else if(strcmp(pr.ime,dr.ime)<0) return 1;
        else return 1;          
}
/*Funkcija prima niz struktura, velicinu niza i zadani prosjek*/
int genijalci(struct Student niz[], int vel, double prosjekk){  
    int i,j,indexprvi,indexdrugi,indextreci,indexmin=0;
    double maxprvi, maxdrugi, maxtreci,temp_prosjek,min=10;
	
	/*Izbacivanje iz niza ako je prosjek manji od zadanog*/
	for(i=0;i<vel;i++){ 
		if(prosjekk-prosjek(niz[i].ocjene,niz[i].br_ocjena)>epsilon) {         
                for(j=i;j<vel-1;j++){           
                    niz[j]=niz[j+1];
                }
			vel--;
			i--;
		}
	}
  /*Trazimo min i upamtimo mu indeks*/
  for(i=0;i<vel;i++){ 
  float temp=prosjek(niz[i].ocjene,niz[i].br_ocjena);
      	if(min-temp>epsilon) {
      	    min=temp; indexmin=i;
      	}
  }
    
    /*Pamtimo index prvog clana tj najveceg studenta*/
    float max=5;
	if(vel>0) { 
	 indexprvi=indexmin;        
    for(i=0;i<vel;i++){
        int vr=dalijeveci(niz[i],niz[indexprvi]);
        if(vr==1)      
            indexprvi=i;     
            max=prosjek(niz[i].ocjene,niz[i].br_ocjena);
	}
	
	/*Ispis najboljeg studenta*/
	if(i>0)
	printf("\n%s %s\n",niz[indexprvi].prezime,niz[indexprvi].ime);  
	}
	
	/*Ako je velicina veca od 1, treba jos jednog minimalno ispisati*/
	if(vel>1){ 
	indexdrugi=indexmin;
	for(i=0;i<vel;i++){
	    if(i==indexprvi) continue;  
	     int vr=dalijeveci(niz[i],niz[indexdrugi]);
        if(vr==1) 
        
            indexdrugi=i;
            max=prosjek(niz[i].ocjene,niz[i].br_ocjena);
        }
	
		printf("%s %s\n",niz[indexdrugi].prezime,niz[indexdrugi].ime);
	}
	/*Ako je velicina 3 ili vise, ispisujemo i treceg studenta*/
	if(vel>2){ 
    indextreci=indexmin;
    for(i=0;i<vel;i++){
        if(i==indexprvi ||i==indexdrugi) continue;      
         int vr=dalijeveci(niz[i],niz[indextreci]);
        if(vr==1) 
        
            indextreci=i;
            max=prosjek(niz[i].ocjene,niz[i].br_ocjena);
	}
     if(i>0)    
    	printf("%s %s\n",niz[indextreci].prezime,niz[indextreci].ime);
	}

 return vel;
}


int main() {
    struct Student studenti[5] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Eso", "Esic", { 10, 10, 10, 10, 5}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
};
genijalci(studenti, 5, 6.5);
 
	return 0;
}
