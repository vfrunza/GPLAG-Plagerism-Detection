/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::set;
using std::make_pair;

struct Dijete {
  string ime;
  Dijete *sljedeci;
};


int Velicina(string s, int vel) {
    int broj(0);
    
    for(int i=0; i<s.size(); i++) {
       
        if(isalpha(s[i]) || (s[i]>='0' && s[i]<='9')) broj++;
       
    }
    return broj;
}

void Unisti(Dijete *pocetak) {
    Dijete *p;
    for(p=pocetak; p!=nullptr;) {
        auto pom(p);
        p=p->sljedeci;
        pom->sljedeci=nullptr;
        delete pom;
    }
    delete p;
    return;
}


vector<set<string>> Razvrstavanje(vector<string> v, int broj) {
    if(broj<1 || broj>v.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    
    Dijete *pocetak(nullptr), *prethodni;
    try{
    for (int i=0; i<v.size(); i++) {
        Dijete*novi(new Dijete);
        novi->ime=v[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
        if(i==v.size()-1) prethodni->sljedeci=pocetak;
    }
    }
    catch(...) {
    Unisti(pocetak);
    throw;
    }
    auto pred=prethodni;
    double tim(v.size()/broj);
    vector<set<string>> skupovi(broj);
    int ostatak(v.size()%broj);
    tim=int(tim);
    int a(broj-ostatak),vel(0);
    
    Dijete *p=pocetak; 
        for(int i=0; i<ostatak; i++) {
        
        for(int k=0; k<tim+1; k++) {
            skupovi[i].insert(p->ime);
            
            vel=Velicina(p->ime,(p->ime).size());
            
            pred->sljedeci=p->sljedeci;
            auto save=p;
            p=p->sljedeci;
            delete save;
            
            while(vel!=1) {
                pred=pred->sljedeci;
                p=p->sljedeci;
                
                vel--;
                
            }
            
            
        }
    }

    for(int i=ostatak; i<ostatak+a; i++) {
        for(int k=0; k<tim; k++) {
            skupovi[i].insert(p->ime);
            
            vel=Velicina(p->ime,(p->ime).size());
             
            
            pred->sljedeci=p->sljedeci;
            auto save=p;
            p=p->sljedeci;
            delete save;
            
            while(vel!=1) {
                if(pred==p) break;
                 p=p->sljedeci;
                pred=pred->sljedeci;
               
                vel--;
                
            }
            
        }
    }
    
    return skupovi;
} 



int main ()
{
    try{
    cout<<"Unesite broj djece: ";
    int n;
    cin>>n;
    cout<<"Unesite imena djece: "<<endl;
    std::cin.ignore(1000,'\n');
    vector <string> v;
    
    for(int i=0; i<n; i++) {
        string s;
        std::getline(cin,s);
        v.push_back(s);
    }
    cout<<"Unesite broj timova: ";
    int broj;
    cin>>broj;
    auto h= Razvrstavanje(v,broj);
    for(int i=1; i<broj+1; i++) {
        cout<<"Tim "<<i<<": ";
        int br(0);
        for(string x: h[i-1]) {
           if(h[i-1].size()==broj+1 && br==broj-1) cout<<x<<", ";
           else if(br==h[i-1].size()-1 ) cout<<x<<" ";
           else  cout<<x<<", ";
           br++;
        }
        cout<<endl;
    }
    
    
    }
    catch(std::logic_error i) {
        cout<<"Izuzetak: "<<i.what()<<endl;
    }
    
	return 0;
}

