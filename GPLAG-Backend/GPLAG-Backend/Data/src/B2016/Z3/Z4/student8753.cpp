/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include<vector>
#include<set>
#include<string>
#include<stdexcept>
#include<list>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int brojSkupova)
{
    std::vector<std::set<std::string>> rezultat;
    std::list<std::string> listaDjece;
    if(brojSkupova<1 || brojSkupova>djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int cijeliDio=djeca.size()/brojSkupova;
    int ostatak=djeca.size()%brojSkupova;
    int brojDjece=djeca.size();
    for(int i=0; i<djeca.size(); i++)
    {
        listaDjece.push_back(djeca[i]);

    }
    //nakon što su sva djeca dodana u listu, počinje razvrstavanje
    //prvi koji ide u tim 1 je prvi iz liste
    auto trenutni=listaDjece.begin();
    int brojacDjeceUSkupu=0;
    std::set<std::string> skup;
    for(int i=0;i<brojDjece;i++)
    {
        int brojac=-1;
        for(int j=0;j<(*trenutni).length();j++)
        if((*trenutni)[j]!=' ' && (*trenutni)[j]!='-' && (*trenutni)[j]!='_') brojac++;
        //dodajemo trenutni u skup;
        skup.insert(*trenutni);
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
        
        trenutni=listaDjece.erase(trenutni);
        if(i==(brojDjece-1)) break;
        if(trenutni==listaDjece.end()) trenutni=listaDjece.begin();
        //pošto je trenutni iterator onda ga trebamo dereferencirati
       
        //sad idi kroz listu dok brojac ne bude 0;
        while(brojac!=0)
        {
            trenutni++;
            if(trenutni==listaDjece.end()) trenutni=listaDjece.begin();
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