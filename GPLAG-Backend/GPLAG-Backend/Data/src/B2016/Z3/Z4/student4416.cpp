/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <stdexcept>
typedef std::vector<std::set<std::string>> Povratni;
int Slova(std::string s){
    auto a(s.begin());
    int brojac(0);
    while (a!=s.end()){
        if((*a>='a' && *a<='z') || (*a>='A' && *a<='Z') || (*a>='0' && *a<='9')) brojac++;
        a++;
    }
    return brojac;
}
Povratni Razvrstavanje(std::vector<std::string> djeca,int k){
    std::list<std::string> lista;
    Povratni izlaz;
    int n(djeca.size());
    if(k<1 || k>n) throw std::logic_error("Razvrstavanje nemoguce");
    for(auto i:djeca) lista.push_back(i);
    auto it(lista.begin());
    int x,i;
    for(i=0;i<n%k;i++){
        std::set<std::string> temp;
        for(int j=0;j<n/k+1;j++){
            x=Slova(*it);
            temp.insert(*it);
            it=lista.erase(it);
            if(it==lista.end()) it=lista.begin();
            for(int k=0;k<x-1;k++){
                it++;
                if(it==lista.end()) it=lista.begin();
            }
        }
        izlaz.push_back(temp);
    }
    for(int a=i;a<k;a++){
        std::set<std::string> temp;
        for(int b=0;b<n/k;b++){
            x=Slova(*it);
            temp.insert(*it);
            it=lista.erase(it);
            if(it==lista.end()) it=lista.begin();
            for(int c=0;c<x-1;c++){
                it++;
                if(it==lista.end())it=lista.begin();
            }
        }
        izlaz.push_back(temp);
    }
    return izlaz;
}
int main (){
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    if(n<0) {std::cout<<"Pogresan parametar"; return 0;}
    std::cout<<"Unesite imena djece: \n";
    std::vector<std::string> djeca(n);
    std::cin.ignore(1000,'\n');
    for(int i=0;i<n;i++) std::getline(std::cin,djeca[i]);
    std::cout<<"Unesite broj timova: ";
    int k;
    std::cin>>k;
    Povratni ispis;
    try{
        ispis=Razvrstavanje(djeca,k);
    } catch(std::logic_error a){
        std::cout<<"Izuzetak: "<<a.what();
        return 0;
    }
    for(int i=0;i<k;i++){
        std::cout<<"Tim "<<i+1<<": ";
        auto temp(ispis[i].begin());
        for(int j=0;j<ispis[i].size()-1;j++) std::cout<<*temp++<<", ";
        std::cout<<*temp<<std::endl;
    }
	return 0;
}