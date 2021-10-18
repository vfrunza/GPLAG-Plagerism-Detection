/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>

#include <stdexcept>

#include <vector>
#include <set>
#include <iterator>
#include <new>
struct Dijete{
    std::string ime;
    Dijete* sljedeci=nullptr;
};


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

    Dijete* djecica=new Dijete[djeca.size()];
    

    for(int i=0;i<djeca.size();i++)
    {
        if(i==int(djeca.size())-1)
        {
            djecica[i].ime=djeca[i];
            djecica[i].sljedeci=djecica;
            continue;
        }
            djecica[i].sljedeci=djecica+i+1;
            djecica[i].ime=djeca[i];
          
       
        
        
        
    }
    
    
    std::vector<std::set<std::string>> izlaz;
    izlaz.resize(brojtimova);
    
    int trenutni_skup=0;
    Dijete* trenutno_dijete=djecica;
    Dijete* tr_dva=djecica+(djeca.size())-1;
    
    
    for(int broj_predjenih=0;broj_predjenih<djeca.size();broj_predjenih++)
    {
        if(izlaz[trenutni_skup].size()==djeca.size()/brojtimova + (trenutni_skup<djeca.size()%brojtimova))
        trenutni_skup++;
        
        
        if(djeca.size())
        izlaz[trenutni_skup].insert((*djecica).ime);
        int vel=NadjiVelicinu((*trenutno_dijete).ime);
        
        (*tr_dva).sljedeci=trenutno_dijete->sljedeci;
        delete trenutno_dijete;
        
        
        for(int i=0;i<vel;i++)
        {
            trenutno_dijete=trenutno_dijete->sljedeci;
        }
        if(tr_dva!=djecica)
        tr_dva=trenutno_dijete-1;
        else
        tr_dva=djecica+djeca.size()-1;
        
        
        
        
        
        
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