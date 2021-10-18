/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>

struct Djete{
    std::string ime;
    Djete *sljedeci;
};

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
    
    std::vector<std::set<std::string>> imena;
    imena.resize(broj_timova);
    
    Djete *pocetno(nullptr), *prethodno;
    for(int i=0;i<v.size();i++){
        Djete *novi(new Djete);
        novi->ime=v[i];
        novi->sljedeci=nullptr;
        if(!pocetno) pocetno=novi;
        else prethodno->sljedeci=novi;
        prethodno=novi;
    }
    
    Djete *prvo(pocetno->sljedeci);
    
    int velicina(Broj_Slova(pocetno->ime));
    
    imena[0].insert(pocetno->ime);
    //delete pocetno->sljedeci;
    delete pocetno;
    prethodno->sljedeci=prvo;
    
    std::vector<int> vel_timova;
    vel_timova.resize(broj_timova);
    for(int i=0;i<broj_timova;i++){
        if(i<v.size()%broj_timova){
            vel_timova[i]=v.size()/broj_timova+1;
            if((double(v.size()/broj_timova)-v.size()/broj_timova)>0.5)vel_timova[i]++;
        }
        else{
            vel_timova[i]=v.size()/broj_timova;
            if((double(v.size()/broj_timova)-v.size()/broj_timova)>0.5)vel_timova[i]++;
        }
        
    }
   
   int index(0);
   velicina--;
   auto poslije(prvo->sljedeci);
   for(int i=0;i<v.size()-1;i++){
        for(int j=0;j<velicina-1;j++){
           prvo=poslije;
           poslije=prvo->sljedeci;
        }
        if(imena[index].size()>=vel_timova[index]) index++;
        velicina=Broj_Slova(poslije->ime);
        imena[index].insert(poslije->ime);
        prvo->sljedeci=poslije->sljedeci;
        poslije->sljedeci=nullptr;
        delete poslije;
        if(i!=v.size()-2)poslije=prvo->sljedeci;
       // else delete prvo;
       
   }
   
    
    return imena;
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