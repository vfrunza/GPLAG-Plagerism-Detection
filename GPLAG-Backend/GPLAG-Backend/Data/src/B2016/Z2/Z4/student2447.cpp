#include <set>
#include <iostream>
#include <vector>
#include <stdexcept>

int PotencijalniKrivci(char **&pok,std::vector<std::string> vs){
	
	char **novi;
	novi=pok;
	int brojac(0);
	try{
		pok=(new char *[vs.size()]);
		if(pok==nullptr) throw std::bad_alloc();
		for(int i=0;i<vs.size();i++){
			pok[i]=new char [vs[0].size()];
				}
		}
		catch(...){
			for(int i=0;i<vs.size();i++){
				delete [] pok[i];
			}
			delete [] pok;
			throw;
		}
		
		
		
		
}



/*OdbaciOptuzbu(char **&a1,char **&a2,PotencijalniKrivci,std::string s)*/


int main ()
{
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;;
	int n;
	std::cin>>n;
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
	std::vector<std::string> v;
	for(int i=0;i<=n;i++){
		std::string rijec;
		std::getline(std::cin,rijec);
		v.push_back(rijec);
	}
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
	

	return 0;
}