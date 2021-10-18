/*B 16/17, Zadaća 2, Zadatak 4

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <new>
#include <string>
#include <cstring>

int	PotencijalniKrivci(char **&p,std::vector<std::string> s){
	p = nullptr;
	int br(0);
	p = new char* [s.size()];
		for(int i = 0; i < s.size(); i++)p[i] = nullptr;
		try{
			for(int i = 0; i < s.size(); i++){
				p[i] = new char[s[i].size() + 1];
				std::strcpy(p[i],s[i].c_str());
				br++;
			}
		}
		catch(...){
			for(int i = 0; i < s.size(); i++) delete []p[i];
			delete []p;
			throw;
		}
	return br;
}

........
int	OdbaciOptuzbu(char **&p,int vel, std::string s){
	bool cs(false);
	for(int i = 0; i < vel; i++){
		if(p[i] != nullptr && std::strcmp(p[i],s.c_str()) == 0)cs = true;
		if(cs)break;
	}
	if(!cs){
		std::string pom{"Osoba sa imenom "};
		pom += s;
		pom += " nije bila optuzena";
		throw std::domain_error (pom.c_str());
	}

	for(int i = 0; i < vel; i++){
		if(std::strcmp(p[i],s.c_str()) == 0 && p[i] != nullptr){delete []p[i]; p[i] = nullptr; break;}
	}
	int br(0);
	for(int i = 0; i < vel; i++)if(p[i] == nullptr)br++;
	if(br <= 10)return vel;
		char **pom(nullptr);
		int n_vel = vel - br;
			try{
				pom = new char* [n_vel];
				for(int i = 0; i < n_vel; i++)pom[i] = nullptr;
				try{
					int k(0);
					for(int i = 0; i < vel; i++)
						if(p[i] != nullptr) {
							pom[k] = new char[std::strlen(p[i]) + 1];
						        std::strcpy(pom[k],p[i]);
                                k++;
						}

					for(int i = 0; i < vel; i++)delete [] p[i]; delete []p;
					p = nullptr;
					p = pom;
					return n_vel;
				}
				catch(...){
				    for(int i = 0; i < n_vel; i++) delete []pom[i];
					delete []pom;
					throw;
				}
			}
			catch(...) {}
	return vel;
}

int DodajOptuzbu(char **&p,int vel, std::string s){
	char *novi_niz(nullptr);
    novi_niz = new char[s.size() + 1];
    for(int i = 0; i < s.size(); i++)novi_niz[i] = s[i]; novi_niz[s.size()] = '\0';
	for(int i = 0; i < vel; i++)if(p[i] == nullptr){p[i] = novi_niz; novi_niz = nullptr; return vel;}
    char **pom(nullptr);
		int n_vel = vel + 1;
            try{
				pom = new char* [n_vel];
				for(int i = 0; i < vel; i++)pom[i] = p[i];
                    pom[vel] = nullptr;
                    pom[vel] = novi_niz;
                    novi_niz = nullptr;
                    delete []p;
					p = nullptr;
					p = pom;
					return n_vel;
            }
            catch(...){delete []novi_niz;throw;}
return vel;
}

void IzlistajOptuzbu(char **p,int vel){
	for(int i = 0; i < vel; i++)
	if(p[i] != nullptr)std::cout<<p[i] << std::endl;
}
int main (){
	int vel;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? " <<std::endl;
	std::cin>>vel;
	std::vector<std::string> v(vel);
	std::cin.ignore (10000, '\n');
	std::cout<<"Unesite potencijelne krivce: ";
	for(int i = 0; i < v.size(); i++)
	{
		std::getline(std::cin, v[i]);
	}
	std::cout<<std::endl;

 	//for(int i = 0; i < v.size();i++)
		//	std::cout<< v[i] << std::endl;
	char **p;
//	for(int i=0; i<vel; i++){
	//	p[i]=nullptr;
	
	
	try{
		
		int br;
		do{
		std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
		std::cin>>br;
		if(br==1)
		{
			std::cout<<"Unesite ime novog optuzenog: ";
			std::string s;
			std::cin.ignore(1000, '\n');
			std::getline(std::cin,s);
			vel= DodajOptuzbu(p, s.length(), s);
		}
		else if(br==2)
		{
			std::cout<<"Unesite ime koje zelite izbaciti: ";
			std::string s;
			std::cin.ignore(1000, '\n');
			std::getline(std::cin,s);
			vel= OdbaciOptuzbu(p, s.length(), s);
		}
		else if(br==3)	
		{
			IzlistajOptuzbu(p,vel);
		}

		
		}
		while(br!=0);
	for(int i=0; i<vel; i++) delete [] p[i];
	delete [] p;
	}
		
		//vel = PotencijalniKrivci(p,v);
		//std::cout<<std::endl<<"PotencijalniKrivci:"<<std::endl;
		//std::cout<< "Broj alociranih znakova: " << vel <<std::endl;
		//for(int i = 0; i < vel; i++)std::cout<< p[i] <<std::endl;
		//std::cout<<std::endl<<"OdbaciOptuzbu:"<<std::endl;
		//for(int i = 15; i < 30; i++){delete []p[i]; p[i] = nullptr;}
      
	catch(std::domain_error d){
		std::cout<< d.what()<<std::endl;
	}
	catch(...){
		std::cout<<"Nema memorije!";
	}

	return 0;
}
