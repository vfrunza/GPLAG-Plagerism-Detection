/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <new>

int PotencijalniKrivci (char **&pok, const std::vector<std::string> &v){
	int brojac(0);
	char **p(nullptr);
	try{
		p = new char*[v.size()];
		for(int i=0; i<v.size(); i++)
		  p[i] = nullptr;
		try{
			for(int i=0; i<v.size(); i++){
				p[i] = new char[v[i].length() +1];
				brojac++;
			}
			for(int i=0; i<v.size(); i++){
				for(int j=0; j<v[i].size(); j++)
				  p[i][j] = v[i][j];
			}
		}
		catch(...){
			for(int i=0; i<v.size(); i++)
			  delete[] p[i];
		    delete[] p;
		    throw std::bad_alloc();
		}
	}
	catch(...){
		throw std::bad_alloc();
	}
	pok = p;
	return brojac;
}

int OdbaciOptuzbu (char **&pok, int br_pokazivaca, const std::string &s){
	int br(0);
	bool isti_su(false);
	int prvi(0);
	char *p(nullptr);
	for(int i=0; i<br_pokazivaca; i++){
	//	char *p(pok[i]);
	    p = pok[i];
	//	char *poc(p);
		prvi = i;
		int j(0);
		while(*p!='\0'){
			if(p[j]==s[j]){
				while (j<s.length() && *p!='\0' && p[j]==s[j]) {
					p++;
					j++;
				}
			if(j==s.length() && *p=='\0'){
				isti_su = true;
				break;
			}
			}
		}
	}
	if(!isti_su){
		std::string a("Osoba sa imenom ");
		a+=s;
		a+=" nije bila optuzena";
		throw std::domain_error(a);
	}
	if(isti_su){
		pok[prvi] = nullptr;
		int c(0);
		for(int i=0; i<br_pokazivaca; i++){
			if(!p[i])
			  c++;
		}
	  if(c<10)
	    return br_pokazivaca;
	  //int br(br_pokazivaca-c);
	  br = br_pokazivaca-c;
	  char **p1(nullptr);
	  try{
	  	p1 = new char*[br];
	  	for(int i=0; i<br; i++)
	  	  p1[i] = nullptr;
	  	try{
	  		int j(0);
	  		for(int i=0; i<br_pokazivaca; i++){
	  			if(pok[i]){
	  				int k(0);
	  				while(*pok[i]!='\0'){
	  				  k++;
	  			      pok[i]++;
	  				}
	  				p1[j] = new char[k];
	  				j++;
	  			}
	  			
	  		}
	  		j = 0;
	  		for(int i=0; i<br_pokazivaca; i++){
	  			if(pok[i]){
	  				while(*pok[i]!='\0'){
	  					*p1[j] = *pok[i];
	  					pok[i]++; 
	  				}
	  				j++;
	  			}
	  		}
	  		for(int i=0; i<br_pokazivaca; i++)
	  		  delete[] pok[i];
	  		delete[] pok;
	  		pok = p1;
	  	}
	  	catch(...){
	  		for(int i=0; i<br; i++)
	  		  delete[] p1[i];
	  		delete[] p1;
	  		throw std::bad_alloc();
	  	}
	  }
	  catch(...){
	  	throw std::bad_alloc();
	  }
	}
	return br;
}

int DodajOptuzbu (char **pok, int velicina, const std::string &s){
	int brojac(velicina);
	char *p(nullptr);
	char **niz(nullptr);
	try{
		p = new char[s.length() + 1];
		int l(0);
		for(l=0; l<s.length(); l++)
		  p[l] = s[l];
		p[l] = '\0';
		for(int i=0; i<velicina; i++){
			if(!pok[i]){
				pok[i] = p;
			    return brojac;
			}
		}
		try{
			niz = new char*[velicina + 1];
			brojac = velicina + 1;
			int i(0);
			for(i=0; i<velicina; i++)
			  niz[i] = pok[i];
			niz[i] = p;
			for(int i=0; i<velicina; i++)
			   delete[] pok[i];
			delete[] pok;
			pok = niz;
		}
		catch(...){
			throw std::bad_alloc();
		}
	}
	catch(...){
		throw std::bad_alloc();
	}
	return brojac;
}


void IzlistajOptuzbu (char **pok, int br_pokazivaca){
	for(int i=0; i<br_pokazivaca; i++){
		if(pok[i]){
			int j(0);
			while(pok[i][j]!='\0'){
				std::cout<<pok[i][j];
				j++;
			}
			std::cout<<std::endl;
		}
	}
}



int main ()
{
    char **niz_pokazivaca(nullptr);
    int n;
    std::cout<<"Koliko potencijalnih krivaca zelite unijeti?";
    std::cin>>n;
    std::cout<<"Unesite potencijalne krivce: ";
    std::vector<std::string> v(n);
    std::string s;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    for(int i=0; i<n; i++){
    	std::getline(std::cin, s);
    	v[i] = s;
    	
    }
    PotencijalniKrivci(niz_pokazivaca, v);
    int a;
    for(;;){
      std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
      std::cin>>a;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      if(a==0)
        break;
      if(a==1){
      	std::string s1;
      	std::cout<<"Unesite ime novog optuzenog: ";
      	std::getline(std::cin, s1);
      	n = DodajOptuzbu(niz_pokazivaca, n, s1);
      }
      if(a==2){
      	std::string s2;
      	
      	
      	std::cout<<"Unesite ime koje zelite izbaciti: ";
      	std::getline(std::cin, s2);
        n = 	OdbaciOptuzbu(niz_pokazivaca, n, s2);
      }
    	
    if(a==3){
    	IzlistajOptuzbu(niz_pokazivaca, n);
    }
    }
    
	return 0;
}




