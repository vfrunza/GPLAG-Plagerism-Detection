#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
int PotencijalniKrivci(char ** &p, std::vector<std::string>v){
	int brojac(0);
	int j(0);
	 	p=nullptr;
		 p=new char*[v.size()];
		if(p==nullptr) throw std::bad_alloc();
		for(int i=0; i<v.size(); i++){
			p[i]=nullptr;
		}
		for(int i=0; i<v.size(); i++){
			p[i]=new char[v[i].length()+1];
			if(p[i]==nullptr) {
				for(int j=0; j<brojac; j++){
					delete[] p[j];
				}
				delete[] p;
				throw std::bad_alloc();
		}
		brojac++;
		}
		for(int i=0; i<v.size(); i++){
			for(j=0; j<v[i].length(); j++){
				p[i][j]=v[i][j];
			}
			p[i][j]='\0';
		}
	return brojac;
}
int OdbaciOptuzbu(char ** &p, int n, std::string s){
	int j,k(0),brojac(0);
	for(int i=0; i<n; i++){
		j=0;
			while(p[i][j]!='\0' && j<s.length()){
				if(p[i][j]!=s[j]){
					break;
				}
				j++;
			}
			if(p[i][j]=='\0' && j==s.length()) {
				k=1;
				p[i][0]='\0';
				p[i]=nullptr;
				for(int i=0; i<n; i++){
					if(p[i]==nullptr) brojac++;
				}
				if(brojac<=10){
					return n;
				}else if(brojac>10){
					char **l;
					l=nullptr;
					l=new char*[n-brojac];
					if(l!=nullptr){
					for(int i=0; i<n; i++){
						if(p[i]!=nullptr){
					l[i]=p[i];	
					}
					}
				for(int i=0; i<n; i++){
					delete[] p[i];
				}
			delete[] p; 
				p=l;
				return n-brojac;
				}
			}
		
	}
		
	
	}
	if(k==0){
		std::string izuzetak="Osoba sa imenom " + s + " nije bila optuzena";
throw std::domain_error(izuzetak);
}
	
return n;	
}
int DodajOptuzbu(char ** &p, int n, std::string s){
	char *k;
	k=nullptr;
	k=new char[s.length()+1];
	if(k==nullptr) throw std::bad_alloc();
	for(int i=0; i<s.length(); i++){
		k[i]=s[i];
	}
	k[s.length()]='\0';
	for(int i=0; i<n; i++){
		if(p[i]==nullptr){
			p[i]=k;
			return n;
		}
	}
	char**pomocni;
	pomocni=nullptr;
	pomocni=new char*[n+1];
	if(pomocni==nullptr) {
		delete[] k;
		throw std::bad_alloc();
	}
	for(int i=0; i<n; i++){
	pomocni[i]=p[i];	
	}
	pomocni[n]=k;
	delete[] p;
	p=pomocni;
return n+1;	
}
void IzlistajOptuzbu(char**p, int n){
for(int i=0; i<n; i++){
	// if(p[i]==nullptr) continue;
 std::cout<<p[i]<<std::endl;
}
}
int main ()
{
		char **d;
		int x,n;
	std::string s;
	std::vector<std::string>v;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti?"<<std::endl;
	std::cin>>n;
	v.resize(n);
	std::cin.ignore(10000,'\n');
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
	for(int i=0; i<n; i++){
	std::getline(std::cin,s);
		v[i]=s;
	}
	try{
	n=PotencijalniKrivci(d,v);
		
		}catch(...){
		for(int j=0; j<n; j++){
					delete[] d[j];
				}
				delete[] d;	
		}
	
	do{
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;	
	std::cin>>x;
	std::cin.ignore(10000,'\n');
if(x==1){
		std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
		std::getline(std::cin,s);
		try{
			n=DodajOptuzbu(d,n,s);
		}catch(...){
			for(int j=0; j<n; j++){
				delete[] d[j];
			}
			delete[] d;
		}
}
else if(x==2){
	std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
	std::getline(std::cin,s);
	try{
		n=OdbaciOptuzbu(d,n,s);
	}catch(...){
		for(int j=0; j<n; j++){
		delete[] d[j];
		}
	delete[] d;
	}
}
else if(x==3){
	IzlistajOptuzbu(d,n);
}
else if(x==0){
	for(int j=0; j<n; j++){
		delete[] d[j];
	}
	delete[] d;
	return 0;
}
		
}while(x!=0);

	for(int j=0; j<n; j++){
		delete[] d[j];
	}
	delete[] d;
	return 0;
}