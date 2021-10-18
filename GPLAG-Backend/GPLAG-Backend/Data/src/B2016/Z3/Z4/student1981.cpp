/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::list;
using std::vector;
using std::set;
using std::make_pair;


int Velicina(string s, int vel) {
    int broj(0);
    
    for(int i=0; i<s.size(); i++) {
       
        if(isalpha(s[i]) || (s[i]>='0' && s[i]<='9')) broj++;
       
    }
    
    return broj;
}



vector<set <string> > Razvrstavanje (vector<string> v, int broj) {
    if(broj<1 || broj>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    list <string> lista;
    auto it(lista.begin());
    
    
    for(int i=0; i<v.size(); i++) {
        lista.push_back(v[i]);
        it++;
        
    }
   double tim(v.size()/broj);
   vector<set <string> > skupovi(broj);
   
   
    int ostatak(v.size()%broj);
    tim=int(tim);
    
    int a(broj-ostatak),vel=0;
    auto it1(lista.begin());
   
   
    for(int i=0; i<ostatak; i++) {
        
        for(int k=0; k<tim+1; k++) {
            skupovi[i].insert(*it1);
            vel=Velicina(*it1,(*it1).size());

            it1=lista.erase(it1);
            
            
            while(vel!=1) {
                if(it1==lista.end()) it1=lista.begin();
                it1++;
                
                vel--;
                
            }
            
           if(it1==lista.end()) it1=lista.begin();
            
        }
    }
   
    for(int i=ostatak; i<ostatak+a; i++) {
        for(int k=0; k<tim; k++) {
            
            skupovi[i].insert(*it1);
            vel=Velicina(*it1,(*it1).size());
            it1=lista.erase(it1);
          
            if(it1==lista.end()) it1=lista.begin();
            
            while(vel!=1 ) {
                if(it1==lista.end()) it1=lista.begin();
                it1++;
                vel--;
                
            }
            
            if(it1==lista.end()) it1=lista.begin();
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

