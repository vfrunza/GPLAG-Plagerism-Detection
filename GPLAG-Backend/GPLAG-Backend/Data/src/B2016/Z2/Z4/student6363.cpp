/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include<vector>
#include<string>
#include<new>
#include<algorithm>
#include<stdexcept>

void IzlistajOptuzbu(char**p, int broj_prodavaca){
	for(int i(0); i<broj_prodavaca; i++){
		if(!(p[i]==nullptr)){
			std::cout<<p[i]<<std::endl;
		}
	}
}

int PotencijalniKrivci(char **&p, std::vector<std::string> v){
	int broj(0);
	p = nullptr;
	try{
		p = new char* [v.size()];
		for(int i(0); i<int(v.size()); i++)	p[i] = nullptr;
			
		try{
			for(int i(0); i<int(v.size()); i++){
			p[i] = new char [int(v[i].size()) +1];
			std::copy(v[i].begin(), v[i].end(), p[i]);
			p[i][v[i].size()] = '\0';
			broj++;
			}
			
		}
		catch(...){
			unsigned int i(0);
			while(i<v.size()){
			delete[] p[i];
			i++;
		}
		throw;
	}
	
	}
	catch(...){
		delete[] p;
		throw;
	}
	return broj;
	
}

int OdbaciOptuzbu (char **&p, int broj_prodavaca, std::string s){
	bool flag(true);
   	
   	for(int i(0); i<broj_prodavaca;i++){
   		 flag = true;
   		if(p[i][0] == s[0]){
   			for(int j(0); j<int(s.length()) && p[i][j] != '\0'; j++){
   				if(p[i][j]!=s[j]){flag = false; break;}
   			}
   			if(flag){
   				delete[] p[i];
   				p[i]= nullptr;
   				break;
   			}
   		}
		if(i==broj_prodavaca - 1) throw std::domain_error("Osoba sa imenom " + s + " nije bila optuzena");
   	}
   	int broj(0);
   	for(int i(0); i<broj_prodavaca; i++){
   		if(p[i] == nullptr)broj++;
   	}
   	char **m = nullptr;
   	
   	if(broj==10){
   		try{
   			
   		m = new char*[broj_prodavaca - 10];
   		
   				
   		for(int i(0), j(0); i<broj_prodavaca; i++){
   			if(p[i]!=nullptr){
   				m[j] = p[i];
   				j++;
   			}
   			}
   		for(int i(0); i<broj_prodavaca; i++){
   			p[i] = nullptr;
  
   		}
   		delete[] p;
   		
   		p=m;
   		return broj_prodavaca-10;
   		
   		
   	}
   	catch(...){
   		delete[] m;
   		
   	}
   	}
   	return broj_prodavaca;
 }
 
 int DodajOptuzbu(char**&p, int broj_prodavaca, std::string s){
 	char *m = nullptr;
 	try{
 	char **n = nullptr;
 	m = new char[s.length()+1];
 	for(int i(0); i<int(s.length()); i++){
 		m[i] = s[i];
 	}
 	m[s.length()] = '\0';
 	bool flag(true);
 	for(int i(0); i<broj_prodavaca; i++){
 		if(p[i] == nullptr){
 			p[i] = m;
 			m=nullptr;
 			flag = false;
 			break;
 		}
 	}
 		if(flag){
 			try{
 				n = new char*[broj_prodavaca+1];
 				for(int k(0); k<broj_prodavaca; k++){
 					n[k]=p[k];
 					p[k]=nullptr;
 				}
 				n[broj_prodavaca] = m;
 				delete[] p;
 				p=n;
 				return broj_prodavaca+1;
 			}
 			catch(...){
 				delete[] n;
 				throw;
 			}
 		}
 		return broj_prodavaca;
 	
 	}
 	catch(...){
 		delete [] m;
 		throw;
 	}
 	return broj_prodavaca;
 }

void DeLociraj(char **p, int broj){
	for(int i(0); i<broj; i++)delete[] p[i];
	
	delete[] p;
	
}

int main ()
{
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
	int n, broj_prodavaca(0);
	std::cin>>n;
	std::cin.ignore(1000, '\n');
	std::cout  <<"Unesite potencijalne krivce: "<< std::endl;
	char** p = nullptr;
	try{
		for(int i(0);i<n;i++){
			std::string s;
			std::getline(std::cin, s);
			broj_prodavaca = DodajOptuzbu(p,i,s);
		}
		while(1){
			std::string s;
			std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
			std::cin>>n;
			std::cin.ignore(1000, '\n');
			if(n==0){
				DeLociraj(p, broj_prodavaca);
				break;	
			} 
			
			if(n==1){
				std::cout << "Unesite ime novog optuzenog: " << std::endl;
				std::getline(std::cin, s);
				broj_prodavaca = DodajOptuzbu(p,broj_prodavaca,s);
				continue;
			} 
			if(n==2){
				std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
				std::getline(std::cin,s);
				broj_prodavaca = OdbaciOptuzbu(p,broj_prodavaca,s);
				continue;
			}
			if(n==3){
				IzlistajOptuzbu(p,broj_prodavaca);
			}
		}
	}
	catch(std::domain_error e){
		std::cout<<"Izuzetak: "<<e.what();
	}
	catch(...){}
	return 0;
}