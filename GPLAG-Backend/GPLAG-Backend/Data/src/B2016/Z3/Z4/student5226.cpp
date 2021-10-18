/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <set>
#include <list>
#include <vector>
#include <iterator>
std::vector<std::set<std::string>> Razvrstaj (std::vector<std::string> imena, int broj_timova){
    std::vector<std::set<std::string>> timovi;
    int i=1;
    std::list<std::string> lista_imena;
    for(int i=0;i<imena.size();i++) lista_imena.push_back(imena[i]);
    std::list<std::string>::iterator it(lista_imena.begin()),kraj(lista_imena.end());
    timovi[1].insert(*it);
    int broj_igraca=1;
    while(it!=lista_imena.end()){
        std::string ime(*it);
        int broj_slova(0);
        while(ime!='\n') broj_slova++;
        std::advance(it,broj_slova);
        
        int modul=imena.size()%broj_timova;
        timovi[i].insert(*it);
        it=lista_imena.erase(*it);
        broj_igraca++;
        if(i>=modul && broj_igraca==(imena.size()/broj_timova)+1) {i=i+1; broj_igraca=0;}
        else if(i<modul && broj_igraca==imena.size()/broj_timova){i=i+1; broj_igraca=0;}
        if(std::distance(kraj,it)==1) it=
        
    }
    return timovi;
}

int main ()
{
    int broj_djece,broj_timova
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj_djece;
    std::vector<std::string> djeca(broj_djece);
    std::cout<<"\nUnesite imena djece: ";
    for(int i=0;i<broj_djece;i++){
        std::getline(std::cin,djeca[i]);
    }
    std::cout<<"Unesite broj timova: ";
    std::cin>>broj_timova;
    std::vector<std::set<std::string>> timovi;
    timovi=Razvrstaj(djeca,broj_djece);
    std::cout<<std::endl;
    for(int i=0;i<timovi.size();i++){
        std::cout<<"Tim "<<i+1<<": ";
        for(auto s:timovi[i]) std::cout<<timovi<<" ";
        
    }
	return 0;
}