/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <list>

int Broj_Slova(std::string s){
    int brojac(0);
    for(int i=0;i<s.size();i++){
        if((s[i]<'A'&& s[i]>'9') || (s[i]>'Z'&&s[i]<'a') || s[i]>'z' || s[i]<'0') continue;
        brojac++;
    }
    return brojac;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int broj_timova){
    if(broj_timova<1 || broj_timova>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> imena;
    for(int i=0;i<v.size();i++) imena.push_back(v[i]);
    std::vector<std::set<std::string>> razvrstani;
    razvrstani.resize(broj_timova);
    
    auto it(imena.begin());
    razvrstani[0].insert(*it);
    int brojac_velicine(Broj_Slova(*it));
    it=imena.erase(it);
    
    std::vector<int> vel_timova;
    vel_timova.resize(broj_timova);
    for(int i=0;i<broj_timova;i++){
        if(i<v.size()%broj_timova){
            vel_timova[i]=v.size()/broj_timova+1;
            if((double(v.size()/broj_timova)-v.size()/broj_timova)>=0.5) vel_timova[i]++;
        }
        else{ 
            vel_timova[i]=int(v.size()/broj_timova);
            if((double(v.size()/broj_timova)-v.size()/broj_timova)>=0.5) vel_timova[i]++;
        }
    }
    int index_timova(0);
    
    while(imena.size()!=0){
        brojac_velicine--;
        if(it==imena.end()) it=imena.begin();
        for(int i=0;i<brojac_velicine;i++){
            it++;
            if(it==imena.end()) it=imena.begin(); //nezz valja li
        }
        if(razvrstani[index_timova].size()>=vel_timova[index_timova]) index_timova++; //nezz valja li
        razvrstani[index_timova].insert(*it);
        brojac_velicine=Broj_Slova(*it);
        it=imena.erase(it);
    }
    
    
    return razvrstani;
}

int main (){
    std::cout<< "Unesite broj djece: ";
    int n; std::cin>>n;
    std::vector<std::string> v;
    v.resize(n);
    std::cout << "Unesite imena djece: " << std::endl;
    std::cin.ignore(1000,'\n');
    for(int i=0;i<n;i++)  std::getline(std::cin,v[i]);
    std::cout << "Unesite broj timova: ";
    int broj; std::cin >> broj;
    std::vector<std::set<std::string>> skupovi;
    try{
    skupovi=Razvrstavanje(v,broj);
    }catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
    
    for(int i=0;i<skupovi.size();i++){
        std::cout << "Tim " <<i+1<<": ";
        int brojac(0);
        for(auto x:skupovi[i]){ 
            if(brojac!=skupovi[i].size()-1) std::cout << x << ", ";
            else std::cout << x << " ";
            brojac++;
        }
        std::cout<<std::endl;
    }
	return 0;
}