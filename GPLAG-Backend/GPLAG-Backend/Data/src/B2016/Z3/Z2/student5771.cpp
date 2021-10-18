/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include<map>
#include<string>
#include<vector>
#include<stdexcept>
#include<iterator>
#include<set>
#include<algorithm>
#include <iomanip>
#include<cmath>
#include<utility>
using namespace std;
string PretvoriUMala(string rijec){
    string malaslova;
    for(int i=0; i<rijec.size(); i++){
        if(rijec[i]>='A' && rijec[i]<='Z')malaslova.push_back(rijec[i]+32);
        else malaslova.push_back(rijec[i]);
    }
    return malaslova;
}
bool ProvjeriJelPrijeBila(const map<string, set<int>> &mapa, string rijec){
    string malaslova=PretvoriUMala(rijec);
    if(!mapa.count(malaslova))return false;
    else return true;
}
bool ProvjeriJelDioRijeci(char znak){
    if((znak>='A' && znak<='Z') || (znak>='a' && znak<='z') || znak=='1' || znak=='2' || znak=='3' 
        || znak=='4' || znak=='5' || znak=='6' || znak=='7' || znak=='8' || znak=='9' || znak=='0')return true;
        else return false;
}
map<string, set<int>>KreirajIndeksPojmova(string recenica){
    map<string, set<int>>mapa;
    for(int i=0; i<recenica.size(); i++){
        if(i==0 && ProvjeriJelDioRijeci(recenica[i])==true){ 
            string rijec;
        set<int> pocetni; pocetni.insert(i);
        while(i<recenica.size() && ProvjeriJelDioRijeci(recenica[i])==true){
            rijec.push_back(recenica[i]);
            i++;
        }
           string ubacije=PretvoriUMala(rijec);
            mapa.insert(make_pair(ubacije, pocetni));
        }
        if(i!=0 && i<(recenica.size()) && ProvjeriJelDioRijeci(recenica[i])==true){
            string rijec;
        set<int> pocetni; pocetni.insert(i);
        int pocetak=i;
        while(i<recenica.size() && ProvjeriJelDioRijeci(recenica[i])==true){
            rijec.push_back(recenica[i]);
            i++;
        }
           if(ProvjeriJelPrijeBila(mapa, rijec)==false) {
               string ubacije=PretvoriUMala(rijec);
               mapa.insert(make_pair(ubacije, pocetni));}
           else {
               string ubacije=PretvoriUMala(rijec);
               auto it(mapa.find(ubacije)); (it->second).insert(pocetak);
           }
        }
        
    }
    return mapa;
}
set<int> PretraziIndeksPojmova(string rijec,const  map<string, set<int>> &mapa){
    set<int> skup;
    if(!mapa.count(rijec))throw logic_error("Unesena rijec nije nadjena! ");
    else{
        auto it(mapa.find(rijec));
        skup=(*it).second;
    }
    return skup;
}
void IspisiIndeksPojmova(const map<string, set<int>> &mapa){
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        cout<<it->first<<": ";
       for(auto it2=((*it).second).begin(); it2!=((*it).second).end(); it2++){
           if((++it2)!=((*it).second).end())cout<<*--it2<<",";
           else cout<<*--it2;
       }
       cout<<endl;
    }
}
int main ()
{
    cout<<"Unesite tekst: ";
    string recenica;
    getline(cin,recenica);
    map<string, set<int>> mapa=KreirajIndeksPojmova(recenica);
    IspisiIndeksPojmova(mapa);
    string rijec;
     while(rijec!="."){
            cout<<"Unesite rijec: ";
            getline(cin,rijec);
            if(rijec!="."){
                try{
            set<int> skup=PretraziIndeksPojmova(rijec,mapa);
            for(int x : skup)cout<<x<<" ";
            }
            catch(logic_error izuzetak){cout<<izuzetak.what()<<endl;} cout<<endl;
            }
        }
	return 0;
}