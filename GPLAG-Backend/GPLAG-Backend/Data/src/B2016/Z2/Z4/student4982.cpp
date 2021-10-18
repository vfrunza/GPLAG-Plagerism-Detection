#include <iostream>
#include <vector>
#include <string>
#include <new>
#include <stdexcept>
#include <type_traits>
#include <cstring>

int PotencijalniKrivci(char**& c, std::vector<std::string> imena)
{
   char **niz=nullptr;; 
   int broj=0;
   try
   {
       niz=new char*[imena.size()];
       try
       {
          for(int i=0;i<imena.size();i++)
          {
             niz[i]=new char[imena[i].size()+1];
             std::strcpy(niz[i],imena[i].c_str());
             broj++;
          }
          c=niz;
          return broj;
       }
       
       catch(...)
       {
           for(int i=0;i<broj;i++) delete[] niz[i];
           delete[] niz; throw;
       }
   }
   catch(std::bad_alloc)
   {
       throw;
   }
}

int OdbaciOptuzbu(char**& c, int vel, std::string s)
{
    
    int nulptr=0;
    bool ime=false;
    for(int i=0;i<vel;i++)
    {
        if(c[i]!=nullptr)
        {
            if(std::strcmp(c[i],s.c_str())==0) {
            ime=true;
            delete[] c[i]; c[i]=nullptr; nulptr++;
            }
        }
    }
    if(ime==false) throw std::domain_error("Osoba sa imenom "+s+" nije bila optuzena");
    if(nulptr>10)
    {
        if(nulptr-vel==0) return 0;
        char **c2=nullptr;
        try
        {
            int broj=0;
            c2=new char*[nulptr-vel];
            try
            {
                
                for(int i=0;i<vel;i++)
                {
                    if(c[i]!=nullptr)
                    {
                        std::strcpy(c2[broj],c[i]);
                        broj++;
                    }
                }
                return broj;
            }
            catch(...)
            {
                for(int i=0;i<broj;i++)
                {
                    delete[] c2[i];
                }
                delete[] c2; throw;
            }
        }
        catch(std::bad_alloc)
        {
            throw;
        }
    }
    return vel;
}

int DodajOptuzbu(char**& c, int vel, std::string s)
{
    bool puno=true;
    for(int i=0;i<vel;i++)
    {
        if(c[i]==nullptr)
        {
            c[i]=new char[s.size()+1];
            std::strcpy(c[i],s.c_str());
            puno=false;
            break;
        }
    }
    if(puno==true)
    {
        char **c2=nullptr;
        try
        {
            c2=new char*[vel+1]; int broj=0;
            try
            {
                for(int i=0;i<vel;i++)
                {
                    c2[i]=new char[std::strlen(c[i])+1];
                    std::strcpy(c2[i],c[i]);
                    broj++;
                }
                c2[vel]=new char[s.size()+1];
                std::strcpy(c2[vel],s.c_str());
                broj++;
                for(int i=0;i<vel;i++)
                {
                    delete[] c[i];
                }
                delete[] c; c=c2; c2=nullptr;
                return vel+1;
            }
            catch(...)
            {
                for(int i=0;i<broj;i++)
                {
                    delete[] c2[i];
                }
                delete[] c2; c2=nullptr; throw;
            }
        }
        catch(std::bad_alloc)
        {
            throw;
        }
    }
    return vel;
}

void IzlistajOptuzbu(char** c, int vel)
{
    for(int i=0;i<vel;i++)
    {
        if(c[i]==nullptr) continue;
        else
        {
            for(int j=0;j<std::strlen(c[i]);j++) std::cout<<c[i][j];
            std::cout<<std::endl;
        }
    }
}

int main ()
{
    
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	int vel;
	std::cin>>vel;
	std::cin.ignore(10000,'\n');
	std::vector<std::string> krivci;
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
	for(int i=0;i<vel;i++)
	{
	    std::string ime;
	    std::getline(std::cin,ime);
	    krivci.push_back(ime);
	}
	char **niz;
	int n=PotencijalniKrivci(niz,krivci);
	char o;
	try {
	do {
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
	std::cin>>o;
	if(o=='1')
	{
	    std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
	    std:: string ime;
	    std::cin.ignore(10000,'\n');
	    std::getline(std::cin, ime);
	    n=DodajOptuzbu(niz,n,ime);
	}
	if(o=='2')
	{
	    std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
	    std::string ime;
	    std::cin.ignore(10000,'\n');
	    std::getline(std::cin, ime);
	    n=OdbaciOptuzbu(niz,n,ime);
	}
	if(o=='3')
	{
	    IzlistajOptuzbu(niz,n);
	}
	} while(o!='0');
    }
    catch(std::domain_error e)
    {
        std::cout<<e.what()<<std::endl;
    }
	for(int i=0;i<n;i++)
	{
	    delete[] niz[i];
	}
	delete[] niz;
	return 0;
}