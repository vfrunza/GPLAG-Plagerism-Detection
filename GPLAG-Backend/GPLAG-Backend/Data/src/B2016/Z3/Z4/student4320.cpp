/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <stdexcept>
#include <list>
#include <string>
#include <set>
#include <vector>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int n)
{
    std::list<std::string> lista;
    for(int i=0; i<v.size(); i++)
        lista.push_back(v[i]);
    std::vector<std::set<std::string>> rez;
    rez.resize(n); int prvi=0;
    int x=lista.size()%n;
    int y=lista.size()/n;
    for(int i=0; i<n; i++) {
        int br=0;  
        if(i<x) {
            while(br<(y+1)) { int z=0;
                    for(auto it=lista.begin(); it!=lista.end(); it++) {
                if(prvi==0) { rez[i].insert(*it); prvi++; int k=0; 
                while (k<it->size()) { if(it==lista.end()) it=lista.begin(); it++; k++; }   it=lista.erase(it); 
                if(it==lista.end()) it=lista.begin();  continue; }
                int broj=0; 
                int x1=it->size();
                while(broj<x1) {
                    if(it==lista.end()) it=lista.begin(); 
                    it++; broj++; }
                    if(it==lista.end()) it=lista.begin();
            rez[i].insert(*it);
            int x2=it->size(); it=lista.erase(it); if(it==lista.end()) it=lista.begin();
                while(z<x2) { if(it==lista.end()) it=lista.begin(); it++; z++; }
            
            } br++; } } 
        else if(i>x) {
            while(br<y) { int z=0;
                for(auto it=lista.begin(); it!=lista.end(); it++) {
            rez[i].insert(*it); int r=it->size();
            it=lista.erase(it); if(it==lista.end()) it=lista.begin(); while(z<r) { if(it==lista.end()) it=lista.begin(); it++; z++; }
            } br++; }
        }
    }
    return rez; }
    
    
    /*
    int x=lista.size()%n;
    if(x==0) { int n1=0; while(n1<lista.size()/n)  { rez[n1].insert(" "); n1++; } }
    else {
    for(int i=0; i<n; i++) {
        if(i<x)
            //rez[i].resize(lista.size()/x+1);
        {
            int n1=0;
            while(n1<lista.size()/n+1) {
                rez[i].insert(" ");
                n1++;
            }
        } else { // rez[i].resize(lista.size()/x);
            int n1=0;
            while(n1<lista.size()/n) {
                rez[i].insert(" ");
                n1++;
            }
        } }
    }
    int br(0);
    int br2(0);
  //  int k=0; while(k<rez.size()) {
  for(int hb=0; hb<n; hb++)
    for(int i=0; i<rez[hb].size(); i++) {
        rez[hb].clear();
        for(auto it=lista.begin(); it!=lista.end(); it++) {
            br2=0;
            //    int ostatak;
            if(br==0) {
                rez[0].insert(*it);
                br++;
                int z=0; while(z<it->size() && it!=lista.end()) { if(it==lista.end()) it=lista.begin(); it++; z++; }
                it=lista.erase(it);
                it=lista.begin();
                continue;
            }
            if(lista.size()==1) { rez[hb].insert(*it); lista.clear(); break; }
            // for(int i=0; i<n; i++) {
            int j=0;
            while(j<(*it).size() && it!=lista.end()) {
                j++;
                it++; if(it==lista.end()) it=lista.begin();
                br2++;
            }
            if(j==(*it).size() && it!=lista.end()) {
                rez[hb].insert(*it);
                it=lista.erase(it);
                it=lista.begin();
                continue;
            } else {
                int koraci=0;
                it=lista.begin();
                for(;;) {
                    it=lista.begin();
                    int x=(*it).size()-br2;
                    while(it!=lista.end() && koraci<x ) {
                        it++;
                        koraci++;
                    }
                    if(koraci==x && it!=lista.end()) {
                        rez[hb].insert(*it);
                        it=lista.erase(it);
                        it=lista.begin();
                        break;
                    }
                }
            }
        }
    }
    
// k++; }
return rez; }

*/


int main ()
{
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite imena djece: ";
    std::vector<std::string> v;
    v.resize(n);
    for(int i=0; i<n; i++) std::cin>>v[i];
    std::cout<<"Unesite broj timova: ";
    int timovi;
    std::cin>>timovi;
    std::vector<std::set<std::string>> rez;
    rez=Razvrstavanje(v, timovi);
    for(int i=0; i<timovi; i++) {
        // for(int j=0; j<v[i].size(); j++) 
        for(std::string x : rez[i]) std::cout<<x<<" ";
        std::cout<<std::endl;
    }

    return 0;
}