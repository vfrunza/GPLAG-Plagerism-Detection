#include <iostream>
#include <vector>
#include <string>
#include <new>
#include <stdexcept>
int DodajOptuzbu(char **&pokz, int broj, std::string ime){
	int pokaz{0}, j{0}, ind(ime.size()+1), brojac1{0}, brojac{0}, brojac2{0};
	try{
	    char *niz1(new char);
	    niz1=new char[ind];
	    for(int i=0; i<ind; i++) niz1[i]=ime[i];
  	    for(int i=0; i<broj; i++){
         if(brojac==0 && pokz[i]==nullptr){
      	  pokaz=1;
      	  pokz[i]=new char[ime.size()+1];
      	  while(niz1[j]!='\0'){
      	   pokz[i][j]=niz1[j];
           j++;
          }
          brojac=1;
         }
	    }
	   if(pokaz==0){
	   	brojac1=1;
		char **niz(new char*[broj+1]);
		for(int i=0; i<broj+1; i++){
		 j=0;	
		 if(i<broj){	
			brojac2=0;
			while(pokz[i][j]!='\0'){brojac2++; j++;} 
			niz[i]=new char[brojac2];
			j=0;
			while(pokz[i][j]!='\0'){
				niz[i][j]=pokz[i][j];
				j++;
			}
		 }
		 else{
		 	niz[i]=new char[ime.size()];
		 	j=0;
		 	while(niz1[j]!='\0') {niz[broj][j]=niz1[j]; j++;}
		 	delete []niz1;
		 }
		}
	  for(int i=0; i<broj; i++) delete []pokz[i];
	  delete []pokz;
	  pokz=niz;
	  if(pokaz==0) {
	  	for(int i=0; i<broj+1; i++) delete []niz[i];
	  	delete []niz;
	  }
	 }
	}
	catch(std::bad_alloc){
		std::cout <<"Neuspjela alokacija"<<std::endl;
	}
	if(brojac1==1){ broj=broj+1;}
	return broj;
}
int OdbaciOptuzbu(char **&pokz, int broj, std::string ime){
	int j{0}, ind{0}, pokaz{0}, brojac{0}, brojac1{0};
	std::string poruka;
	std::string poruka1{"Osoba sa imenom "};
	std::string poruka2{" nije bila optuzena"};
	poruka=poruka1+ime+poruka2;
	try{
	for(int i=0; i<broj; i++){
	 while(pokz[i][j]!='\0'){
	 	if(pokz[i][j]==ime[j]) {ind++; j++;}
        else if(j>ime.size()-1){break;}
	 	 else{j++;}
	 }	
	 if(ind==j){
      delete []pokz[i];
	  pokz[i]=nullptr;
	  pokaz=1;
	  brojac1++;
	 }
	 ind=0;
	 j=0;
	}
	if(pokaz==0) throw std::domain_error(poruka);
	for(int i=0; i<broj; i++){
		if(pokz[i]==nullptr) brojac++;
	}
	if(brojac<=10){}
	else{
     char **niz(new char*[broj]);		
	 for(int i=0; i<broj; i++){
	 	j=0;
	 	while(pokz[i][j]!='\0'){
	 		niz[i][j]=pokz[i][j];
	 		j++;
	 	}
	 }
     pokz=niz;
	 for(int i=0; i<broj; i++) delete []niz[i];
	 delete []niz;
	}
	}
	catch(std::domain_error izuzetak){
		std::cout <<izuzetak.what()<<std::endl;
	}
	return broj;
}
void IzlistajOptuzbu(char **pokz, int broj){
	int j{0}, ind{0};
	for(int i=0; i<broj; i++){
        if(pokz[i]==nullptr){ind=1;}
	    else while(pokz[i][j]!='\0'){
	       std::cout <<pokz[i][j];
	       j++;
	 }
     if(ind==0) std::cout <<std::endl;
	 else ind=0;
	j=0;
	}
}
int PotencijalniKrivci(char **&pokz, std::vector<std::string> ime){
    int broj(ime.size()), j{0}; 
	 try{
 	   pokz=new char *[broj];
 	   try{
    	 for(int i=0; i<broj; i++) pokz[i]=new char[ime[i].size()+1];
 	     for(int i=0; i<broj; i++){
 	   		for(j=0; j<ime[i].size()+1; j++){
 	   			pokz[i][j]=ime[i][j];
 	   		}
 	   	} 
 	   	return broj; 
 	   }
 	   catch(std::bad_alloc){
 	   	throw;
 	   }
 }
 catch(std::bad_alloc){
 	std::cout <<"Neuspjela alokacija"<<std::endl;
 }
 return broj;
}
int main (){
    	int broj, n{0}, izbor{-1};
  	    std::vector<std::string> ime;
  	    std::cout <<"Koliko potencijalnih krivaca zelite unijeti? ";
  	    std::cin >>n;
        char **niz=nullptr;
       try{
  		std::cin.ignore(10000, '\n');
  	    std::cout<<"Unesite potencijalne krivce: "<<std::endl;
  	    std::string pomoc;
  	    for(int i=0; i<n; i++){
  	    	std::getline(std::cin, pomoc);
  	    	ime.push_back(pomoc);
  	    	if(i==n-1) break;
  	    }
  	    std::string krivac;
  	    std::string novi;
  	    broj=PotencijalniKrivci(niz, ime);
  	    while(izbor!=0){
  	    	std::cout <<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
  	    	std::cin >>izbor;
  	    	std::cin.ignore(10000,'\n');
  	    	switch(izbor){
  	    		case 1:
  	    		 std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
  	    		 std::getline(std::cin,novi);
  	    		 broj=DodajOptuzbu(niz, broj, novi);
  	    		 break;
  	    		case 2:
  	    		 std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
  	    		 std::getline(std::cin, krivac);
  	    		 broj=OdbaciOptuzbu(niz,broj,krivac);
  	    		 break;
  	    		case 3:
  	    		 IzlistajOptuzbu(niz, broj);
  	    		 break;
  	    		case 0:
  	    		 break;
  	    		default: std::cout <<"Pogresan izbor!"; 
  	    	}
  	    }
	}
	catch(std::bad_alloc){
		std::cout<<"Neuspjela alokacija"<<std::endl;
 }
 for(int i=0; i<broj; i++) delete []niz[i];
	delete [] niz;
	return 0;
}