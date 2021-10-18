/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include<new>
#include <set>
#include <stdexcept>
#include<memory>
using std::set;
using std::cin; 
using std::cout;
using std::endl;
using std::string; 
using std::vector;
using std::shared_ptr;
struct Dijete{
    string ime;
    shared_ptr<Dijete> sljedeci;
};
int Mjesta(string s){
    int br(0);
    for(int i=0; i<s.size(); i++)
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) br++;
    return br-1;
}
shared_ptr<Dijete> KreirajKruznuListu(vector<string>v){
    shared_ptr<Dijete> pocetak(nullptr), prethodni;
    for(int i=0; i<v.size(); i++){
        shared_ptr<Dijete> novi=std::make_shared<Dijete>();
        novi->ime=v[i]; novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
        if(i==v.size()-1) prethodni->sljedeci=pocetak;
    }
    return pocetak;
}
vector<set<string>> Razvrstavanje(vector<string>v, int brtim){
    if(brtim<1 || brtim>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    shared_ptr<Dijete> lista(nullptr);
 //   try{
    lista=KreirajKruznuListu(v);
/*    } catch(...){
        UnistiListu(lista);
        throw;
    }*/
    int vecitimovi(v.size()%brtim), brelem(v.size()/brtim);
    vector<int>brel(brtim);
    for(int i=0; i<brtim; i++)
        if(i<vecitimovi) brel[i]=brelem+1;
        else brel[i]=brelem;
    vector<set<string>>timovi(brtim);
    auto pocit(lista);
    int pocetak(0), pomjeranje, prepravka=0, pocetakzaprethodni(1);
    auto zabrisanje(lista), prethodni(lista);
    for(int i=0; i<brtim; i++){
        for(auto it=pocit; ; it=it->sljedeci){
            if(!pocetak) pomjeranje=0, pocetak=1;
                else{
                   if(prepravka) prepravka=0, it=lista;
                   pomjeranje=Mjesta(it->ime);
                  zabrisanje=it;
                  if(pocetakzaprethodni){
                      int j(0),br(0);
                      for(int k=0; k<i; k++) br+=timovi[i].size();
                      for(auto pom=pocit; ; pom=pom->sljedeci){
                          prethodni=pom;
                          j++;
                          if(j==v.size()-br) break;
                      }
                      prethodni->sljedeci=it->sljedeci; 
                      it=it->sljedeci;
                      pocetakzaprethodni=0;
                      
                  }
                  else{
                      prethodni->sljedeci=it->sljedeci;
                      it=it->sljedeci;
                  }
                  zabrisanje=nullptr;
                }
                for(int i=0; i<pomjeranje; i++){
                  //  if(it==lista.end()) it=lista.begin();
                    it=it->sljedeci;
                    if(i==pomjeranje-2) prethodni=it;
                  //  if(it==lista.end()) it=lista.begin();
                }
                timovi[i].insert(it->ime);
                if(timovi[i].size()==brel[i]){ if(i==brtim-1){it->sljedeci=nullptr; it=nullptr;} pocit=it; break;}
                if(it!=lista) it=prethodni;
                else prepravka=1;
            }
        }
    return timovi;
}

int main (){
    int n;
    cout<<"Unesite broj djece: ";
    cin>>n;
    std::cin.ignore(100000,'\n');
    vector<string>v(n);
    cout<<"Unesite imena djece: ";
    for(int i=0; i<n; i++)
        std::getline(cin, v[i]);
    int brtimova;
    cout<<"\nUnesite broj timova: ";
    cin>>brtimova;
    try{
    vector<set<string>>timovi(Razvrstavanje(v, brtimova));
    for(int i=0; i<timovi.size(); i++){
        cout<<"Tim "<<i+1<<": ";
        int j(0);
         for(auto it=timovi[i].begin(); it!=timovi[i].end(); it++){
           if(j!=timovi[i].size()-1) cout<<*it<<", ";
           else cout<<*it;
           j++;
       }
        cout<<endl;
    }
    }
    catch(std::logic_error izuzetak){ cout<<"Izuzetak: "<<izuzetak.what()<<endl;}
 //   catch(...){ return 0;}
	return 0;
}