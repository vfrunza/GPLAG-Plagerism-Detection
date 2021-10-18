/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

int brojosl=0;
void Dealociraj(char **mat, int n){
 for(int i = 0; i < n; i++) delete[] mat[i];
 delete[] mat;
}
int PotencijalniKrivci(char **&p,std::vector<std::string> v){
	//std::cout<<v.size()<<v[0].size();
	//try{
	p=nullptr;
	p=new char*[v.size()];
	for(int i=0;i<v.size();i++)
	p[i]=nullptr;
	//brojac_new=0;
	for(int i=0;i<v.size();i++){
		p[i]=new char[v[i].size()+1];
		//std::cout<<brojac_new;
		//char pom[1000];
		char daj[1000];
		int a=0;
		for(int j=0;j<v[i].size();j++){
			daj[j]=v[i][j];
			a++;
		}
		daj[a]='\0';
		//std::cout<<sizeof(daj);
		//std::strcpy(pom,daj);
		//std::cout<<pom;
		for(int j=0;j<=v[i].size();j++){
			p[i][j]=daj[j];
			//std::cout<<sizeof(p[i]);
		}
		//p[i]=pom;
	}
	/*}
	catch(std::bad_alloc){
		Dealociraj(p,v.size());
	}*/
	return v.size();
}
int OdbaciOptuzbu(char **&p,int &velicina,std::string s){
	//std::cout<<velicina;
	bool t=false;
	char daj[1000];
		int a=0;
		for(int j=0;j<s.length();j++){
			daj[j]=s[j];
			a++;
		}
		daj[a]='\0';
		//std::cout<<daj;
	for(int i=0;i<velicina;i++){
		int j=0;
		if(p[i]!=nullptr){
			//std::cout<<p[i][j]<<daj[j]<<std::endl;
		while(p[i][j]==daj[j] && daj[j]!='\0')j++;
		//std::cout<<j<<s.length();
		if(j==s.length() ){
			t=true;
			//std::cout<<"brisanje"<<i<<std::endl;
			delete []p[i];
			p[i]=nullptr;
			brojosl++;
			if(brojosl>10){
				try {
				char **nP=new char*[velicina - 11];
				int z=0;
				for(int k=0;k<velicina;k++){
					if(p[k]!=nullptr){nP[z]=p[k];z++;}
				}
				delete []p;
				p=nP;
				brojosl=0;
				velicina-=11;
			}
			catch (std::bad_alloc s) {
					return velicina;
				}
			}
		}
	}
}
if(t==false){
	std::string izuzetak;
	izuzetak="Osoba sa imenom ";
	izuzetak+=s;
	izuzetak+=" nije bila optuzena";
	throw std::domain_error(izuzetak);
}
	return velicina;
}
int DodajOptuzbu(char **&p,int &velicina,std::string s){
	char*sl=nullptr;
	sl=new char [s.size()+1];
	char daj[1000];
		int a=0;
		for(int j=0;j<s.length();j++){
			daj[j]=s[j];
			a++;
		}
		daj[a]='\0';
		for(int j=0;j<=s.size();j++){
			sl[j]=daj[j];
				}
		int z=0;
		for(int i=0;i<velicina;i++){
			z++;
			if(p[i]==nullptr){
				p[i]=sl;
			break;
			}
		}
		if(z==velicina){
			try{
				char **nP=new char*[velicina +1];
				for(int k=0;k<=velicina;k++){
					if(k!=velicina)
					nP[k]=p[k];
					else{
						nP[k]=sl;
		}
				}
				delete []p;
				p=nP;
				velicina+=1;
			}
			catch (std::bad_alloc s) {
				throw std::bad_alloc();
					return velicina;
				}
		}
		return velicina;
}
void IzlistajOptuzbu(char **p,int velicina){
	//std::cout<<"ss"<<velicina;
	for(int i=0;i<velicina;i++){
		if(p[i]==nullptr)i++;
		//std::cout<<" "<<sizeof(p[i]);
		int j=0;
		while(p[i][j]!='\0') {std::cout<<p[i][j];j++;}
		//for(int j=0;j<sizeof(p[i]);j++){if(p[i][j]=='\0')break;std::cout<<p[i][j];}
		std::cout<<std::endl;
		//if(i==velicina-1)break;
	}
	//std::cout<<"a";
}
int main ()
{
	char **nizPotencijalnih;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	int n;
	std::cin>>n;
	std::cin.clear();
	std::cin.ignore(10000,'\n');
	std::vector<std::string> imena (n);
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
	for(int i=0;i<n;i++){
		std::getline(std::cin,imena[i]);
	}
	int velicina=PotencijalniKrivci( nizPotencijalnih, imena);;
	int unos;
	while(true){
		std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
		std::cin>>unos;
		if(unos==0){Dealociraj(nizPotencijalnih,velicina);break;}
		else if(unos==1){
			std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
			std::string novi;
			std::cin.clear();
	std::cin.ignore(10000,'\n');
			std::getline(std::cin,novi);
			velicina=DodajOptuzbu(nizPotencijalnih,velicina,novi);
		}
		else if(unos==2){
			std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
			std::string novi;
			std::cin.clear();
	std::cin.ignore(10000,'\n');
			std::getline(std::cin,novi);
			try{
			velicina=OdbaciOptuzbu(nizPotencijalnih,velicina,novi);
			}
			catch(std::domain_error e){
				std::cout<<"Izuzetak: "<<e.what()<<std::endl;
			}
		}
		else if(unos==3){
			IzlistajOptuzbu(nizPotencijalnih,velicina);
		}
	}
	return 0;
}