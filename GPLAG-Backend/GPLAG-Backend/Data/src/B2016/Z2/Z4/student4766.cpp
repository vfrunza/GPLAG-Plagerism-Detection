#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <stdexcept>
int DodajOptuzbu(char ** &p, int n, std::string s){
	bool ima(false); int i;
	try{
		char *pok = new char[s.length() + 1];
		std::strcpy(pok, s.c_str());
		for(i = 0; i < n; i++)
			if(p[i] == nullptr){
				ima = true;
				break;
			}
		if(ima){
			p[i] = pok;
		}else{
			try{
				char **novi = new char*[n+1];
				for(int k = 0; k < n; k++)
					novi[k] = p[k];
				novi[n++] = pok;
				//for(int k = 0; k < n-1; k++)
				//	delete[] p[k];
				delete[] p;
				p = novi;
			}catch(...){
				delete[] pok;
				throw std::bad_alloc();
			}
		}
	}catch(...){
		throw std::bad_alloc();
	}
	return n;
}
int OdbaciOptuzbu(char** &p, int n, std::string s){
	bool ima(false); int i;
	for(i = 0; i < n; i++) {
		if(p[i] == nullptr) continue;
		if(std::strcmp(p[i], s.c_str()) == 0){
		 ima=true;
		 break;
		}
	}
	if(!ima) throw std::domain_error("Osoba sa imenom " + s +" nije bila optuzena");
	delete[] p[i]; p[i] = nullptr;
	int num(0);
	for(int i = 0; i < n; i++) if(p[i] == nullptr) num++;
	if(num > 10){
		try{
			char **novi = new char*[n-num];
			int current(0);
			for(int i = 0; i < n; i++)
				if(p[i] != nullptr) novi[current++] = p[i];
			delete[] p;
			p = novi;
			n-=num;
		}catch(...){
			;
		}
	}
	return n;
}
int PotencijalniKrivci(char** &p, std::vector<std::string> v){
	int i(0);
	try{
		p = nullptr;
		p = new char*[v.size()];
		for(i = 0; i < v.size(); i++){
			p[i] = nullptr;
			p[i] = new char[v[i].size() + 1];
			for(int j = 0; j < v[i].size(); j++){
				p[i][j] = v[i][j];
				if(j == 0) p[i][v[i].size()] = '\0';
			}
		}
	}catch(...){
		for(int k = 0; k < i; k++) delete[] p[k];
		delete[] p;
		throw std::bad_alloc();
	}
	return i;
}
void IzlistajOptuzbu(char **p, int n){
	for(int i = 0; i < n; i++) 
		if(p[i] != nullptr) std::cout << p[i] << std::endl;
}
int main ()
{
	std::cout << "Koliko potencijalnih krivaca zelite unijeti?\n";
	int n,opt; std::cin >> n;
	std::string tmp; std::cin.ignore(1000, '\n');
	std::cout << "Unesite potencijalne krivce: \n";
	std::vector<std::string> v(n);
	for(int i = 0; i < n; i++) std::getline(std::cin, v[i]);
	char **p;
	n = PotencijalniKrivci(p, v);
	bool vrti(true);
	for(;vrti;){
		std::cout << "Odaberite opciju: 1 za unos novog optuzenog," <<
		" 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj:\n";
		std::cin >> opt; std::cin.ignore(1000, '\n');
		switch(opt){
			case 1: std::cout << "Unesite ime novog optuzenog: \n"; std::getline(std::cin, tmp);
			n = DodajOptuzbu(p,n,tmp); break;
			case 2: try{
				std::cout << "Unesite ime koje zelite izbaciti: \n"; std::getline(std::cin, tmp);
			n = OdbaciOptuzbu(p,n,tmp); 
			}catch(std::domain_error exc){
				std::cout << exc.what();
				}break;
			case 3: IzlistajOptuzbu(p,n); break;
			case 0: vrti = false; break;
		}
	}
	for(int i = 0; i < n; i++) delete[] p[i];
	delete[] p;
	return 0;
}