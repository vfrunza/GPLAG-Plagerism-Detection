/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <new>
#include <cstring>

template <typename TipElemenata>
void UnistiMatricu(TipElemenata **mat, std::vector<std::string> v )
{
	if(!mat) return;
	for(int i=0; i<v.size();i++) delete[] mat[i];
	delete[] mat;
}
template<typename TipElemenata>
TipElemenata **StvoriMatricu(std::vector<std::string> v)
{
	TipElemenata **mat(new TipElemenata*[v.size()]);
	for(int i=0; i<v.size(); i++) mat[i]=nullptr;
	try{
		for(int i=0; i<v.size();i++)
		mat[i]=new TipElemenata[v[i].size()+1];
	}
	catch(std::bad_alloc){
		UnistiMatricu(mat, v);
		throw ;
	}
	return mat;
	
}
int PotencijalniKrivci(char**&pok, std::vector<std::string> v)
{
	pok=nullptr;
	try{
		pok=StvoriMatricu<char>(v);
		for(int i=0; i<v.size();i++)
		{
			for(int j=0; j<v[i].size(); j++)
			     {
			     	pok[i][j]=v[i][j];
			     }
			pok[i][v[i].size()]='\0';
		}
		
	}
	catch(std::bad_alloc) {
		std::cout<< "Neuspjela alokacija"<<std::endl;
	}
	return v.size();
}
int OdbaciOptuzbu (char**&pok, int vel, std::string s)
{   
	char ime[100];
	int prov=0;
	int brojac=0;
	for(int i=0; i<s.length(); i++)
	  	ime[i]=s[i];
	  
	  ime[s.length()]='\0';
	  for(int i=0; i<vel; i++)
	  {
	  	if(std::strcmp(pok[i],ime)==0) prov=1;
	  }
	  
	  if(prov==0) throw std::domain_error("Osoba sa imenom " + s + " nije bila optuzena");
	  prov=0;
	  for(int i=0; i<vel; i++)
	  {
	  	
	 
	  	if(std::strcmp(pok[i],ime)==0)
	  	{
	  		
	  		delete[] pok[i];
	  		pok[i]=nullptr;
	  		
	  	}
	  	prov=0;
	  }
	  int brojac2=0;
	  for(int i=0; i<vel; i++) { if(pok[i]==nullptr) brojac++;
	  
	  else brojac2++;}
	  
	  if(brojac>10) {
	  	try{
	  		char **a=new char*[brojac2];
	  		for(int i=0; i<10; i++) a[i]=nullptr;
	  		int j=0;
	  		for(int i=0; i<vel; i++)
	  		{
	  			if(pok[i]!=nullptr) 
	  			{a[j]=pok[i];
	  			j++;
	  			}
	  			}
	  		for(int i=0; i<vel; i++) delete[] pok[i];
	  		delete[]pok;
	  		pok=a;
	  		return vel;
	  	}
	  	catch(...){
	  		std::cout<<"Neuspjela alokacija";
	  	
	  	}
	  }
	  return vel;
	  
	  
}
int DodajOptuzbu (char**&pok, int vel, std::string s)
{
	int prov=0;
	char* pok2=new char[s.length()+1];

		for(int i=0; i<s.length();i++)
				pok2[i]=s[i];
				
	pok2[s.length()]='\0';	
	
	for(int i=0; i<vel; i++)
		{
			if(pok[i]==nullptr) 
			{
			pok[i]=pok2;
			prov=1;
			
			}
		
			
		}
	if(prov==1) {
		delete[] pok2;
		return vel;	
	}
	else if(prov==0)
	{
	
		try{
		char **a(new char*[vel+1]);
		for(int i=0; i<vel+1; i++) a[i]=nullptr;
		try{
		
			for(int i=0; i<vel+1; i++)
				{
					if(i==vel) a[i]=pok2;
					else a[i]=pok[i]; //a ovdje pristupas ovom sto si obrisala gore
				
				}
				delete[] pok;
				pok=a;
				
				
	  
		return vel+1;
		}
			catch(...){
				for(int i=0; i<vel+1; i++) delete[] a[i];
				delete[] a;
				delete[] pok2;
				throw;
			}
		
		}
		catch(...){ 
			std::cout<<"Problem sa memorijom!"; 
		}
	}
	
	return vel;
}
void IzlistajOptuzbu(char**pok, int vel)
{
	for(int i=0; i<vel; i++) 
	{
		if(pok[i]!=nullptr) std::cout<<pok[i]<<std::endl;
	}
	}

int main ()
{
	
	char**pok=nullptr;
	int n;
	std::string s;
		std::vector<std::string> v;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	std::cin>>n;
	std::cin.clear();
    std::cin.ignore(10000,'\n');
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;;
	for(int i=0; i<n; i++)
	{
		std::getline(std::cin, s);
		v.push_back(s);
	}
	int vel=PotencijalniKrivci(pok, v);
	try{
	int opcija;
	for(;;)
	{
		std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
		std::cin>>opcija;
		std::cin.clear();
		std::cin.ignore(100,'\n');
		if(opcija==0) break;
		else if(opcija==1)  {
			std::string str;
		 std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
		 std::getline(std::cin,str);
		 vel=DodajOptuzbu(pok, vel, str);
		 
		
		}
	else if(opcija==2)  {
		 std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
		 std::string str;
		 std::getline(std::cin,str);
		 vel=OdbaciOptuzbu(pok, vel, str);
		}
		
	else if(opcija==3) IzlistajOptuzbu(pok,vel);
	}
	for(int i=0; i<vel; i++) delete[] pok[i];
	delete[] pok;
	}
	catch(std::domain_error e)
	{
		std::cout<<e.what();
	}
return 0;
}