#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <new>
#include <set>

struct Dijete{
    std::string ime;
    Dijete *sljedeci;
};

int Duzina(std::string ime){
    int brojac=0;
    for(int i=0;i<ime.size();i++){
        if(ime[i]<'0' || (ime[i]>'9' && ime[i]<'A') || (ime[i]>'Z' && ime[i]<'a')|| ime[i]>'z')brojac++;
    }
    return ime.length()-brojac;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> &djeca,int br_timova){
     if(br_timova<1 || djeca.size()<br_timova) throw std::logic_error ("Razvrstavanje nemoguce");
     try{
       std::vector<std::set<std::string>> v;
       int kol=djeca.size();
       int brojac;
       Dijete *pocetak(nullptr),*prethodni,*radni;
       
         for(int i=0;i<djeca.size();i++){
           Dijete *novi=new Dijete;
           if(i==0){
               novi->ime=djeca[i];
               novi->sljedeci=nullptr;
               prethodni=novi;
               pocetak=novi;
           }
           else if(i==djeca.size()-1){
               novi->ime=djeca[i];
               prethodni->sljedeci=novi;
               novi->sljedeci=pocetak;
           }
           else{
               novi->ime=djeca[i];
               prethodni->sljedeci=novi;
               novi->sljedeci=nullptr;
               prethodni=novi;
           }
           novi=nullptr;
           delete novi;
         }
         radni=pocetak;
         for(int i=0;i<kol%br_timova;i++){
             std::set<std::string>skup;
             for(int j=0;j<(kol/br_timova)+1;j++){
                 brojac=Duzina(radni->ime);
                 skup.insert(radni->ime);
                 Dijete *tmp=radni;
                 while((radni->sljedeci)!= tmp) radni=radni->sljedeci;
                 radni->sljedeci=tmp->sljedeci;
                 if(pocetak==tmp)pocetak=tmp->sljedeci;
                 tmp->sljedeci=nullptr;
                 delete tmp;
                     for(int t=0;t<brojac;t++){
                         radni=radni->sljedeci;
                     }
             }
             v.push_back(skup);
         }
         for(int i=0;i<br_timova-(kol%br_timova);i++){
             std::set<std::string> skup;
             for(int j=0;j<kol/br_timova;j++){
                 brojac=Duzina(radni->ime);
                 skup.insert(radni->ime);
                 Dijete *tmp=radni;
                 while(radni->sljedeci!=tmp){
                      radni=radni->sljedeci;
                 }
                 radni->sljedeci=tmp->sljedeci;
                 tmp->sljedeci=nullptr;
                 delete tmp;
                 if(i==br_timova-(kol%br_timova)-1 && j==kol/br_timova-1){
                     break;
                 }
                 else{
                 for(int t=0;t<brojac;t++){
                     radni=radni->sljedeci;
                 }
                 }
             }
             v.push_back(skup);
         }
       return v;
    }
   catch(...){
       return {};
    }
}
int main (){
    try{
        int n;
        std::vector<std::string> djeca{};
        std::cout << "Unesite broj djece: ";
        std::cin >> n;
        std::cin.clear();
        std::cin.ignore (100,'\n');
        std::cout << "Unesite imena djece: ";
        for(int i=0;i<n;i++){
            std::string s;
            std::getline(std::cin,s);
            while(s=="")std::getline(std::cin,s);
            djeca.push_back(s);
        }
        std::cout  << std::endl;
        int k;
        std::cout << "Unesite broj timova: ";
        std::cin >> k;
        std::vector<std::set<std::string>> v;
        std::set<std::string>ss;
        v=Razvrstavanje(djeca,k);
        int br=0;
        for(int i=0;i<v.size();i++){
            std::cout << "Tim "<<i+1<<": ";
            ss=v[i];
            br=0;
            for(auto x:ss){
                br++;
                if(ss.size()==br){
                    std::cout << x;
                    break;
                }
                std::cout << x <<", ";
            }
           std::cout << std::endl;
        }}
        catch(std::logic_error e){
            std::cout <<"Izuzetak: "<< e.what();
    }
	return 0;
}