/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include<list>
#include <set>
#include <stdexcept>
using std::set;
using std::cin;  
using std::cout;
using std::endl;
using std::string; 
using std::list;
using std::vector;
int Mjesta(string s){
    int br(0);
    for(int i=0; i<s.size(); i++)
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) br++;
    return br-1;
}
vector<set<string>> Razvrstavanje(vector<string>v, int brtim){
    if(brtim<1 || brtim>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    list<string>lista;
    for(int i=0; i<v.size(); i++)
        lista.push_back(v[i]);
    int vecitimovi(v.size()%brtim), brelem(v.size()/brtim);
    vector<int>brel(brtim);
    for(int i=0; i<brtim; i++)
        if(i<vecitimovi) brel[i]=brelem+1;
        else brel[i]=brelem;
    vector<set<string>>timovi(brtim);
    auto pocit(lista.begin());
    int pocetak(0), pomjeranje, prepravka=0;
    for(int i=0; i<brtim; i++){
        for(auto it=pocit; ; it++){
            if(!pocetak) pomjeranje=0, pocetak=1;
                else{
                    if(prepravka) prepravka=0, it=lista.begin();
                   pomjeranje=Mjesta(*it);
                   auto pomit=++it;
                   if(pomit==lista.end()){it--; lista.erase(it); it=lista.begin();}
                   else{it--; it=lista.erase(it);} 
                }
                for(int i=0; i<pomjeranje; i++){
                    if(it==lista.end()) it=lista.begin();
                    it++;
                    if(it==lista.end()) it=lista.begin();
                }
                timovi[i].insert(*it);
                if(timovi[i].size()==brel[i]){ pocit=it; break;}
                if(it!=lista.begin()) it--;
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
        int j=0;
       for(auto it=timovi[i].begin(); it!=timovi[i].end(); it++){
           if(j!=timovi[i].size()-1) cout<<*it<<", ";
           else cout<<*it;
           j++;
       }
       
        cout<<endl;
    }
    }
    catch(std::logic_error izuzetak){ cout<<"Izuzetak: "<<izuzetak.what()<<endl;}
	return 0;
}