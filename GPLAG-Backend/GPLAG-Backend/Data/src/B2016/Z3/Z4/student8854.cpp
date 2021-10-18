/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>
#include <set>
#include <iterator>
int NadjiVelicinu(std::string dijete)
{
    int broj=0;
    for(int i=0;i<dijete.size();i++)
    {
        if((dijete[i]<='z' && dijete[i]>='a') || (dijete[i]<='Z' && dijete[i]>='A') || (dijete[i]>='0' && dijete[i]<='9'))
        broj++;
    }
    return broj;
}


std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca,int brojtimova)
{
    if(brojtimova<1 || brojtimova>djeca.size())
    throw std::logic_error("Razvrstavanje nemoguce");

    std::list<std::string>lista;
    

    for(int i=0;i<djeca.size();i++)
    {
        lista.push_back(djeca[i]);
    }
    
    
    std::vector<std::set<std::string>> izlaz;
    izlaz.resize(brojtimova);
    
    int trenutni_skup=0;
    std::list<std::string>::iterator trenutno_dijete=lista.begin();
    int broj_predjenih=0;
    
    for(int broj_predjenih=0;broj_predjenih<djeca.size();broj_predjenih++)
    {
        if(izlaz[trenutni_skup].size()==djeca.size()/brojtimova + (trenutni_skup<djeca.size()%brojtimova))
        trenutni_skup++;
        
        
        if(lista.size())
        izlaz[trenutni_skup].insert(*trenutno_dijete);
        int vel=NadjiVelicinu(*trenutno_dijete);
        trenutno_dijete=lista.erase(trenutno_dijete);
        trenutno_dijete--;
        for(int i=0;i<vel;i++)
        {
            trenutno_dijete++;
            if(trenutno_dijete==lista.end())
            trenutno_dijete=lista.begin();
        }
        
        
        
        
        
    }
    
    return izlaz;
    
}

int main ()
{
	std::cout<<"Unesite broj djece: ";
	int broj;
	std::cin>>broj;
	std::cin.ignore(10000,'\n');
	std::cout<<"Unesite imena djece: "<<std::endl;
	std::vector<std::string>djeca(broj);
	for(int i=0;i<broj;i++)
	std::getline(std::cin,djeca[i]);
	
	std::cout<<"Unesite broj timova: ";
	int brojtimova;
	std::cin>>brojtimova;
	std::vector<std::set<std::string>> izlaz;
	try
	{
	izlaz=Razvrstavanje(djeca,brojtimova);
	}
	catch(std::logic_error e)
	{
	    std::cout<<"Izuzetak: "<<e.what()<<std::endl;
	    return 0;
	}
	
	for(int i=0;i<brojtimova;i++)
	{
	    std::cout<<"Tim "<<i+1<<": ";
	    std::cout<<*(izlaz[i].begin());
	    auto it=izlaz[i].begin();
	    for(;;)
	    {
	        it++;
	        if(it!=izlaz[i].end())
	        std::cout<<", "<<*it;
	        else
	        break;
	    }
	    std::cout<<std::endl;
	}
	
	
	
	return 0;
}