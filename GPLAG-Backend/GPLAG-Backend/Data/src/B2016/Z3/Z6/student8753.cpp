/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include<vector>
#include<set>
#include<string>
#include<stdexcept>
#include<list>
#include<memory>

struct Dijete
{
    std::string imeDjeteta;
    std::shared_ptr<Dijete> sljedeci;
};


std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int brojSkupova)
{
    std::vector<std::set<std::string>> rezultat;
    if(brojSkupova<1 || brojSkupova>djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int cijeliDio=djeca.size()/brojSkupova;
    int ostatak=djeca.size()%brojSkupova;
    int brojDjece=djeca.size();
    std::shared_ptr<Dijete> pocetak;
    std::shared_ptr<Dijete> prosli;
    for(int i=0; i<brojDjece; i++)
    {
        std::shared_ptr<Dijete> novoDijete(new Dijete());
        novoDijete->imeDjeteta=djeca[i];
        if(i==(brojDjece-1))
        {
            novoDijete->sljedeci=pocetak;
            prosli->sljedeci=novoDijete;
        }
        else if(i==0)
        {
            pocetak=novoDijete;
        }
        else
        {
            prosli->sljedeci=novoDijete;
        }
        prosli=novoDijete;
    }
    //nakon što su sva djeca dodana u listu, počinje razvrstavanje
    //prvi koji ide u tim 1 je prvi iz liste
    std::shared_ptr<Dijete> trenutni=pocetak;
    int brojacDjeceUSkupu=0;
    std::set<std::string> skup;
    for(int i=0;i<brojDjece;i++)
    {
        int brojac=-1;
        for(int j=0;j<(trenutni->imeDjeteta).length();j++)
        if((trenutni->imeDjeteta)[j]!=' ' && (trenutni->imeDjeteta)[j]!='-' && (trenutni->imeDjeteta)[j]!='_') brojac++;
        //dodajemo trenutni u skup;
        skup.insert(trenutni->imeDjeteta);
        brojacDjeceUSkupu++;
        int potrebanBrojDjece=cijeliDio;
        if(ostatak>0) potrebanBrojDjece+=1;
        //ako je skup popunjen
        if(brojacDjeceUSkupu==potrebanBrojDjece)
        {
            rezultat.push_back(skup);
            ostatak--;
            skup.clear();
            brojacDjeceUSkupu=0;
        }
        
        //ovo možda ne radi za zadnji element
        if(i==brojDjece-1)
        {
            prosli->sljedeci=nullptr;
            prosli=nullptr;
            trenutni=nullptr;
            break;
        }
        prosli->sljedeci=trenutni->sljedeci;
        trenutni=prosli->sljedeci;
       
        //sad idi kroz listu dok brojac ne bude 0;
        while(brojac!=0)
        {
           trenutni=trenutni->sljedeci;
           prosli=prosli->sljedeci;
            brojac--;
        }
        //sad smo došli do novog trenutnog
    }
    return rezultat;
}
int main ()
{
    std::cout<<"Unesite broj djece: ";
    int brojDjece;
    std::cin>>brojDjece;
    std::cin.clear();
    std::cin.ignore(256,'\n');
    std::vector<std::string> vektorDjece;
    std::cout<<"Unesite imena djece: ";
    for(int i=0;i<brojDjece;i++)
    {
        std::string ime;
        getline(std::cin,ime);
        vektorDjece.push_back(ime);
        
    }
    int brojTimova;
    std::cout<<std::endl<<"Unesite broj timova: ";
    std::cin>>brojTimova;
    std::vector<std::set<std::string>> x;
    try {
        x=Razvrstavanje(vektorDjece,brojTimova);
    }
    catch (std::logic_error err) {
        std::cout <<"Izuzetak: "<< err.what() << std::endl;
    }
    
    for(int i=0;i<x.size();i++)
    {
        //sad imamo skupove
         auto it=begin(x[i]);
         int brojac=0;
        while(it!=end(x[i]))
        {
            brojac++;
            it++;
        }
        it=begin(x[i]);
        std::cout<<"Tim "<<i+1<<": ";
         for(int i=0; i<brojac; i++)
        {
            if(i<(brojac-1)) std::cout<<*it++<<", ";
            else std::cout<<*it;
        }
        std::cout<<std::endl;
    }
	return 0;
}