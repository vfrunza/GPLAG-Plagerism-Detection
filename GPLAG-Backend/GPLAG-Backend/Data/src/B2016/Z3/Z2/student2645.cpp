#include <iostream>
#include <map>
#include <set>
#include <string>
#include <stdexcept>
using namespace std;
void SmanjiSlova(string &recenica){
    for (int i = 0; i < recenica.size(); i++) {
        if (recenica[i]>64&&recenica[i]<91) {
            recenica[i]+=32;
        }
    }
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int> > mapi1){
    for(auto it = mapi1.begin(); it != mapi1.end(); it++){
 std::cout << it->first << ":"<<" ";
 int i(0);
 for(auto x : it->second) {std::cout << x; i++;
 if(i!=(it->second.size())){
     std::cout << ",";}}
std::cout  << std::endl;
}}
std::set<int>  PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>  > mapi1){
   auto it(mapi1.find(rijec));
   if (it==mapi1.end()) throw logic_error("Unesena rijec nije nadjena!");
   else return mapi1[rijec];
}
std::map<std::string, std::set<int> > KreirajIndeksPojmova (std::string recenica){
    int pocetak(0),kraj(0),i(0);
    string novarecenica;
        std::map<std::string, std::set<int> > mapa1;
    while (recenica[i]!='\0') {
        while (recenica[i]<48||(recenica[i]>58&&recenica[i]<65)||(recenica[i]>90&&recenica[i]<97)||recenica[i]>122) {
            pocetak++;
            i++;
        }
        while (((recenica[i]>47&&recenica[i]<58)||(recenica[i]>64&&recenica[i]<91)||(recenica[i]>96&&recenica[i]<123))&&i!=recenica.size()) {
            kraj++;
            i++;
        }
        novarecenica=recenica.substr(pocetak,kraj);
        pocetak=i;
        
        mapa1.insert(pair<string,std::set<int> >(novarecenica,{}));
        mapa1[novarecenica].insert(pocetak-kraj);
        kraj=0;
    }
    return mapa1;
}
int main(){
     std::map<std::string, std::set<int> > map1;
     std::set<int>  map2;
     string s="abc qwe stsda abc abc dhi qwe hrkw dhi";
     std::cout << "Unesite tekst: " ;
     getline(cin,s);
     SmanjiSlova(s);
     map1=KreirajIndeksPojmova(s);
     IspisiIndeksPojmova(map1);
     string c="qwe";
     std::cout << " " << std::endl;
     do{
     std::cout << "Unesite rijec: " ;
     getline(cin,c);
     if(c[0]=='.') break;
     try{ map2=PretraziIndeksPojmova(c,map1);
     int i(0);
     for(auto x : map2) {std::cout << x << " ";i++;
     if (i==map2.size())std::cout << std::endl; }
     }catch (logic_error izuzetak){
         std::cout << izuzetak.what() << std::endl;
     }
     }while(c[0]!='.');
    return 0;
}