#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <deque>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <list>
#include <set>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
int broj_slova(string s){
    int i{},brojac{};
    while(i<s.size()){
        if((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
            brojac++;
        i++;
    }
    return brojac;
}
vector<std::set<string>> Razvrstavanje(std::vector<string> V, int k){
    std::list<string> L;
    if(k<1 || k>V.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int  n(V.size());
    for(int i=0; i<V.size(); i++)
        L.push_back(V[i]);
    int broj_clanova,brojac{};
    broj_clanova=n/k;
    int broj_dodatnih;
    broj_dodatnih=n%k;
    vector<int> M(k);
    for(int i=0; i<k; i++){
        if(i<broj_dodatnih)
            M[i]=(broj_clanova+1);
        else M[i]=(broj_clanova);
    }
    vector<std::set<string>> T(k);
    auto it=L.begin();
    int i=0;
    T[0].insert(*it);
    string s;
    bool brisao=false;
    auto kt=L.begin();
    while(L.size()!=0 && i<M.size()){
        if(T[i].size()==M[i])
            i++;
        it=kt;
        brojac=broj_slova(*it);
        while(brojac!=0 && kt!=L.end()){
            kt++;
            brojac--;
            if(kt==L.end()){
                if(it!=L.end() && !brisao){
                    it=L.erase(it);
                    brisao=true;
                }
                kt=L.begin();
            }
        }
        if(!brisao){
            if(it!=L.end()) {
            it=L.erase(it);
            }
        }
                    brisao=false;

            if(kt!=L.end())
        T[i].insert(*kt);
        if(T[i].size()==M[i])
            i++;
        
        
    }
    
    return T;
    
}

int main (){
    int n=1,k;
    vector<string> V;
    cout<<"Unesite broj djece: ";
    cin>>n;
    V.resize(n);
    cin.ignore(1000,'\n');
    cout<<"Unesite imena djece: ";
    for(int i=0; i<n; i++)
        	std::getline(std::cin, V[i]);
    cout<<endl<<"Unesite broj timova: ";
    cin>>k;
    try{
        vector<std::set<string>> K;
        K=Razvrstavanje(V,k);
        for(int i=0; i<K.size(); i++){
            cout<<"Tim "<<i+1<<": ";
             auto ita=K[i].begin();
        while(ita!=K[i].end()) {
            ita++;
            if(ita==K[i].end()) {
                ita--;
                cout<<*ita;
                break;
            } else {
                ita--;
                std::cout <<*ita<<", ";
            }
            ita++;

        }
            cout<<endl;
        }
    }
    catch(std::logic_error e){
        cout<<"Izuzetak: "<<e.what()<<endl;        
    }


	return 0;
}