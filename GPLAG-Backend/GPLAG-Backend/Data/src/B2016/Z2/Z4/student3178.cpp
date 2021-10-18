#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <memory>
#include <string>
#include <vector>
#include <new>

int PotencijalniKrivci(char**& mat, std::vector<std::string> imena){

try{
	mat = new char* [imena.size()];
	try{
		for(int i=0; i<imena.size(); i++)
	    	mat[i] = new char[imena[i].size() + 1];
	    	
	}catch(std::bad_alloc bd){
		delete[] mat;
		throw bd;
	}
	}catch(std::bad_alloc bd){
		throw bd;
    }
    for(int i=0; i<imena.size(); i++){
    	for(int j=0; j<imena[i].size(); j++){
    		mat[i][j] = imena[i][j];
    	}
    	mat[i][imena[i].size()] = '\0';
    }
    return imena.size();
}

bool JednakiSu(char* p, std::string ime){
	if(p == nullptr) return false;
	int i{0};
	while(i<ime.length() && p[i] !='\0'){
		if(p[i] != ime[i]) return false;
		i++;
	}
	if(p[i] != '\0' || ime.length() != i) return false;
	
    return true;	
}
  
  int DajVelicinu(char* p){
  	int i{0};
  	while(p[i] != '\0') i++;
  	return i;
  }

int OdbaciOptuzbu(char**& mat, int vel, std::string ime){

   int brNull(0);
   bool nadjen=false;
   for(int i=0; i<vel; i++){
      	if(mat[i] == nullptr)
   	       brNull++;
   	       
   	    if(JednakiSu(mat[i],ime)){
   	    	delete[] mat[i];
   	    	mat[i] = nullptr;
   	    	brNull++;
   	    	nadjen=true;
   	    }
   }
   	 
   if(!nadjen)
       throw std::domain_error("Osoba sa imenom " + ime + " nije bila optuzena");
   if(brNull >= 10){
     	try{
   		    char** tmpP = new char*[vel- brNull];
   		    int tmpBr = 0;
   		    try{
   		    	for(int i=0; i<vel; i++){
   		    		if(mat[i] != nullptr){
   		    			int k = DajVelicinu(mat[i]);
   		    			tmpP[tmpBr] = new char[k+1];
   		    			while(k>=0){
   		    				 tmpP[tmpBr][k] = mat[i][k];
   		    				 k--;
   		    			}
   		    			tmpBr++;
   		    		}
   		    	}
   		    }catch(std::bad_alloc bd){
   		    	
   		    	for(int i=0; i<tmpBr; i++)
   		    	    delete[] tmpP[i];
   		    	    
   		    	delete[] tmpP;
   		    	throw bd;
   		    	
   		    }
   		    
   		    for(int i=0; i<vel; i++)
   		        delete[] mat[i];
   		        
   		    delete[] mat;
   		    
   		    mat = tmpP;
   		    vel = tmpBr;
     	}catch(std::bad_alloc bd){}
   }
   return vel;
}
   		    

int DodajOptuzbu(char**& mat, int vel, std::string ime){
	try{
		char* novi = new char[ime.length() + 1];
		
		for(int i=0; i<ime.length(); i++)
		    novi[i] = ime[i];
		novi[ime.length()] = '\0';
		
		for(int i=0; i<vel; i++){
			if(mat[i] == nullptr){
				mat[i] = novi;
				return vel;
			}
		}
		char** tmp;
		try{
			tmp = new char*[vel + 1];
			
			for(int i=0;i<vel; i++){
				try{
					tmp[i] = new char[DajVelicinu(mat[i]) + 1];
				}catch(std::bad_alloc bd){
					for(int j=0; j<i; j++)
					   delete[] tmp[j];
					delete[] tmp;
					throw bd;
				}
				int k(0);
				while(mat[i][k] != '\0'){
					tmp[i][k] = mat[i][k];
					k++;
				}
				tmp[i][k] = '\0';
			}
		}catch(std::bad_alloc bd){
			throw bd;
		}
		tmp[vel] = novi;
		vel++;
		for(int i=0; i<vel; i++)
		   delete[] mat[i];
		   delete[] mat;
		   mat=tmp;
	}catch(std::bad_alloc bd){
			throw bd;
		}
		return vel;
}
				
				

void IzlistajOptuzbu(char** mat, int vel){
	for(int i=0; i<vel; i++){
		if(mat[i] != nullptr)
		     std::cout << mat[i] <<std::endl;
	}
}

	


int main(){
	int n;
//char** pok;

std::vector<std::string> lista_pot_krivaca;
std::cout<< "Koliko potencijalnih krivaca zelite unijeti? " <<std::endl;
std::cin>> n;
if(n<0) return 0;
std::cin.ignore(10000, '\n');

std::cout<< "Unesite potencijalne krivce: " <<std::endl;

for(int i{0}; i<n; i++){
	std::string krivac;
	std::getline(std::cin, krivac);
	lista_pot_krivaca.push_back(krivac);
}

try{
std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " <<std::endl;
int broj{0};
std::cin >>broj;

if(broj==1){
	std::cout<< "Unesite ime novog optuzenog: " <<std::endl;
	std::string novi;
	std::cin.ignore(10000, '\n');
	std::getline(std::cin, novi);
//DodajOptuzbu(,lista_pot_krivaca);
}
else if(broj == 2){
	std::cout <<"Unesite ime koje zelite izbaciti: " <<std::endl;
	std::string za_izb;
	std::cin.ignore(10000, '\n');
	std::getline(std::cin, za_izb);
//OdbaciOptuzbu( ,lista_pot_krivaca);	
}
else if(broj==3){
//	IzlistajOptuzbu(,lista_pot_krivaca);
}
else if(broj==0){
	return 0; 
}

}

catch(std::domain_error e){
std::cout << e.what() << std::endl;}
catch(...){
	std::cout << "Problem: Nema dovoljno memorije! " << std::endl;}
return 0;
}