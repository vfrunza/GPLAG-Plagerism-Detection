#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <iterator>
#include <stdexcept>
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string>ime, int tim){
 std::list<std::string>lista;
 std::vector<std::set<std::string>>skup;
 int niz[100]{0};
 int ostatak, rezultat{0}, broj(ime.size()), vel{0}, ind{0}, poz{0};
 ostatak=broj%tim;
 rezultat=broj/tim;
 skup.resize(tim);
 for(int i=0; i<tim; i++){
     if(ostatak>0){
      niz[i]=rezultat+1;
      skup.resize(rezultat+1);
      ostatak--;
     }
     else{
        niz[i]=rezultat;
        skup.resize(rezultat);
     }
 }
 skup.resize(tim);
 for(int i=0; i<ime.size(); i++){
  lista.push_back(ime[i]);
 }
 int broj1{0},brojac2{0};
 std::list<std::string>::iterator it(lista.begin());
 for(;;){
     vel=niz[ind];
     for(std::string x : lista){
      if(x==*it){
        brojac2=0;
        for(int j=0; j<x.size(); j++){
         if((x[j]>='A' && x[j]<='Z') || (x[j]>='a' && x[j]<='z') || (x[j]>='0' && x[j]<='9')) brojac2++;
        }
       } 
      }
    skup[ind].insert(*it);
     poz++; 
     if(poz==vel) {ind++; poz=0;} 
     it=lista.erase(it);
     it--;
     for(int i=0; i<brojac2; i++) {it++; if(it==lista.end()) {it=lista.begin();}}
     broj1++;
     if(broj1==broj)
     break;
 }
 return skup;
}
int main (){
 try{
    int n, tim;
    std::vector<std::string> ime;
    std::string pom;
    std::vector<std::set<std::string>>skup;
    std::cout <<"Unesite broj djece: ";
    std::cin >>n;
    std::cin.ignore(10000, '\n');
    std::cout <<"Unesite imena djece: "<<std::endl;
    for(int i=0; i<n; i++){
        std::getline(std::cin,pom);
        ime.push_back(pom);
    }
    std::cout <<"Unesite broj timova: ";
    std::cin >>tim;
    if(tim<1 || tim>n) throw std::logic_error("Razvrstavanje nemoguce");
    skup=Razvrstavanje(ime,tim);
    int i{0}, j{0};
      for(std::set<std::string> const &abc : skup){
       std::cout <<"Tim "<<i+1<<": ";
       for(const std::string s : abc){
        if(j<abc.size()-1)
        std::cout<<s<<", ";
        else std::cout <<s;
        j++;
       }
       j=0;
       i++;
       if(i>=tim) break;
       std::cout<<std::endl;
      }
 }
 catch(std::logic_error izuzetak){
  std::cout <<"Izuzetak: "<<izuzetak.what()<<std::endl;
 }
	return 0;
}